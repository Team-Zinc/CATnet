subdir('logging')
subdir('sockets')

project_source_files = [
  'daemon.cpp',
  'registrar/registrar.cpp',
  'participant/participant.cpp'
]

project_dependencies = [socket_dep, cli11_dep, logging_dep]
build_args = []
inc_dirs = [socket_inc, cli11_inc, spdlog_inc]

project_target = executable(
  'catnetd',
  project_source_files,
  dependencies : project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

subdir('docs')
