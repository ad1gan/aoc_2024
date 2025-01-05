#include <print>

#include "src/day04.hpp"
#include "src/util/matrix.hpp"

int main() {
  std::print("┌{0:─^{2}}┐\n"
             "│{1: ^{2}}│\n"
             "└{0:─^{2}}┘\n",
             "", "AOC 2024 - Day 04", 20);

  const auto example = util::read_matrix("examples/day04.txt");
  std::println("Exrmple 1-1:\t {}", day04::part1(example));
  std::println("Example 2-1:\t {}", day04::part2(example));
  std::println();

  const auto input = util::read_matrix("input/day04.txt");
  std::println("Part 1:\t\t {}", day04::part1(input));
  std::println("Part 2:\t\t {}", day04::part2(input));
  std::println();

  return 0;
}
