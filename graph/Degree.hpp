#include <vector>

template <typename Graph> class Degree {
private:
  const Graph &G;
  std::vector<int> degrees;

public:
  Degree(const Graph &G) : G{G}, degrees(G.V(), 0) {
    for (int v = 0; v < G.V(); ++v) {
      typename Graph::adjIterator A(G, v);
      for (int w = A.beg(); !A.end(); w = A.nxt()) {
        degrees[v]++;
      }
    }
  }

  int operator[](int v) const { return degrees[v]; }
};
