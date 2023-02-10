#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

static const std::unordered_map<std::string, long> numbersMap{
    {"zero", 0},        {"and", 0},          {"one", 1},
    {"two", 2},         {"three", 3},        {"four", 4},
    {"five", 5},        {"six", 6},          {"seven", 7},
    {"eight", 8},       {"nine", 9},         {"ten", 10},
    {"eleven", 11},     {"twelve", 12},      {"thirteen", 13},
    {"fourteen", 14},   {"fifteen", 15},     {"sixteen", 16},
    {"seventeen", 17},  {"eighteen", 18},    {"nineteen", 19},
    {"twenty", 20},     {"thirty", 30},      {"forty", 40},
    {"fifty", 50},      {"sixty", 60},       {"seventy", 70},
    {"eighty", 80},     {"ninety", 90},      {"hundred", 100},
    {"thousand", 1000}, {"million", 1000000}};

long parse_int(std::string number) {
  long cur = 0;

  if (number.size() == 0) return cur;
  std::string::size_type million_pos = number.find("million");
  if (million_pos != std::string::npos) {
    return 1000000;
  }

  std::string::size_type and_pos = number.find(" and ");
  if (and_pos != std::string::npos) {
    number = number.replace(and_pos, 5, " ");
  }

  std::string::size_type thousand_pos = number.find("thousand");
  if (thousand_pos != std::string::npos) {
    cur = parse_int(number.substr(0, thousand_pos - 1)) * 1000;
    if (number.find(" ", thousand_pos) != std::string::npos) {
      return cur + parse_int(number.substr(thousand_pos + 9));
    }
    return cur;
  }

  std::string::size_type hundred_pos = number.find("hundred");
  if (hundred_pos != std::string::npos) {
    cur = parse_int(number.substr(0, hundred_pos - 1)) * 100;
    if (number.find(" ", hundred_pos) != std::string::npos) {
      return cur + parse_int(number.substr(hundred_pos + 8));
    }
    return cur;
  }

  std::string::size_type n = number.find("-");
  if (n == std::string::npos) {
    auto iter = numbersMap.find(number);
    if (iter != numbersMap.end()) {
      cur = iter->second;
    }
  } else {
    auto iter1 = numbersMap.find(number.substr(0, n));
    auto iter2 = numbersMap.find(number.substr(n + 1));

    if (iter1 != numbersMap.end() && iter2 != numbersMap.end()) {
      cur = iter1->second + iter2->second;
    }
  }

  return cur;
}

int main(int argc, char const *argv[]) {
  std::cout
      << parse_int(
             "seven hundred eighty-three thousand three hundred and nineteen")
      << "\n";
  return 0;
}
