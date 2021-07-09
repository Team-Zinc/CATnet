project_source_files = [
  head_whisker_exchange_gened,
  'main.cpp',
  'daemon_test.cpp',
  'logging/log_test.cpp',
  'message/encrypt_test.cpp',
  'message/message_test.cpp',
]

logging_inc = include_directories('../src/logging/include')
sockets_inc = include_directories('../src/sockets/include')
message_inc = include_directories('../src/message/include')
participant_inc = include_directories('../src/participant/include')
registrar_inc = include_directories('../src/registrar')
base_inc = include_directories('../src')

project_dependencies = [
  thread_dep,
  sodium_dep,
  fmt_dep,
  cli11_dep,
  protobuf_dep,
  gtest_dep,
]

build_args = [
]

inc_dirs = [
  cli11_inc,
  fmt_inc,
  spdlog_inc,

  logging_inc,
  sockets_inc,
  message_inc,
  participant_inc,
  registrar_inc,
  base_inc,
]

project_target = executable(
  'catnetd_tests',
  project_source_files,
  cpp_pch : 'pch/pch.hpp',
  dependencies : project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

