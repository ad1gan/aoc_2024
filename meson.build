project('aoc 2024',
        'cpp',
        version : '2024.1.1',
        default_options : ['cpp_std=c++23',
                           'warning_level=3',
                           'debug=false',
                           'optimization=3'
                          ])
cxx = meson.get_compiler('cpp')

benchmark = dependency('benchmark')

src_inc = include_directories('src/')
benchmark_inc = include_directories('benchmark/')

day01_exe = executable('day01', ['src/day01.cpp'], include_directories: src_inc)
day02_exe = executable('day02', ['src/day02.cpp'], include_directories: src_inc)

bench_exe = executable('all_benchmarks', ['benchmark/all.cpp'], include_directories: [src_inc, benchmark_inc], dependencies: benchmark)
