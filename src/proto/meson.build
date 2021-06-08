# Compile .proto files
# gen_proto = custom_target(
#   'head_whisker_exchange.bp.cc',
#   input : ['head_whisker_exchange.proto'],
#   output : ['head_whisker_exchange.bp.cc'],
#   command : [
#     join_paths(meson.source_root(), 'scripts', 'protoc'), meson.build_root(), meson.current_source_dir(), '@OUTPUT@',
#     '--proto_path=.', '--cpp_out=.', 'head_whisker_exchange.proto'
#   ]
# )

# Very close to protogent. Werid flex, but ok
proto_gen = generator(python3,
  output : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : [join_paths(meson.source_root(), 'scripts', 'protoc'), # Call the wrapper
    meson.current_build_dir(), '@BASENAME@.pb.cc', # Give the warpper the info it needs
    '--proto_path=.', '--cpp_out=.', '@INPUT@'] # Pass it to the actual compiler
)

head_whisker_exchange_gened = proto_gen.process('head_whisker_exchange.proto')
