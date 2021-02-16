# Unit testing stuffs for head.

incdir = include_directories('../../../vendor/googletest/googletest/include/')

project_test_files = [
    'head.cpp'
]

test('head_tests',
  executable(
    'run_head_tests',
    files(project_test_files),
    include_directories : incdir,
    dependencies : [test_dep],
    install : false,
  )
)
