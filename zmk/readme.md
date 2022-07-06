# ZMK

## Quick Start

1. Install the dependencies for ZMK according to the [documentation here](https://zmk.dev/docs/development/setup).

2. Clone/download a precompiled version of CMake 3.20+ as `cmake` inside this `zmk` directory.  If you already have a version of CMake greater than 3.20+ installed, you can skip this step.

3. Initialise all the ZMK nonsense using the `init` script for each board you want to build:

```
zmk/init.sh wanderer
```

(Prepare to wait for an alarming amount of time for some keyboard firmware to install literal gigabytes of dependencies).

4. Build the firmware using `zmk/build.sh` from the top-level directory.

## Build Script

The build script for ZMK is much simpler than the QMK version.  Right now, unlike QMK, it can't build boards that ship with ZMK, it's hardcoded for local config directories.

It, very basically, simplifies the management of ZMK and West, loading the correct, local version of CMake, importing the ZMK environment variables, building the specified layout and outputting it to a `build` directory (ZMK buries the outputted firmware in its folder structure for some reason).

## Gotchas

West, by default, tries to do some kind of partial build or compilation.  I don't pretend to understand it and it only reduces the build time by about 1/3.  However, it seems to crap itself quite often and refuse to rebuild, so you may need to do one or both of the following to fix it:

1. Use the `-p` flag for a "pristine" build.  Add the flag as the first argument to the West call in `build.sh`

2. Delete the `build` folder inside the relevant board's directory.  This requires re-running `west zephy-export` (also in the board directory).