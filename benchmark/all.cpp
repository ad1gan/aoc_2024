#include "benchmark/all.hpp"
#include <benchmark/benchmark.h>

class total_time_reporter : public benchmark::BenchmarkReporter {
public:
  benchmark::ConsoleReporter default_reporter;
  double total_time_us;

  total_time_reporter() = default;

  bool ReportContext(const Context &context) override {
    return default_reporter.ReportContext(context);
  }

  void ReportRuns(const std::vector<Run> &report) override {
    default_reporter.ReportRuns(report);

    for (const auto &run : report) {
      total_time_us += run.GetAdjustedRealTime();
    }
  }

  void Finalize() override {
    std::print("\n\033[31mTotal time of whole Advent of Code 2024: {:2f} us\n",
               total_time_us);
  }
};

int main(int argc, char **argv) {
  benchmark::Initialize(&argc, argv);

  total_time_reporter reporter;
  benchmark::RunSpecifiedBenchmarks(&reporter);

  return 0;
}
