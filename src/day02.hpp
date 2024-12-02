#include <algorithm>
#include <print>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

namespace day02 {
inline size_t part1(const std::vector<std::string> &input) {
  auto res = 0u;

  auto safe = [](const auto &v) -> bool {
    return std::ranges::all_of(
               v, [](const auto &x) { return -1 >= x && x >= -3; }) ||
           std::ranges::all_of(v,
                               [](const auto &x) { return 1 <= x && x <= 3; });
  };

  auto diffs = [](const auto &v) -> std::vector<int> {
    std::vector<int> res;
    std::ranges::transform(v | std::ranges::views::slide(2u),
                           std::back_inserter(res),
                           [](const auto &x) { return x[0] - x[1]; });
    res.pop_back();
    return res;
  };

  for (const auto &line : input) {
    std::stringstream iss(line);
    std::vector<int> nums;
    int num;

    while (iss) {
      iss >> num;
      nums.push_back(num);
    }

    res += safe(diffs(nums));
  }

  return res;
}

inline size_t part2(const std::vector<std::string> &input) {
  auto res = 0u;

  auto safe = [](const auto &v) -> bool {
    return std::ranges::all_of(
               v, [](const auto &x) { return -1 >= x && x >= -3; }) ||
           std::ranges::all_of(v,
                               [](const auto &x) { return 1 <= x && x <= 3; });
  };

  auto diffs = [](const auto &v) -> std::vector<int> {
    std::vector<int> res;
    std::ranges::transform(v | std::ranges::views::slide(2u),
                           std::back_inserter(res),
                           [](const auto &x) { return x[0] - x[1]; });
    res.pop_back();
    return res;
  };

  for (const auto &line : input) {
    std::stringstream iss(line);
    std::vector<int> nums;
    int num;

    while (iss) {
      iss >> num;
      nums.push_back(num);
    }

    if (safe(diffs(nums))) {
      res++;
      continue;
    }

    for (auto i = 0u; i < nums.size(); ++i) {
      auto tmp_vec = nums;
      tmp_vec.erase(tmp_vec.begin() + i);

      if (safe(diffs(tmp_vec))) {
        res++;
        break;
      }
    }
  }

  return res;
}

} // namespace day02
