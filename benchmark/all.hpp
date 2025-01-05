#include "src/day01.hpp"
#include "src/day02.hpp"
#include "src/day03.hpp"
#include "src/day04.hpp"
#include "src/util/fileio.hpp"
#include "src/util/matrix.hpp"

#include <benchmark/benchmark.h>

static void day01_01(benchmark::State &state) {
  const auto input = util::read_lines("input/day01.txt");

  for (auto _ : state)
    day01::part1(input);
}

static void day01_02(benchmark::State &state) {
  const auto input = util::read_lines("input/day01.txt");

  for (auto _ : state)
    day01::part2(input);
}

static void day02_01(benchmark::State &state) {
  const auto input = util::read_lines("input/day02.txt");

  for (auto _ : state)
    day02::part1(input);
}

static void day02_02(benchmark::State &state) {
  const auto input = util::read_lines("input/day02.txt");

  for (auto _ : state)
    day02::part2(input);
}

static void day03_01(benchmark::State &state) {
  const auto input = util::read_lines("input/day03.txt");

  for (auto _ : state)
    day03::part1(input);
}

static void day03_02(benchmark::State &state) {
  const auto input = util::read_lines("input/day03.txt");

  for (auto _ : state)
    day03::part2(input);
}

static void day04_01(benchmark::State &state) {
  const auto input = util::read_matrix("input/day04.txt");

  for (auto _ : state)
    day04::part1(input);
}

static void day04_02(benchmark::State &state) {
  const auto input = util::read_matrix("input/day04.txt");

  for (auto _ : state)
    day04::part2(input);
}

BENCHMARK(day01_01)
    ->Name("AOC 2024 Day01 - Part 1")
    ->Unit(benchmark::kMicrosecond);
BENCHMARK(day01_02)
    ->Name("AOC 2024 Day01 - Part 2")
    ->Unit(benchmark::kMicrosecond);

BENCHMARK(day02_01)
    ->Name("AOC 2024 Day02 - Part 1")
    ->Unit(benchmark::kMicrosecond);
BENCHMARK(day02_02)
    ->Name("AOC 2024 Day02 - Part 2")
    ->Unit(benchmark::kMicrosecond);

BENCHMARK(day03_01)
    ->Name("AOC 2024 Day03 - Part 1")
    ->Unit(benchmark::kMicrosecond);
BENCHMARK(day03_02)
    ->Name("AOC 2024 Day03 - Part 2")
    ->Unit(benchmark::kMicrosecond);

BENCHMARK(day04_01)
    ->Name("AOC 2024 Day04 - Part 1")
    ->Unit(benchmark::kMicrosecond);
BENCHMARK(day04_02)
    ->Name("AOC 2024 Day04 - Part 2")
    ->Unit(benchmark::kMicrosecond);
