#include <print>

#include "src/day02.hpp"
#include "src/util/fileio.hpp"

int main() {
  std::print("┌{0:─^{2}}┐\n"
             "│{1: ^{2}}│\n"
             "└{0:─^{2}}┘\n",
             "", "AOC 2024 - Day 02", 20);

  const auto example = util::read_lines("examples/day02.txt");
  std::println("Example 1-1:\t {}", day02::part1(example));
  std::println("Example 2-1:\t {}", day02::part2(example));
  std::println();

  const auto input = util::read_lines("input/day02.txt");
  std::println("Part 1:\t\t {}", day02::part1(input));
  std::println("Part 2:\t\t {}", day02::part2(input));
  std::println();

  return 0;
}
