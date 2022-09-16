#include "../../DenseGRAPH.hpp"
#include "../../IO.hpp"
#include "../../SparseMultiGRAPH.hpp"
#include <iostream>
#include <vector>

template <typename Graph> void show(const Graph &G) {
  for (int i = 0; i < G.V(); i++) {
    for (int j = 0; j < G.V(); j++) {
      std::cout.width(2);
      std::cout << std::boolalpha << G.edge(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  SparseMultiGRAPH dg{10, false};
  IO<SparseMultiGRAPH>::scanEZ(dg);
  IO<SparseMultiGRAPH>::show(dg);
  return 0;
}
