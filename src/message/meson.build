message_source_files = [
  'encrypt.cpp',
  'message.cpp',
  head_whisker_exchange_gened
]

message_dependencies = [
  logging_dep
]

message_build_args = [
]

message_inc_dirs = [
  spdlog_inc
]

message_inc = include_directories('include')
message_inc_dirs += message_inc
message_target = static_library(
  'catnet_message',
  message_source_files,
  cpp_pch : meson.source_root() + '/src/pch/pch.hpp',
  dependencies: message_dependencies,
  include_directories : message_inc_dirs,
  install : true,
  cpp_args : message_build_args,
)

message_dep = declare_dependency(
  include_directories: message_inc,
  link_with : message_target
)

