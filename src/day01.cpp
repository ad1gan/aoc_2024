#include "src/util/fileio.hpp"

#include <algorithm>
#include <print>
#include <ranges>
#include <sstream>
#include <unordered_map>

namespace day01 {
size_t part1(const std::vector<std::string> &input) {
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

size_t part2(const std::vector<std::string> &input) {
  std::vector<int> left(input.size());
  std::unordered_map<int, size_t> right;

  for (const auto &[idx, line] : std::ranges::views::enumerate(input)) {
    size_t a, b;
    std::istringstream iss(line);
    iss >> a >> b;
    left[idx] = a;
    right[b] = right.contains(b) ? right[b] + 1 : 1u;
  }

  return std::ranges::fold_left(
      left, 0u, [&](size_t x, const auto &v) { return x + v * right[v]; });
}

} // namespace day01

int main() {
  const auto example = util::read_lines("examples/day01.txt");
  std::println("Example 1-1:\t {}", day01::part1(example));
  std::println("Example 2-1:\t {}", day01::part2(example));

  const auto input = util::read_lines("input/day01.txt");
  std::println("Part 1:\t\t {}", day01::part1(input));
  std::println("Part 2:\t\t {}", day01::part2(input));

  return 0;
}
