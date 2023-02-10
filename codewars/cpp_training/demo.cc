#include <array>
#include <iostream>
#include <string>

int points(const std::array<std::string, 10>& games) {
  int res;
  for (auto match : games) {
    char x = match[0];
    char y = match[2];

    if (x > y)
      res += 3;
    else if (x == y)
      res += 1;
  }

  return res;
}

int main(int argc, char const* argv[]) {
  std::array<std::string, 10> games{"1:0", "2:0", "3:0", "4:0", "2:1",
                                    "3:1", "4:1", "3:2", "4:2", "4:3"};

  std::cout << points(games);
  return 0;
}
