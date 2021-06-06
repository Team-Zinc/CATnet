project_source_files = [
    'socket_compat.hpp',
    'tcp_client_socket.hpp',
    'tcp_server_socket.hpp',
    'tcp_socket.hpp',
    'udp_client_socket.hpp',
    'udp_server_socket.hpp',
    'udp_socket.hpp'
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

