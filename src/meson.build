# subdir('logging')
subdir('proto')
# subdir('sockets')
# subdir('message')

# proto_gen = generator(protoc,
#   output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
#   arguments : ['--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@BUILD_DIR@', '@INPUT@'])

# head_whisker_exchange_gened = proto_gen.process('proto/head_whisker_exchange.proto')

project_source_files = [
  head_whisker_exchange_gened,
  'daemon.cpp',
  'participant/participant.cpp',
  'participant/registrar_exchange.cpp',
  'participant/whisker_exchange.cpp',
  'registrar/registrar.cpp',
  'logging/log.cpp',
  'message/message.cpp',
  'message/encrypt.cpp',
  'sockets/socket_compat.cpp',
  'sockets/tcp_client_socket.cpp',
  'sockets/tcp_server_socket.cpp',
  'sockets/tcp_socket.cpp',
  'sockets/udp_client_socket.cpp',
  'sockets/udp_server_socket.cpp',
  'sockets/udp_socket.cpp',
]

logging_inc = include_directories('logging/include')
sockets_inc = include_directories('sockets/include')
message_inc = include_directories('message/include')
participant_inc = include_directories('participant/include')
registrar_inc = include_directories('registrar')
# all_inc = include_directories('include')


project_dependencies = [
  thread_dep,
  sodium_dep,
  fmt_dep,
  cli11_dep,
  protobuf_dep
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
  # all_inc
]

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
