# "and when you're dead ill be still alive. still alive. still alive." -- inspriation, unknown

# Define the project.
project(
  'catnet', # Set project name
  'cpp', # Set project language
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

# Spdlog (What the hell does SPD stand for?)
message('Downloading and building spdlog....')
spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
spdlog_inc = spdlog_proj.get_variable('inc')

# CLI11 (Descriptive?)
message('Downloading and building cli11....')
cli11_proj = subproject('cli11')
cli11_dep = cli11_proj.get_variable('CLI11_dep')
cli11_inc = cli11_proj.get_variable('CLI11_inc')

subdir('src')
