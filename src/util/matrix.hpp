#pragma once
#include <print>

#include <algorithm>
#include <cmath>
#include <vector>

#include "util/fileio.hpp"

namespace util {

/// TODO Changed to mdspan if available in gcc
template <typename T> struct matrix {
  size_t num_rows;
  size_t num_cols;

  std::vector<T> data;

  auto begin() { return data.begin(); }
  auto end() { return data.end(); }

  auto begin() const { return data.begin(); }
  auto end() const { return data.end(); }

  auto cbegin() const { return data.cbegin(); }
  auto cend() const { return data.cend(); }

  matrix(const matrix &other) = default;
  matrix(matrix &&other) = default;
  matrix &operator=(const matrix &other) = default;
  matrix &operator=(matrix &&other) = default;

  template <typename V>
  friend bool operator==(const matrix<V> &lhs, const matrix<V> &rhs);

  template <typename V>
  friend bool operator!=(const matrix<V> &lhs, const matrix<V> &rhs);

  matrix(size_t _num_rows, size_t _num_cols, T init = T{})
      : num_rows(_num_rows), num_cols(_num_cols) {
    data.resize(num_rows * num_cols, init);
  }

  template <typename C>
  matrix(const C &_data, size_t _num_rows, size_t _num_cols)
      : num_rows(_num_rows), num_cols(_num_cols) {
    data.resize(num_rows * num_cols);

    for (auto j = 0u; j < num_cols; ++j)
      for (auto i = 0u; i < num_rows; ++i)
        (*this)(i, j) = _data[i * num_cols + j];
  }

  template <typename C>
  matrix(const C &_data)
      : matrix<T>(_data, static_cast<size_t>(std::sqrt(_data.size())),
                  static_cast<size_t>(std::sqrt(_data.size()))) {}

  matrix() = default;

  inline T at_or_default(size_t i, size_t j) const noexcept {
    return i < num_rows && j < num_cols ? this->operator()(i, j) : T{};
  }

  inline const T &operator()(size_t i, size_t j) const noexcept {
    return data[i * num_cols + j];
  }

  /// Periodic assignment
  inline const T &operator[](size_t i, size_t j) const noexcept {
    const auto per_i = i % num_rows;
    const auto per_j = j % num_cols;

    return this->operator()(per_i, per_j);
  }

  inline T &operator()(size_t i, size_t j) noexcept {
    return data[i * num_cols + j];
  }

  /// Periodic assignment
  inline T &operator[](size_t i, size_t j) noexcept {
    const auto per_i = i % num_rows;
    const auto per_j = j % num_cols;

    return this->operator()(per_i, per_j);
  }

  std::vector<std::pair<size_t, size_t>>
  row_neighbours_idx(size_t i, size_t j) const noexcept {
    std::vector<std::pair<size_t, size_t>> res;
    res.reserve(2);

    if (i > 0)
      res.push_back({i - 1, j});
    if (i < num_rows - 1)
      res.push_back({i + 1, j});

    return res;
  }

  std::vector<std::pair<size_t, size_t>>
  col_neighbours_idx(size_t i, size_t j) const noexcept {
    std::vector<std::pair<size_t, size_t>> res;
    res.reserve(2);

    if (j > 0)
      res.push_back({i, j - 1});
    if (j < num_cols - 1)
      res.push_back({i, j + 1});

    return res;
  }

  std::vector<std::pair<size_t, size_t>>
  topleft_botright_neighbours_idx(size_t i, size_t j) const noexcept {
    std::vector<std::pair<size_t, size_t>> res;
    res.reserve(2);

    if (i > 0 && j > 0)
      res.push_back({i - 1, j - 1});
    if (i < num_rows - 1 && j < num_cols - 1)
      res.push_back({i + 1, j + 1});

    return res;
  }

  std::vector<std::pair<size_t, size_t>>
  bottomleft_topright_neighbours_idx(size_t i, size_t j) const noexcept {
    std::vector<std::pair<size_t, size_t>> res;
    res.reserve(2);

    if (i > 0 && j < num_cols - 1)
      res.push_back({i - 1, j + 1});
    if (i < num_rows - 1 && j > 0)
      res.push_back({i + 1, j - 1});

    return res;
  }

  std::vector<std::pair<size_t, size_t>>
  plus_neighbours_idx(size_t i, size_t j) const noexcept {
    auto res = row_neighbours_idx(i, j);
    auto col_neighs = col_neighbours_idx(i, j);
    res.insert(res.end(), col_neighs.begin(), col_neighs.end());

    return res;
  }

  std::vector<std::pair<size_t, size_t>>
  neighbours_idx(size_t i, size_t j) const noexcept {
    auto res = plus_neighbours_idx(i, j);
    auto tmp_1 = topleft_botright_neighbours_idx(i, j);
    auto tmp_2 = bottomleft_topright_neighbours_idx(i, j);
    res.insert(res.end(), tmp_1.begin(), tmp_1.end());
    res.insert(res.end(), tmp_2.begin(), tmp_2.end());

    return res;
  }

  std::vector<T> row_neighbours(size_t i, size_t j) const noexcept {
    return std::ranges::transform(
        row_neighbours_idx(i, j), [&](const auto &idx) {
          return this->operator()(idx.fist, idx.second);
        });
  }

  std::vector<T> col_neighbours(size_t i, size_t j) const noexcept {
    return std::ranges::transform(
        col_neighbours_idx(i, j), [&](const auto &idx) {
          return this->operator()(idx.fist, idx.second);
        });
  }

  std::vector<T> plus_neighbours(size_t i, size_t j) const noexcept {
    return std::ranges::transform(
        plus_neighbours_idx(i, j), [&](const auto &idx) {
          return this->operator()(idx.fist, idx.second);
        });
  }

  std::vector<T> topleft_botright_neighbours(size_t i,
                                             size_t j) const noexcept {
    return std::ranges::transform(
        topleft_botright_neighbours_idx(i, j), [&](const auto &idx) {
          return this->operator()(idx.fist, idx.second);
        });
  }

  std::vector<T> bottomleft_topright_neighbours(size_t i,
                                                size_t j) const noexcept {
    return std::ranges::transform(
        bottomleft_topright_neighbours_idx(i, j), [&](const auto &idx) {
          return this->operator()(idx.fist, idx.second);
        });
  }

  std::vector<T> neighbours(size_t i, size_t j) const noexcept {
    return std::ranges::transform(neighbours_idx(i, j), [&](const auto &idx) {
      return this->operator()(idx.fist, idx.second);
    });
  }

  bool valid(int i, int j) const noexcept {
    return i >= 0 && i < num_rows && j >= 0 && j < num_cols;
  }

  template <typename V> bool valid(const std::pair<V, V> &pos) const noexcept {
    return valid(pos.first, pos.second);
  }

  void print(char sep = ' ') const noexcept {
    std::print("Size: ({}, {})\n", num_rows, num_cols);
    for (auto i = 0u; i < num_rows; ++i) {
      for (auto j = 0u; j < num_cols; ++j)
        std::print("{}{}", this->operator()(i, j), sep);
      std::print("\n");
    }
  }
};

template <typename V>
bool operator==(const matrix<V> &lhs, const matrix<V> &rhs) {
  return lhs.data == rhs.data;
}

template <typename V>
bool operator!=(const matrix<V> &lhs, const matrix<V> &rhs) {
  return !(lhs == rhs);
}

inline matrix<char> read_matrix(std::string &&input_file) {
  const auto file_str = util::read_lines(std::move(input_file));

  const auto rows = file_str.size();
  const auto cols = file_str[0].size();

  matrix<char> res(rows, cols);

  for (auto j = 0u; j < cols; ++j)
    for (auto i = 0u; i < rows; ++i)
      res(i, j) = file_str[i][j];

  return res;
}

} // namespace util
