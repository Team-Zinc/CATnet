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

# Build all of our vendored dependencies first

subdir('vendor')
subdir('src')
