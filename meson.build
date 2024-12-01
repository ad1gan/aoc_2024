project('aoc 2024',
        'cpp',
        version : '2024.0.1',
        default_options : ['cpp_std=c++23',
                           'warning_level=3',
                           'debug=false',
                           'optimization=3'
                          ])
cxx = meson.get_compiler('cpp')

src_inc = include_directories('src/')

day01_exe = executable('day01', ['src/day01.cpp'], include_directories: src_inc)
