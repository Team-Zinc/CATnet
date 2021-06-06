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

# Spdlog
spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
spdlog_inc = spdlog_proj.get_variable('inc')

# CLI11
cli11_proj = subproject('cli11')
cli11_dep = cli11_proj.get_variable('CLI11_dep')
cli11_inc = cli11_proj.get_variable('CLI11_inc')

# subdir('vendor')
subdir('src')
