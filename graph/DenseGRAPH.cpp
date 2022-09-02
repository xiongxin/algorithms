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

int DenseGRAPH::adjIterator::nxt() {
  for (++i; i < G.V(); ++i)
    if (G.adj[v][i])
      return i;

  return -1;
}
