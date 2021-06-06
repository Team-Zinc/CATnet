project_source_files = [
    'SocketCompat.hpp',
    'TcpClientSocket.hpp',
    'TcpServerSocket.hpp',
    'TcpSocket.hpp',
    'UdpClientSocket.hpp',
    'UdpServerSocket.hpp',
    'UdpSocket.hpp'
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

