#pragma once

#include "Edge.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

template <typename Graph> class IO {
public:
  // functions for printing a graph
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

  // inserting edges defined by pairs of integers on standard input
  static void scanEZ(Graph &G) {
    std::cout << "Please input pair of int, ex: `1,2` ; input `quit` to end \n";

    while (true) {
      std::string line{};

      std::getline(std::cin, line);
      if (line == "quit") {
        break;
      }
      std::size_t pos{};
      int v1{std::stoi(line, &pos)};
      int v2{std::stoi(line.substr(pos + 1))};

      Edge edge{v1, v2};
      G.insert(edge);
    }
  }
  // inserting edges defined by pairs of symbols on standard input
  static void scan(Graph &);

  static void randE(Graph &G, int E) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < E; i++) {
      int v = static_cast<int>(G.V() * std::rand() / (1.0 + RAND_MAX));
      int w = static_cast<int>(G.V() * std::rand() / (1.0 + RAND_MAX));
      G.insert(Edge{v, w});
    }
  }
};
