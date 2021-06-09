logging_source_files = [
  'log.cpp'
]

logging_dependencies = [
    spdlog_dep
]

logging_build_args = [
]

logging_inc_dirs = [
  spdlog_inc
]

logging_target = static_library(
  'catnet_logging',
  logging_source_files,
  dependencies: logging_dependencies,
  include_directories : logging_inc_dirs,
  install : true,
  cpp_args : logging_build_args,
)

logging_inc = include_directories('include')
logging_dep = declare_dependency(
  include_directories: logging_inc,
  link_with : logging_target
)

subdir('docs')
