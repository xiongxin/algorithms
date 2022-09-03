#include "../DenseGRAPH.hpp"
#include "../IO.hpp"

template <typename Graph> std::vector<Edge> edges(const Graph &G) {
  int E = 0;
  std::vector<Edge> a(G.E());

  for (int v = 0; v < G.V(); v++) {
    typename Graph::adjIterator A{G, v};
    for (int w = A.beg(); !A.end(); w = A.nxt())
      if (G.directed() || v < w)
        a[E++] = Edge(v, w);
  }

  return a;
}

int main(int argc, char const *argv[]) {
  DenseGRAPH g{1000, false};
  g.insert(Edge(0, 1));
  g.insert(Edge(0, 2));
  IO<DenseGRAPH>::show(g);

  return 0;
}
