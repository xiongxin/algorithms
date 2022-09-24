#pragma once

#include "Edge.hpp"
#include <vector>

class DenseGRAPH {
private:
  int Vcnt;
  int Ecnt;
  bool digraph;
  std::vector<std::vector<bool>> adj;

public:
  DenseGRAPH(int, bool);
  int V() const { return Vcnt; }
  int E() const { return Ecnt; }
  bool directed() const { return digraph; }
  void insert(Edge);
  void remove(Edge);
  bool edge(int v, int w) const { return adj[v][w]; }

<<<<<<< HEAD
  public:
    adjIterator(const DenseGRAPH &, int);
    int beg() {
      i = -1;
      return nxt();
    }
    int nxt();
    bool end() const { return i >= G.V(); }
  };

=======
  class adjIterator;
>>>>>>> branch 'main' of git@github.com:xiongxin/algorithms.git
  friend class adjIterator;
};
