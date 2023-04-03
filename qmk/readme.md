# QMK

## Quick Start

1. Clone [QMK](https://qmk.fm) as `firmware` inside this folder:

	git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git firmware

2. Install dependencies (if needed):

	firmware/util/qmk_install.sh

3. Physically reset your keyboard.

4. Link and build a keymap (from the top-level directory!):

	qmk/build.sh dz60:undertow

You can even specify the internal boards that ship with the firmware, without needing to create your own keymaps — though conflicting names will choose the local ones, so beware.

## Build Script

`build.sh` wraps the QMK compile step and automatically flashes an eligible connected keyboard.  The goal here is to minimise interaction with the enormous QMK repository and file structure, by simply managing your keymaps outside of it.

Using the Undertow keyboard in this repository as an example, here are the steps the script executes:

	qmk/build.sh dz60:undertow

It then hardlinks the files in the following pattern:

	undertow.c  -> firmware/keyboards/dz60/keymaps/undertow/keymap.c
	undertow.h  -> firmware/keyboards/dz60/dz60.h
	undertow.mk -> firmware/keyboards/dz60/rules.mk

Any directories that do not exist already are created, but the script _will_ exit if the model is not found in the `keyboards` directory.  This prevents useless files from being written into the repository in the event of a typo, a hard-learned lesson from when I wrote the script.

### Flashing

You can optionally add the `flash` argument:

	qmk/build.sh dz60:undertow flash

...which will directly call DFU Programmer to flash the compiled firmware to an eligible board.

If you use the Windows Subsystem for Linux to run these scripts, like I do, this won't work — WSL has no access to the hardware USB ports.  You could change `dfu-programmer` to `dfu-programmer.exe`, assuming you have a relevant Windows installation, but I've had little success with this for some reason.  DFU Programmer seems not to work standalone, though the bundled one in QMK Toolbox is fine.