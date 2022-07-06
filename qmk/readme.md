# QMK

## Quick Start

1. Clone [QMK](https://qmk.fm) as `firmware` inside this folder:

```
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git firmware
```

2. Install dependencies (if needed):

```
firmware/util/qmk_install.sh
```

3. Physically reset your keyboard.

4. Link and build a keymap (from the top-level directory!):

```
qmk/build.sh dz60:undertow
```

You can even specify the internal boards that ship with the firmware, without needing to create your own keymaps — though conflicting names will choose the local ones, so beware.

## Build Script

`build.sh` wraps the QMK compile step and automatically flashes an eligible connected keyboard.  The goal here is to minimise interaction with the enormous QMK repository and file structure, by simply managing your keymaps outside of it.

Using the Undertow keyboard in this repository as an example, here are the steps the script executes:

```
qmk/build.sh dz60:undertow
```

It then hardlinks the files in the following pattern:

```
undertow.c  -> firmware/keyboards/dz60/keymaps/undertow/keymap.c
undertow.h  -> firmware/keyboards/dz60/dz60.h
undertow.mk -> firmware/keyboards/dz60/rules.mk
```

Any directories that do not exist already are created, but the script _will_ exit if the model is not found in the `keyboards` directory.  This prevents useless files from being written into the repository in the event of a typo, a hard-learned lesson from when I wrote the script.

## Windows

Context: I run all these scripts through WSL on Windows.

There are some lines related to DFU Programmer in `build.sh`, which doesn't seem to work on my PC at all for any reason.

Last time I really tried to get it working, the Windows version would just passive-aggressively spit back the "usage" output regardless of what command I gave it, while the macOS equivalent worked perfectly.  WSL doesn't have access to hardware USB ports, so a Linux install can't replace it either.

QMK Toolbox has always worked perfectly, so I even stole the DFU Programmer executable from the QMK Toolbox bundle *and it still didn't work*.

Anyway, you can uncomment those lines and just flash directly from the build script if you use an operating system that doesn't suck.  It probably isn't Windows' fault, but it sucks anyway so I'm blaming it.