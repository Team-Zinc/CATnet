sockets_source_files = [
]

sockets_dependencies = [
  logging_dep
]

sockets_build_args = [
]

sockets_inc_dirs = [
  spdlog_inc
]

socket_inc = include_directories('include')
sockets_inc_dirs += socket_inc
socket_target = static_library(
  'catnet_sockets',
  sockets_source_files,
  cpp_pch : meson.source_root() + '/src/pch/pch.hpp',
  dependencies: sockets_dependencies,
  include_directories : sockets_inc_dirs,
  install : true,
  cpp_args : sockets_build_args,
)

socket_dep = declare_dependency(
  include_directories: socket_inc,
  link_with : socket_target
)

