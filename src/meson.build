subdir('logging')
subdir('proto')
subdir('sockets')
subdir('message')

project_source_files = [
  'daemon.cpp',
  'participant/participant.cpp',
  'participant/registrar_exchange.cpp',
  'participant/whisker_exchange.cpp',
  'registrar/registrar.cpp',
  head_whisker_exchange_gened
]

project_dependencies = [thread_dep, sodium_dep, message_dep, socket_dep, cli11_dep, logging_dep, protobuf_dep] # protobuf_dep here fixes it
build_args = [
]
inc_dirs = [cli11_inc, spdlog_inc, logging_inc, socket_inc, message_inc]

project_target = executable(
  'catnetd',
  project_source_files,
  cpp_pch : 'pch/pch.hpp',
  dependencies : project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

subdir('docs')
