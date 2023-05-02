# ⌨️ Keyboards

This is the repository for my keyboards, like the Undertow and the Wanderer, as well as a handful of macro pads.

This repository used to be a local affair, with scripts that built and flashed each board, whether ZMK or QMK.  You can still see this old repository on the `archive` branch.

Because keyboard firmwares have bloated beyond all reason and recognition and *for some reason* have grown to require their own, dedicated, Python toolchains for compilation that require sacrificing goats to get working, I've ported all of my current boards to an Actions workflow.

## Branches

Each board lives on a separate, orphaned branch, named for the firmware and board itself:

- `qmk/undertow`
- `zmk/wanderer`
- `zmk/rotr`

I also frequently build boards for friends:

- `qmk/milo`
- `zmk/candy`

## Docs

To create a new orphaned branch, use:

	git switch --orphan qmk/xxx