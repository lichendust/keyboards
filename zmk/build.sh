#!/bin/bash

set -e

if [ -z $1 ]; then
	echo "please specify a board"
	exit 1;
fi

regex() {
	[[ $1 =~ $2 ]] && echo "${BASH_REMATCH[1]}"
}

# extract arguments
target=$(regex $1 '^(.*):.*$')
keymap=$(regex $1 '^.*:(.*)$')

# load all the appropriate settings for the board
source zmk/$keymap/zephyr/zephyr-env.sh
PATH="$(realpath zmk/cmake/bin):$PATH"

# move into the board folder and build
pushd zmk/$keymap > /dev/null
west build -s zmk/app -b $target -- -DZMK_CONFIG="$(realpath ./config)"
popd > /dev/null

# grab the compiled firmware out
mkdir -p build
mv zmk/$keymap/build/zephyr/zmk.uf2 build/$keymap.uf2
echo "output to build/$keymap.uf2"