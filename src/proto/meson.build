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
proto_gen = generator(protoc,
  output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : ['--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@BUILD_DIR@', '@INPUT@'])

base_gened = proto_gen.process('base.proto')
test_connection_gened = proto_gen.process('test_connection.proto')
pubkey_exchange_gened = proto_gen.process('pubkey_exchange.proto')

