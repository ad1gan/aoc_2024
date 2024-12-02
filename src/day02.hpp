#include <algorithm>
#include <print>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

namespace day02 {
inline size_t part1(const std::vector<std::string> &input) {
  auto res = 0u;

  for (const auto &line : input) {
    std::stringstream iss(line);
    std::vector<int> nums;
    int num;

    while (iss) {
      iss >> num;
      nums.push_back(num);
    }

    std::vector<int> diffs;
    std::ranges::transform(nums | std::ranges::views::slide(2u),
                           std::back_inserter(diffs),
                           [](const auto &x) { return x[0] - x[1]; });
    diffs.pop_back();

    res += std::ranges::all_of(
               diffs, [](const auto &x) { return -1 >= x && x >= -3; }) ||
           std::ranges::all_of(diffs,
                               [](const auto &x) { return 1 <= x && x <= 3; });
  }

  return res;
}

inline size_t part2(const std::vector<std::string> &input) {
  auto res = 0u;
  return res;
}

} // namespace day02
