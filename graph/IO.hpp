#pragma once

#include <iostream>

template <typename Graph> class IO {
public:
  static void show(const Graph &G) {
    for (int s = 0; s < G.V(); s++) {
      std::cout.width(2);
      std::cout << s << ":";
      typename Graph::adjIterator A{G, s};
      for (int t = A.beg(); !A.end(); t = A.nxt()) {
        std::cout.width(2);
        std::cout << t << " ";
      }
      std::cout << std::endl;
    }
  }

  // static void scanEZ(Graph &);
  // static void scan(Graph &);
};
