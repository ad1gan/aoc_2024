#include "util/matrix.hpp"
#include <algorithm>

namespace day04 {
inline size_t part1(const util::matrix<char> &input) {
  auto res = 0u;

  const auto search_str = "XMAS";

  const std::vector<std::pair<int, int>> dirs = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

  for (auto col = 0; col < static_cast<int>(input.num_cols); ++col)
    for (auto row = 0; row < static_cast<int>(input.num_rows); ++row)
      if (input(row, col) == 'X')
        for (const auto &dir : dirs) {
          std::string str = "X";
          for (auto i = 1u; i < 4; ++i)
            str +=
                input.at_or_default(i * dir.first + row, i * dir.second + col);
          res += str == search_str;
        }

  return res;
}

inline size_t part2(const util::matrix<char> &input) {
  auto res = 0u;

  const auto search_str = "MAS";

  const std::vector<std::pair<int, int>> dirs = {
      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

  for (auto col = 0; col < static_cast<int>(input.num_cols); ++col)
    for (auto row = 0; row < static_cast<int>(input.num_rows); ++row)
      if (input(row, col) == 'M') {
        const auto num_found =
            std::ranges::count_if(dirs, [&](const auto &dir) {
              std::string str = "M";
              for (auto i = 1u; i < 3; ++i)
                str += input.at_or_default(i * dir.first + row,
                                           i * dir.second + col);
              return str == search_str;
            });
        res += num_found == 2;
      }

  return res;
}

} // namespace day04
