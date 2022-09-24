#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

struct PeakData {
  std::vector<int> pos, peaks;
};

PeakData pick_peaks(std::vector<int> v) {
  PeakData result;
  int i, t;
  for (t = 0, i = 1; i < v.size(); i++)
    if (v[i] > v[i - 1])
      t = i;
    else if (t && v[i] < v[i - 1])
      result.pos.push_back(t), result.peaks.push_back(v[t]), t = 0;
  return result;
}

int main(int argc, char const *argv[]) {
  // pick_peaks(std::vector<int>{3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
  return 0;
}
