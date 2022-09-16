#include "DenseGRAPH.hpp"

DenseGRAPH::DenseGRAPH(int V, bool digraph = false)
    : adj(V), Vcnt{V}, Ecnt{0}, digraph{digraph} {
  for (int i = 0; i < V; i++)
    adj[i].assign(V, false);
}

void DenseGRAPH::insert(Edge e) {
  int v = e.v;
  int w = e.w;

  if (adj[v][w] == false)
    Ecnt++;
  adj[v][w] = true;
  if (!digraph)
    adj[w][v] = true;
}

void DenseGRAPH::remove(Edge e) {
  int v = e.v;
  int w = e.w;

  if (adj[v][w])
    Ecnt--;
  adj[v][w] = false;
  if (!digraph)
    adj[w][v] = false;
}

class DenseGRAPH::adjIterator {
private:
  const DenseGRAPH &G;
  int i;
  int v;

public:
  adjIterator(const DenseGRAPH &G, int v) : G{G}, v{v}, i{-1} {}

  int beg() {
    i = -1;
    return nxt();
  }

  int nxt() {
    for (++i; i < G.V(); ++i)
      if (G.adj[v][i])
        return i;

    return -1;
  }

  bool end() { return i >= G.V(); }
};
