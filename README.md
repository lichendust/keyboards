# ⌨️ Keyboards

```
.
├── niu_mini:lily
│   └── lily.c
│
├── idobo:sven
│   └── sven.c
│
└── dz60:undertow
    ├── undertow.c
    ├── undertow.h
    └── undertow.mk
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

Any `.c`, `.h` or `.mk` files alongside `flash.sh` and `qmk` will be hard-linked into the correct location based on the provided argument, which is accepted in the same format as QMK's `make` argument.

1. The `board_name.c` file will be hard linked to `qmk/keyboards/board_model/keymaps/board_name/keymap.c`, adding a new keymap to the firmware's `make` scope easily.

2. Any `board_name.h` files will be hard linked to `qmk/keyboards/board_model/board_model.h`, replacing the layout definition for that board.

3. Any `board_name.mk` files will be hard linked to `qmk/keyboards/board_model/rules.mk`, replacing the rule flags for that board.

```
undertow.c  -> qmk/keyboards/dz60/keymaps/undertow/keymap.c
undertow.h  -> qmk/keyboards/dz60/dz60.h
undertow.mk -> qmk/keyboards/dz60/rules.mk
```

If there are no local files, `flash.sh` will simply compile and flash the existing keymap in the core repo QMK.

It will also exit if the `board_model` keyboard is not found within QMK, so as not to write useless files and directories into the firmware repository in the event of a typo.

The `flash` argument on the end of the command is optional and now _disabled_ by default due to some fun problems I've had with `dfu-programmer` on Windows.