project('aoc 2024',
        'cpp',
        version : '2024.4.0',
        default_options : ['cpp_std=c++23',
                           'warning_level=3',
                           'debug=false',
                           'optimization=3'
                          ])
cxx = meson.get_compiler('cpp')

benchmark = dependency('benchmark')
ctre = dependency('ctre')

deps = [ctre]

src_inc = include_directories('src/')
benchmark_inc = include_directories('benchmark/')

day01_exe = executable('day01', ['src/day01.cpp'], include_directories: src_inc, dependencies: deps)
day02_exe = executable('day02', ['src/day02.cpp'], include_directories: src_inc, dependencies: deps)
day03_exe = executable('day03', ['src/day03.cpp'], include_directories: src_inc, dependencies: deps)
day04_exe = executable('day04', ['src/day04.cpp'], include_directories: src_inc, dependencies: deps)
day05_exe = executable('day05', ['src/day05.cpp'], include_directories: src_inc, dependencies: deps)

bench_exe = executable('benchmarks', ['benchmark/all.cpp'], include_directories: [src_inc, benchmark_inc], dependencies: benchmark)
