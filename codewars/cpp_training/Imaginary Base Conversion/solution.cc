#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using Complex = pair<int, int>;

static array complex_table = {make_pair(1, 0), make_pair(0, 1),
                              make_pair(-1, 0), make_pair(0, -1)};

Complex power_mul_num(int power, int mul) {
  Complex com = complex_table[power % 4];
  if (mul == 0) {
    return Complex{};
  }
  return com;
}

vector<int> convert(string n) {
  reverse(n.begin(), n.end());
  vector<Complex> sum_v{};
  vector<int> res{0, 0};
  for (int i = n.size() - 1; i >= 0; --i) {
    sum_v.push_back(power_mul_num(i, n[i] - '0'));
  }

  res[0] = accumulate(sum_v.begin(), sum_v.end(), 0,
                      [&](int acc, const Complex& x) { return x.first + acc; });

  res[1] =
      accumulate(sum_v.begin(), sum_v.end(), 0,
                 [&](int acc, const Complex& x) { return x.second + acc; });

  return res;
}

int main(int argc, char const* argv[]) {
  Complex c{};
  vector<int> result = convert(string("1011001"));
  cout << result[0] << ":" << result[1] << "\n";
  return 0;
}
