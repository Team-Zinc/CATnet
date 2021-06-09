# Define the project.

project(
  'catnet', # Set project name
  'cpp', # Set project language
  version : '0.0.1', # Set project version
  default_options : [
    'warning_level=3', # Enable some good warnings
    'c_std=c17', # Require the C17 standard.
    'cpp_std=c++17' # Require the C++17 standard.
  ]
)

# Build all of our wraped dependencies first

# Python3 (Wonder when Python4 will come out....)
python3 = find_program('python3', version : '>=3.3.0', required : true)
if not python3.found()
  message('You need python3 with a version of at least 3.3.0 to compile this software.')
  message('And no, we are not going to build it for you. :D')
endif

# Threading support (Support Free Trade!)
thread_dep = dependency('threads')

# Spdlog (What the hell does SPD stand for?)
spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
spdlog_inc = spdlog_proj.get_variable('inc')

# CLI11 (Descriptive?)
cli11_proj = subproject('cli11')
cli11_dep = cli11_proj.get_variable('CLI11_dep')
cli11_inc = cli11_proj.get_variable('CLI11_inc')

# ProtoBuf (You need proto anti-virus!)
# As opposed to all the other required tools and such,
# Google Protobuf takes a long time to compile. Checking
# for existance reduces build times on clean.
protoc = find_program('protoc', required: true)
# if not protobuf.found()
#   protobuf_proj = subproject('protobuf')
#   protobuf_dep = protobuf_proj.get_variable('protobuf_dep')
# else
protobuf_dep = dependency('protobuf', required : true)
# endif

# Sockpp (I wonder if this is a pun)
# sockpp_proj = subproject('sockpp')

# subdir('vendor')
subdir('src')
