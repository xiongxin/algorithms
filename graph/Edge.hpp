#pragma once

struct Edge {
  int v;
  int w;
  Edge(int v = -1, int w = -1) : v{v}, w{w} {}
};
