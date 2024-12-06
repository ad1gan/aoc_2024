#include <string>
#include <vector>

#include <ctre.hpp>

namespace day03 {
inline size_t part1(const std::vector<std::string> &input) {
  auto res = 0u;

  std::string total_input = "";
  for (const auto &str : input)
    total_input += str;

  auto reg_mul = [](const auto &str) {
    return ctre::search_all<"mul\\((\\d+),(\\d+)\\)">(str);
  };

  for (const auto &match : reg_mul(total_input))
    res += match.get<1>().to_number() * match.get<2>().to_number();

  return res;
}

inline size_t part2(const std::vector<std::string> &input) {
  auto res = 0u;

  std::string total_input = "";
  for (const auto &str : input)
    total_input += str;

  auto reg_mul = [](const auto &str) {
    return ctre::search_all<"mul\\((\\d+),(\\d+)\\)">(str);
  };

  auto reg_do = [](const auto &str) {
    return ctre::search_all<"(?:^|do\\(\\))(.*?)(?=(?:don't\\(\\))|$)">(str);
  };

  for (const auto &do_match : reg_do(total_input))
    for (const auto &mul_match : reg_mul(do_match))
      res += mul_match.get<1>().to_number() * mul_match.get<2>().to_number();

  return res;
}

} // namespace day03
