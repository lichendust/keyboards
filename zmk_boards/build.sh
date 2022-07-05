#!/bin/bash

set -e

if [ -z $1 ]; then
	echo "please specify a board"
	exit 1;
fi

source zmk/zephyr/zephyr-env.sh
PATH="$(pwd)/cmake/bin:$PATH"

mkdir -p build

pushd zmk/app > /dev/null

west build -p -b bt60_v1 -- -DZMK_CONFIG="$(realpath ../../zmk_boards/$1)"

popd > /dev/null

mv ./zmk/app/build/zephyr/zmk.uf2 build/$1.uf2