# Unit testing stuffs for head.

project_test_files = [
    'log.cpp'
]

project_dependencies = [
  gtest_dep,
  logging_dep
]

inc_dirs = [
    spdlog_inc
]

test('logging_tests',
  executable(
    'run_logging_tests',
    files(project_test_files),
    dependencies : project_dependencies,
    include_directories : spdlog_inc,
    install : false,
  )
)
