# ⌨️ Keyboards

This is the repository for my keyboards, like the Undertow and the Wanderer, as well as a handful of macro pads.  The bigger boards both have custom pin layouts and complicated keymaps, so this repository is designed to streamline their management.

## Contents

### Main Boards

#### Wanderer

A Polarity Works BT60 V2 board in a bamboo case, an evolution of the Undertow.

```
zmk/build.sh bt60:wanderer
```

#### Undertow

A DZ60 board in a walnut case.

```
qmk/build.sh dz60:undertow
```

### Macro Pads

#### ROTR

A beautiful magnetic encoder-based macro pad, also from Polarity Works.

```
zmk/build.sh rotr:rotr
```

#### JBoK

"Just a Bunch of Keys"; A Planck-clone Niu Mini from KBDFans that I use as a giant macro pad.  Semi-deprecated because the Wanderer is essentially the result of smashing this board together with the Undertow.

```
qmk/build.sh niu_mini:jbok
```

### Other

#### Sven

Sven is an ortholinear 75 board that's chilling in a cupboard.

```
qmk/build.sh idobo:sven
```

## Usage

As you seen above, you can build any board in this repository using the firmware-appropriate build scripts, sharing a common syntax:

```
zmk_boards/build.sh bt60:wanderer
qmk_boards/build.sh dz60:undertow
```

The final firmware will be saved to a top-level `build` directory, named according to the second part of the argument:

```
build/wanderer.uf2
build/undertow.hex
```

You'll need to set up all dependencies for each firmware, which is explained (or assisted by) the scripts and docs in each directory.