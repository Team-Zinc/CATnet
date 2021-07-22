project_target = executable(
  'catnetd',
  'cli.cpp',
  cpp_pch : meson.source_root() + '/src/pch/pch.hpp',
  dependencies : project_dependencies,
  link_with : project_library_target,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

