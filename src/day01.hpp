
#include <algorithm>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace day01 {
inline size_t part1(const std::vector<std::string> &input) {
  std::vector<int> left(input.size());
  std::vector<int> right(input.size());

  for (const auto &[idx, line] : std::ranges::views::enumerate(input)) {
    size_t a, b;
    std::istringstream iss(line);
    iss >> a >> b;

    left[idx] = a;
    right[idx] = b;
  }

  std::ranges::sort(left);
  std::ranges::sort(right);

  return std::ranges::fold_left(
      std::ranges::zip_view(left, right), 0u, [](size_t x, const auto &v) {
        return x + std::abs(std::get<0u>(v) - std::get<1u>(v));
      });
}

inline size_t part2(const std::vector<std::string> &input) {
  std::vector<int> left(input.size());
  std::unordered_map<int, size_t> right;
  right.reserve(input.size());

  for (const auto &[idx, line] : std::ranges::views::enumerate(input)) {
    size_t a, b;
    std::istringstream iss(line);
    iss >> a >> b;
    left[idx] = a;
    right[b] = right.contains(b) ? right[b] + 1u : 1u;
  }

  return std::ranges::fold_left(
      left, 0u, [&](size_t x, const auto &v) { return x + v * right[v]; });
}

} // namespace day01
