#pragma once

struct Edge {
  int v;
  int w;
  Edge(int v = -1, int w = -1) : v{v}, w{w} {}
};

inline bool operator==(const Edge &lhs, const Edge &rhs) {

  return (lhs.v == rhs.v && lhs.w == rhs.w) ||
         (lhs.v == rhs.w && lhs.w == rhs.v);
}

inline bool operator!=(const Edge &lhs, const Edge &rhs) {
  return !(lhs == rhs);
}
