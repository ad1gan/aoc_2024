#include "util/matrix.hpp"
#include <algorithm>
#include <ranges>

namespace day04 {
inline size_t part1(const util::matrix<char> &input) {
  auto res = 0u;

  const auto search_str = "XMAS";

  // const std::array<std::pair<int, int>, 8u> dirs = {
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

  const auto first_dirs =
      std::array{std::array{std::pair{1, 1}, std::pair{2, 2}},
                 std::array{std::pair{-1, 1}, std::pair{-2, 2}}};
  const auto second_dirs =
      std::array{std::array{std::pair{1, 1}, std::pair{2, 0}},
                 std::array{std::pair{-1, 1}, std::pair{-2, 0}}};

  auto found_mas = [](const std::string &str) {
    return "MAS" == str || "SAM" == str;
  };

  for (auto col = 0; col < static_cast<int>(input.num_cols) + 2; ++col)
    for (auto row = 0; row < static_cast<int>(input.num_rows) + 2; ++row)
      if (input.at_or_default(row, col) == 'M') {
        std::string first_str = std::string{input.at_or_default(row, col)};
        std::string second_str = std::string{input.at_or_default(row, col + 2)};

        if (second_str == "M" || second_str == "S")
          for (auto j = 0u; j < 2; ++j) {
            const auto first_diag = first_dirs[j];
            const auto second_diag = second_dirs[j];

            std::print("first_diag ({}, {}), ({},{}), ({},{})\n", row, col,
                       row + first_diag[0].first, col + first_diag[0].second,
                       row + first_diag[1].first, col + first_diag[1].second);
            std::print("second_diag ({}, {}), ({},{}), ({},{})\n", row, col + 2,
                       row + second_diag[0].first, col + second_diag[0].second,
                       row + second_diag[1].first, col + second_diag[1].second);

            for (auto i = 0; i < 2; ++i) {
              first_str += input.at_or_default(row + first_diag[i].first,
                                               col + first_diag[i].second);
              second_str += input.at_or_default(row + second_diag[i].first,
                                                col + second_diag[i].second);
            }
            std::println("found: {}, {} <-> {}\n",
                         found_mas(first_str) && found_mas(second_str),
                         first_str, second_str);

            res += found_mas(first_str) && found_mas(second_str);

            first_str = std::string{input.at_or_default(row, col)};
            second_str = std::string{input.at_or_default(row, col + 2)};
          }
      }

  return res;
}

} // namespace day04
