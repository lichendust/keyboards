# ⌨️ Keyboards

<!-- MarkdownTOC autolink="true" -->

- [ZMK](#zmk)
	- [Quick Start](#quick-start)
	- [Build Script](#build-script)
- [QMK](#qmk)
	- [Quick Start](#quick-start-1)
	- [Build Script](#build-script-1)
	- [Windows](#windows)

<!-- /MarkdownTOC -->

## ZMK

### Quick Start

1. Clone [ZMK](https://zmk.dev) as `zmk`:

	git clone https://github.com/zmkfirmware/zmk.git

2. Install the dependencies for ZMK and initialise the repository according to the [documentation here](https://zmk.dev/docs/development/setup).

3. Clone/download a version of CMake 3.20+ as `cmake` alongside the new `zmk` directory.

4. Run the ZMK builder with the name of a board directory:

	zmk/build.sh bamboo

### Build Script

The build script for ZMK is much simpler than the QMK version.  Right now, unlike QMK, it can't build boards that ship with ZMK, it's hardcoded for local config directories.

It, very basically, simplifies the management of ZMK and `west`, loading the correct, local version of CMake, importing the ZMK environment variables, building the specified layout and outputting it to a `build` directory (ZMK buries the outputted firmware in its folder structure for some reason).

## QMK

### Quick Start

1. Clone [QMK](https://qmk.fm) as `qmk`:

	git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git qmk

2. Install dependencies (if needed):

	qmk/util/qmk_install.sh

3. Physically reset your keyboard.

4. Link and build a keymap:

	qmk/build.sh dz60:undertow

### Build Script

`qmk.sh` wraps the QMK compile step and automatically flashes an eligible connected keyboard.  The goal here is to minimise interaction with the enormous QMK repository and file structure, by simply managing *your* keymaps outside of it.  If you want to submit PRs for boards or keymaps.

Using the Undertow keyboard in this repository as an example, here are the steps the script executes:

	qmk/build.sh dz60:undertow

It then hardlinks the files in the following pattern:

```
keymaps/undertow.c  -> qmk/keyboards/dz60/keymaps/undertow/keymap.c
keymaps/undertow.h  -> qmk/keyboards/dz60/dz60.h
keymaps/undertow.mk -> qmk/keyboards/dz60/rules.mk
```

Any directories that do not exist already are created, but the script _will_ exit if the model is not found in the `keyboards` directory.  This prevents useless files from being written into the repository in the event of a typo, a hard-learned lesson from when I wrote the script.

If the script finds no matching local files, it will simply compile and/or flash a keymap that ships with QMK.

### Windows

There are some lines related to DFU Programmer in `qmk.sh`

The `flash` argument on the end of the command is optional and _disabled_ by default due to `dfu-programmer` not working (for me) on Windows.

Using QMK Toolbox is the solution, it seems, on Windows.

This script works great on Mac but is untested on Linux.