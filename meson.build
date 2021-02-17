# Define the project.

project(
  'catnet', # Set project name
  'cpp', # Set project language
  version : '0.0.1', # Set project version
  default_options : [
    'warning_level=3', # Enable some good warnings
    'c_std=c17', # Require the C17 standard.
    'cpp_std=c++17' # Require the C++17 standard.
  ]
)

# Build all of our wraped dependencies first

# Googletest (we can add gtest_prog.get_variable('gmock_dep') to get google mock too)
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

# Spdlog
spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
spdlog_inc = spdlog_proj.get_variable('inc')

# subdir('vendor')
subdir('src')
