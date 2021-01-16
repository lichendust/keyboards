#!/bin/bash

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
if test -f "keymaps/${keymap}.c"; then
	mkdir -p "${keymap_path}"
	ln -f "keymaps/${keymap}.c" "${keymap_path}/keymap.c"

	echo "Linked ${keymap}.c"
else
	echo "No ${keymap}.c found - not linked"
fi

if test -f "keymaps/${keymap}.h"; then
	ln -f "keymaps/${keymap}.h" "${header_path}"

	echo "Linked ${keymap}.h"
else
	echo "No ${keymap}.h found - not linked"
fi

if test -f "keymaps/${keymap}.mk"; then
	ln -f "keymaps/${keymap}.mk" "${rules_path}"

	echo "Linked ${keymap}.mk"
else
	echo "No ${keymap}.mk found - not linked"
fi

echo

# make firmware
pushd qmk > /dev/null
echo "Compiling ${keymap}..."
make "$1"
popd > /dev/null

# if [ $2 ] && [ $2 = "flash" ]; then
	# dfu-programmer atmega32u4 erase --force && \
	# dfu-programmer atmega32u4 flash "qmk/${target}_${keymap}.hex" && \
	# dfu-programmer atmega32u4 reset
# fi