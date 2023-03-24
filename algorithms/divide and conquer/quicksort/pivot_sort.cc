#include <bits/stdc++.h>
using namespace std;

void pivot_sort(vector<int> &src, int pivot) {
  assert(src.size() > 0 && "src.size must bigger than 0");

  int s = 0;
  int e = src.size() - 1;
  for (;;) {
    while (src[s] < pivot) ++s;
    while (src[e] > pivot) --e;

    if (s < e) swap(src[s], src[e]);

    // 这里有个优化的地方可以将 --s且--e
    // 最后会形成两个非常好的区间用于递归
    // 1. [0, e] 小与pivot区间
    // 2. [s, src.size() - 1] 小与pivot区间
    else
      break;
  }
}

int main(int argc, char const *argv[]) {
  vector<int> s{4, 5, 12, 34, 55, 6, 56, 3, 2, 44, 1};
  vector<int> s1{};
  pivot_sort(s1, 6);
  for (auto i : s) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
