subdir('logging')
subdir('sockets')
subdir('proto')

project_source_files = [
  'daemon.cpp',
  'registrar/registrar.cpp',
  'participant/participant.cpp',
  'participant/registrar_exchange.cpp',
  'participant/whisker_exchange.cpp',
  head_whisker_exchange_gened
]

project_dependencies = [thread_dep, socket_dep, cli11_dep, logging_dep, protobuf_dep] # protobuf_dep here fixes it
build_args = [
]
inc_dirs = [cli11_inc, spdlog_inc, socket_inc]

project_target = executable(
  'catnetd',
  project_source_files,
  dependencies : project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

subdir('docs')
