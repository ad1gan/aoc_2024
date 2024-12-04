#pragma once

#include <format>
#include <fstream>
#include <string>
#include <vector>

namespace util {
inline std::vector<std::string> read_lines(std::string &&filename) {
  std::vector<std::string> res;

  std::ifstream file_stream(filename, std::ios::in);
  if (!file_stream)
    throw std::runtime_error(std::format("File {} not found\n", filename));

  for (std::string line; std::getline(file_stream, line);)
    res.push_back(std::move(line));

  file_stream.close();

  return res;
}

inline std::string read_line(const std::string &input_file) {
  std::string res;

  std::ifstream file_stream(input_file);
  if (file_stream.is_open())
    std::getline(file_stream, res);

  return res;
}

} // namespace util
