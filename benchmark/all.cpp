#include "src/day01.hpp"
#include "src/day02.hpp"
#include "src/util/fileio.hpp"

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
  const auto input = util::read_lines("input/day01.txt");

  for (auto _ : state)
    day02::part1(input);
}

static void day02_02(benchmark::State &state) {
  const auto input = util::read_lines("input/day01.txt");

  for (auto _ : state)
    day02::part2(input);
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

BENCHMARK_MAIN();
