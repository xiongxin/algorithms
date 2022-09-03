// Write an ADT client that adds all the edges in a given vector to a given
// graph.
#include "../../Edge.hpp"
#include <vector>

template <typename Graph>
void insert_edges(const Graph &G, std::vector<Edge> edges) {
  for (auto edge : edges) {
    G.insert(edge);
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
