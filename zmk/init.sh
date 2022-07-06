#!/bin/bash

set -e

if [ -z $1 ]; then
	echo "please specify a board"
	exit 1;
fi

pushd zmk/$1 > /dev/null

west init -l config
west update
west zephyr-export

popd > /dev/null