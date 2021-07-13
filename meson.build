# "and when you're dead ill be still alive. still alive. still alive." -- inspriation, unknown

# Define the project.
project(
  'catnet', # Set project name
  ['c', 'cpp'], # Set project language
  version : '0.0.1', # Set project version
  default_options : [
    # https://mesonbuild.com/Builtin-options.html
    'warning_level=3', # Enable some good warnings
    'c_std=c17', # Require the C17 standard.
    'cpp_std=c++17', # Require the C++17 standard.
    'cpp_args-I=@BUILD_ROOT@/src/catnetd.p', # Include generated protobuf header.
    'fortran_std=f2018' # For computationally intensive work
  ]
)

# add_global_arguments('-I./src/catnet.d/proto', language : 'cpp')



# Build all of our wraped dependencies first

# Python3 (Wonder when Python4 will come out....)
python3 = find_program('python3', version : '>=3.3.0', required : true)
if not python3.found()
  message('You need python3 installed with a version of at least 3.3.0 to compile this software.')
  message('And no, we are not going to build it for you. :D')
endif

# Doxygen (Not, I repeat, NOT a replacement for oxygen. We don't need to lose another.)
doxygen = find_program('doxygen', required : false)
if not doxygen.found()
  message('Please keep in mind that you do not have Doxygen installed. This means that *whatever*')
  message('you choose (to generate documentation or not too), will be IGNORED. As such, no documentation')
  message('will be generated.')
endif

# TODO: Make it so we could build Google ProtoBuf if not found
# Google ProtoBuf (Sounds very simular to protogent? Weird flex, but ok!)
protobuf_dep = dependency('protobuf', version : '>=3.0.0', required : true)
if not protobuf_dep.found()
  message('You need Google ProtoBuf installed with a version of at least 3.0.0 to compile this software.')
  message('And no, we are not going to build it for you. Maybe in a future release! :D')
endif
protoc = find_program('protoc', required : true)

# TODO: Make it so we could build LibSodium if not found
# You need your salt
sodium_dep = dependency('libsodium', required : true)
if not sodium_dep.found()
  message('You need LibSodium installed to compile this software.')
  message('And no, we are not going to build it for you. Maybe in a future release! :D')
endif

# Threading support (Support Free Trade!)
thread_dep = dependency('threads')

# Fmtlib (dont format the library)
# Originally I needed this for SPDLOG to not
# spit out linker errors, but this is actually
# a really fucking handy/cool library.
message('Downloading and building fmtlib....')
fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')
fmt_inc = fmt_proj.get_variable('fmt_inc')

# Spdlog (What the hell does SPD stand for?)
message('Downloading and building spdlog....')
spdlog_proj = subproject('spdlog', default_options : ['compile_library=true'])
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
spdlog_inc = spdlog_proj.get_variable('inc')

# CLI11 (Descriptive?)
message('Downloading and building cli11....')
cli11_proj = subproject('cli11')
cli11_dep = cli11_proj.get_variable('CLI11_dep')
cli11_inc = cli11_proj.get_variable('CLI11_inc')

# Gtest/Gmock
if get_option('enable-testing')
  message('Downloading and building gtest and gmock....')
  gtest_proj = subproject('gtest')
  gtest_dep = gtest_proj.get_variable('gtest_dep')
endif

message('Downloading an installing json (nlohmann)....')
json_proj = subproject('nlohmann_json')
json_dep = json_proj.get_variable('nlohmann_json_dep')

subdir('src')

# The executable will only be created if enable-testing is given.
subdir('tests')
