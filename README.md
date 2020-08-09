# ⌨️ Keyboards

```
niu_mini:lily ── lily.c

idobo:sven ───── sven.c

dz60:undertow ┬─ undertow.c
              ├─ undertow.h
              └─ undertow.mk
```

## quick start

1. Clone [QMK](https://qmk.fm) as `qmk`:

```
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git qmk
```

2. Install dependencies (if needed):

```
qmk/util/qmk_install.sh
```

3. Physically reset your keyboard.

4. Link, build and flash a keymap:

```
flash.sh board_model:board_name flash
```

...or compile without flashing:

```
flash.sh board_model:board_name
```

## flash.sh

`flash.sh` wraps the QMK compile step and automatically flashes an eligible connected keyboard.

Using the Undertow keyboard in this repository as an example, here are the steps the script executes:

```
flash.sh dz60:undertow flash
```

It then hardlinks the files in the following pattern:

```
keymaps/undertow.c  -> qmk/keyboards/dz60/keymaps/undertow/keymap.c
keymaps/undertow.h  -> qmk/keyboards/dz60/dz60.h
keymaps/undertow.mk -> qmk/keyboards/dz60/rules.mk
```

Any directories that do not exist already are created, but the script _will_ exit if the model is not found in the `keyboards` directory.  This prevents useless files from being written into the repository in the event of a typo, a hard-learned lesson from when I wrote the script.

If the script finds no matching local files, it will simply compile and/or flash a keymap that ships with QMK.

## windows flashing

The `flash` argument on the end of the command is optional and now _disabled_ by default due to `dfu-programmer` not working (for me) on Windows.

`dfu-programmer.exe` seems to kick back to the usage output no matter what I pass to it (without error, except the implied "bad argument").  WSL Linux's `dfu-programmer` can't seem to find any USB ports, which isn't really all that surprising.  I'm sure there's some horrendous hack I can perform for that, but I can't be bothered.

My current solution is just to use QMK Toolbox for the flashing step.

This script works great on my Mac though, so that's nice.  By extension, it should work without issue on all Unix-based platforms.