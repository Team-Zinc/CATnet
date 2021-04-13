project_source_files = [
  'whisker.cpp'
]

project_dependencies = [
  logging_dep
]

build_args = [
]

inc_dirs = [
  spdlog_inc
]

project_target = executable(
  'whisker',
  project_source_files,
  dependencies: project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
  cpp_pch : '../pch/pch.hpp'
)

subdir('docs')
