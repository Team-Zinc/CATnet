if [[ ! -d "build" ]]
then
    meson build || exit
fi

cd build
ninja -t compdb -x c_COMPILER cpp_COMPILER > compile_commands.json
cd ../