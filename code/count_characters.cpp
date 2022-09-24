#include <map>
#include <string>

std::map<char, unsigned> count(const std::string &string) {
  std::map<char, unsigned> cu{};
  for (auto c : string) {
    cu[c]++;
  }

  return cu;
}

int main(int argc, char const *argv[]) {
  auto res = count("aba");
  return 0;
}
