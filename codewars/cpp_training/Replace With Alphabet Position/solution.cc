#include <cctype>
#include <iostream>
#include <string>

std::string alphabet_position(const std::string &text) {
  std::string res;

  for (auto c : text) {
    if (isalpha(c)) {
      res += std::to_string(tolower(c) - 'a' + 1);
      res += ' ';
    }
  }
  if (res.size() > 0) return res.substr(0, res.size() - 1);
  return res;
}

int main(int argc, char const *argv[]) {
  std::cout << alphabet_position("The sunset sets at twelve o' clock.");
  return 0;
}
