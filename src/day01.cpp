#include "src/util/fileio.hpp"

#include <algorithm>
#include <print>
#include <ranges>
#include <sstream>

namespace day01 {
size_t part1(const std::vector<std::string> &input) {
  std::vector<int> vec1(input.size());
  std::vector<int> vec2(input.size());

  for (const auto &[idx, line] : std::ranges::views::enumerate(input)) {
    size_t a, b;
    std::istringstream iss(line);
    iss >> a >> b;
    vec1[idx] = a;
    vec2[idx] = b;
  }

  std::ranges::sort(vec1);
  std::ranges::sort(vec2);

  return std::ranges::fold_left(
      std::ranges::zip_view(vec1, vec2), 0u, [](size_t x, const auto &v) {
        return x + std::abs(std::get<0u>(v) - std::get<1u>(v));
      });
}
} // namespace day01

int main() {
  const auto example = util::read_lines("examples/day01.txt");
  std::println("Example 1-1:\t {}", day01::part1(example));

  const auto input = util::read_lines("input/day01.txt");
  std::println("Part 1:\t\t {}", day01::part1(input));

  return 0;
}
