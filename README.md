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

1. The `keymaps/undertow.c` file will be hard linked to `qmk/keyboards/dz60/keymaps/undertow/keymap.c`.

2. The `undertow.h` file will be hard linked to `qmk/keyboards/undertow/dz60.h`, replacing the layout definition for that board.

3. The `undertow.mk` file will be hard linked to `qmk/keyboards/dz60/rules.mk`.

```
undertow.c  -> qmk/keyboards/dz60/keymaps/undertow/keymap.c
undertow.h  -> qmk/keyboards/dz60/dz60.h
undertow.mk -> qmk/keyboards/dz60/rules.mk
```

Any directories that do not exist already are created, but the script _will_ exit if the model is not found in the `keyboards` directory.  This prevents useless files from being written into the repository in the event of a typo, a hard-learned lesson from when I wrote the script.

If the script finds no matching local files, it will simply compile and/or flash the existing keymap in QMK core.

The `flash` argument on the end of the command is optional and now _disabled_ by default due to some fun problems I've had with `dfu-programmer` on Windows.