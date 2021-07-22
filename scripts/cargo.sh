#!/bin/sh

set -e

echo $@

old=$(pwd)
cd $1

if [[ "$2" == "release" ]]; then
    # CARGO_TARGET_DIR=$old/src/ cargo build --release
    cargo build --release
else
    CARGO_TARGET_DIR=$old/src/$4 cargo build
fi

echo "Searching for archives"
arhives=()
echo "$old/src/$4/$2/*.a"
for arhive in $(find $old/src/$4/$2/*.a); do
    echo -e "\tFound: $archive"
    arhives+=$(realpath $arhive)
done

cd $old
echo $(pwd)

echo "Recompressing archive objects...."
echo ${archives[@]}
ar -cr $3 "${arhives[@]}"

ranlib $3 

echo -e "\tOutput: $3"

