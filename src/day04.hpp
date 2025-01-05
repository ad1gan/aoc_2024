#include "util/matrix.hpp"
#include <ranges>

namespace day04 {
inline size_t part1(const util::matrix<char> &input) {
  auto res = 0u;
  const auto search_str = "XMAS";

  const auto dirs = {std::pair{1, 0},  std::pair{-1, 0}, std::pair{0, 1},
                     std::pair{0, -1}, std::pair{1, 1},  std::pair{-1, -1},
                     std::pair{1, -1}, std::pair{-1, 1}};

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

  const auto first_diag =
      std::array{std::pair{0, 0}, std::pair{1, 1}, std::pair{2, 2}};
  const auto second_diag =
      std::array{std::pair{0, 2}, std::pair{1, 1}, std::pair{2, 0}};

  auto found_mas = [](const std::string &str) {
    return "MAS" == str || "SAM" == str;
  };

  for (auto col = 0; col < static_cast<int>(input.num_cols) + 2; ++col)
    for (auto row = 0; row < static_cast<int>(input.num_rows) + 2; ++row) {
      std::string first_str;
      std::string second_str;
      for (const auto &[pos_1, pos_2] :
           std::ranges::views::zip(first_diag, second_diag)) {
        first_str += input.at_or_default(row + pos_1.first, col + pos_1.second);
        second_str +=
            input.at_or_default(row + pos_2.first, col + pos_2.second);
      }

      res += found_mas(first_str) && found_mas(second_str);
    }

  return res;
}

} // namespace day04
