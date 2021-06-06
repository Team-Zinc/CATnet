project_source_files = [
    'socket_compat.cpp',
    'tcp_client_socket.cpp',
    'tcp_server_socket.cpp',
    'tcp_socket.cpp',
    'udp_client_socket.cpp',
    'udp_server_socket.cpp',
    'udp_socket.cpp'
]

project_dependencies = [

]

build_args = [
]

inc_dirs = [

]

socket_target = static_library(
  'catnet_sockets',
  project_source_files,
  dependencies: project_dependencies,
  include_directories : inc_dirs,
  install : true,
  cpp_args : build_args,
)

socket_inc = include_directories('.')
socket_dep = declare_dependency(
  include_directories: socket_inc,
  link_with : socket_target
)

