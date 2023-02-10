#include <string>

std::string fakeBin(std::string str) {
  // your code here

  std::string res;

  for (auto c : str) {
    if ((c - '0') < 5) {
      res.push_back('0');
    } else {
      res.push_back('1');
    }
  }

  return res;
}
