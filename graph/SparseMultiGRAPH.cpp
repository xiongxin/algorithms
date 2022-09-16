#include "SparseMultiGRAPH.hpp"
#include <algorithm>
#include <iterator>

void SparseMultiGRAPH::remove(Edge e) {
  std::remove(adj[e.v].begin(), adj[e.v].end(), e);
  if (!digraph)
    std::remove(adj[e.w].begin(), adj[e.w].end(), e);
}

bool SparseMultiGRAPH::edge(int v, int w) const {
  Edge e = {v, w};
  if (std::find(adj[v].begin(), adj[v].end(), e) != adj[v].end()) {
    return true;
  }

  if (!digraph && std::find(adj[w].begin(), adj[w].end(), e) != adj[w].end()) {
    return true;
  }

  return false;
}
