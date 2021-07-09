if get_option('enable-testing')
  test_source_files = [
    head_whisker_exchange_gened,
    'main.cpp',
    'daemon_test.cpp',
  ]

  logging_inc = include_directories('../src/logging/include')
  sockets_inc = include_directories('../src/sockets/include')
  message_inc = include_directories('../src/message/include')
  participant_inc = include_directories('../src/participant/include')
  registrar_inc = include_directories('../src/registrar')
  base_inc = include_directories('../src')

  test_dependencies = [
    project_dependencies,
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

  test_target = executable(
    'catnetd_tests',
    test_source_files,
    cpp_pch : 'pch/pch.hpp',
    dependencies : test_dependencies,
    link_with : project_library_target,
    include_directories : inc_dirs,
    install : false,
    cpp_args : build_args,
  )
endif

