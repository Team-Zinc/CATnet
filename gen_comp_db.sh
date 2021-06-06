if [[ ! -d "build" ]]
then
    echo "please make the build directory"
    exit 1
fi

cd build
ninja -t compdb -x c_COMPILER cpp_COMPILER > ../compile_commands.json
cd ../

cat compile_commands.json > build/compile_commands.json
cat compile_commands.json > src/compile_commands.json

