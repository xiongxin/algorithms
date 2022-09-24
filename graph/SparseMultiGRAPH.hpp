#include "Edge.hpp"
#include <list>
#include <vector>

class SparseMultiGRAPH {
private:
  int Vcnt;
  int Ecnt;
  bool digraph;
  std::vector<std::list<Edge>> adj;

public:
  SparseMultiGRAPH(int V, bool digraph = false)
      : adj(V), Vcnt(V), Ecnt(0), digraph(digraph) {
    adj.assign(V, {});
  }
  int V() const { return Vcnt; }
  int E() const { return Ecnt; }
  bool directed() const { return digraph; }
  void insert(Edge e) {
    int v = e.v, w = e.w;
    adj[v].push_front(e);
    if (!digraph)
      adj[w].push_front(e);
    Ecnt++;
  }
  void remove(Edge e);
  bool edge(int v, int w) const;

  class adjIterator {
  private:
    const SparseMultiGRAPH &G;
    int v;
    std::list<Edge>::const_iterator cur_iterator;
    std::list<Edge>::const_iterator end_iterator;

  public:
    adjIterator(const SparseMultiGRAPH &G, int v) : G{G}, v{v} {}

    int beg() {
      cur_iterator = std::begin(G.adj[v]);
      end_iterator = std::end(G.adj[v]);
      return cur_iterator->v;
    }
    int nxt() {
      cur_iterator = std::next(cur_iterator);
      return cur_iterator->v;
    }

    bool end() { return cur_iterator == end_iterator; }
  };
  friend class adjIterator;
};
