for file in $(find src -iname ./*.hpp -o -iname ./*.cpp -o -iname ./*.c -iname ./*.h); do
    echo -e "\033[A\r\033[K$file"
    clang-format -i --style=file $file
done

