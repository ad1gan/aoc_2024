#include <print>
#include <string>
#include <vector>

#include <ctre.hpp>

namespace day03 {
inline size_t part1(const std::vector<std::string> &input) {
  auto res = 0u;

  auto extract_mul = [](const auto &str) {
    return ctre::search_all<"mul\\((\\d+),(\\d+)\\)">(str);
  };

  for (const auto &line : input) {
    auto all_matches = extract_mul(line);
    for (const auto &match : all_matches)
      res += match.get<1>().to_number() * match.get<2>().to_number();
  }

  return res;
}

inline size_t part2(const std::string &input) {
  auto res = 0u;

  return res;
}

} // namespace day03
