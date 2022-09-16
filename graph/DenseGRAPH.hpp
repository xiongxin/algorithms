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

  class adjIterator;
  friend class adjIterator;
};
