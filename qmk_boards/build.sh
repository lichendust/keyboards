#!/bin/bash

set -e

regex() {
	[[ $1 =~ $2 ]] && echo "${BASH_REMATCH[1]}"
}

# extract arguments
target=$(regex $1 '^(.*):.*$')
keymap=$(regex $1 '^.*:(.*)$')

if [ ! $target ]; then
	echo 'Invalid argument given'
	exit 0
fi

mkdir -p build

# paths
base_path="./qmk/keyboards/${target}"
header_path="${base_path}/${target}.h"
keymap_path="${base_path}/keymaps/${keymap}"
rules_path="${base_path}/rules.mk"

# check if target model is valid in QMK
if ! test -f "$header_path"; then
	echo "Target keyboard \"${target}\" has no QMK definition"
	exit 0
fi

# link files if they exist
if test -f "qmk_boards/${keymap}.c"; then
	mkdir -p "${keymap_path}"
	ln -f "qmk_boards/${keymap}.c" "${keymap_path}/keymap.c"
fi

if test -f "qmk_boards/${keymap}.h"; then
	ln -f "qmk_boards/${keymap}.h" "${header_path}"
fi

if test -f "qmk_boards/${keymap}.mk"; then
	ln -f "qmk_boards/${keymap}.mk" "${rules_path}"
fi

# make firmware
pushd qmk > /dev/null
echo "Compiling ${keymap}..."
make "$1"
popd > /dev/null

# copy the final to the build folder
mv qmk/${target}_${keymap}.hex build/${keymap}.hex

# if [ $2 ] && [ $2 = "flash" ]; then
	# dfu-programmer atmega32u4 erase --force && \
	# dfu-programmer atmega32u4 flash "qmk/${target}_${keymap}.hex" && \
	# dfu-programmer atmega32u4 reset
# fi