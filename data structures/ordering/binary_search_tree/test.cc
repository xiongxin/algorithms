#include <iostream>

#include "binary_search_tree.hpp"

int b = 100;
void f(int*& i) { i = &b; }

int main(void) {
  int a = 1230;
  int* c = &a;
  f(c);
  std::cout << a << '\n';
  return 0;
}
