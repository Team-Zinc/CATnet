project_source_files = [
  'log.cpp'






]

project_dependencies = [
    spdlog_dep
]

build_args = [
]

inc_dirs = [
    spdlog_inc
]

logging_target = static_library(
  'catnet_logging',
  project_source_files,
  dependencies: project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

logging_inc = include_directories('include')
logging_dep = declare_dependency(
  include_directories: logging_inc,
  link_with : logging_target
)

subdir('docs')
