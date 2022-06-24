#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// base (control) layer
	[0] = LAYOUT_planck_mit(
		RESET,   RGB_TOG, RGB_MOD,   RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F24,

	//
		XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

	//           undo     redo
		XXXXXXX, C(KC_Z), RCS(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

	//                                        prev         play/pause    next
		XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_MPRV,     KC_MPLY,      KC_MNXT, TO(0),   TO(1),   TO(2),   TO(3)
	),

	/*
		krita and aseprite are designed to match _relatively_
		closely, mostly on the left-hand side. the center and
		right-hand side deviate into more specific app functions
	*/

	// krita
	[1] = LAYOUT_planck_mit(
	//  esc      fit          rot        100%      deselect    reselect                           cut      copy       paste
		KC_ESC,  KC_3,        KC_5,      KC_1,     RCS(KC_A),  RCS(KC_D), XXXXXXX,    XXXXXXX,    C(KC_X), C(KC_C),   C(KC_V), _______,

	//  canvas   quick b      brush      eraser    freehand*   marquee    free-trans  apply                brush--    brush++  save             * freehand must be changed in program
		KC_TAB,  KC_PSLS,     KC_B,      KC_E,     KC_J,       C(KC_R),   C(KC_T),    KC_ENT,     XXXXXXX, KC_LBRC,   KC_RBRC, C(KC_S),

	//  mirror   undo         redo       mirror    layer n     layer c    layer del   clip group  group    ungroup             inc. save
		KC_LSFT, _______,     _______,   KC_M,     KC_INS,     KC_DEL,    S(KC_DEL),  RCS(KC_G),  C(KC_G), LCA(KC_G), KC_UP,   LCA(KC_S),

	//  picker   rotate       zoom       pan
		KC_LCTL, LSA(KC_SPC), S(KC_SPC), KC_SPC,   _______,         _______,          _______,    _______, KC_LEFT,   KC_DOWN, KC_RGHT
	),

	// aseprite
	[2] = LAYOUT_planck_mit(
	//  esc                                 deselect reselect                       cut        copy     paste
		KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, C(KC_D), RCS(KC_D), XXXXXXX,  XXXXXXX,  C(KC_X),   C(KC_C), C(KC_V), _______,

	//  canvas   contour  brush    eraser   freehand marquee    move      apply                brush--  brush++  save
		KC_TAB,  KC_D,    KC_B,    KC_E,    KC_Q,    KC_M,      KC_V,     KC_ENT,   XXXXXXX,   KC_MINS, KC_EQL,  C(KC_S),

	//           undo     redo     bucket   layer n  cell c     cell dup  cell link group
		KC_LSFT, _______, _______, KC_G,    S(KC_N), KC_DEL,    A(KC_D),  A(KC_M),  LSA(KC_G), XXXXXXX, KC_UP,   XXXXXXX,
q
	//  picker            zoom*    pan                                                                                      * zoom must changed to "quick zoom" in program
		KC_LALT, XXXXXXX, KC_Z,    KC_SPC,  _______,      _______,        _______,  _______,   KC_LEFT, KC_DOWN, KC_RGHT
	),

	// blender boarding
	[3] = LAYOUT_planck_mit(
	//  esc      fit      camera
		KC_ESC,  KC_HOME, KC_P0,        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

	//  edit     select   pen tool      overlays               grab                                brush--  brush++  save
		KC_TAB,  KC_A,    S(KC_SPC),    C(KC_GRV),    XXXXXXX, KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, C(KC_S),

	//  shift    undo     redo                                 box
		KC_LSFT, _______, _______,      XXXXXXX,      XXXXXXX, KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,

	//  ctrl     alt      zoom          pan
		KC_LCTL, KC_LALT, LCA(XXXXXXX), LSA(XXXXXXX), _______,     _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
	),

	// blender animation / general
	[4] = LAYOUT_planck_mit(
		KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX

		/*
			notes:
			paste flipped poses
			show/hide overlays toggle
		*/
	),

	// reaper tracking / composing
	[5] = LAYOUT_planck_mit(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX

		/*
			notes:

			t / shift+t    >    forwards/backwards through takes
			shift+alt+t    >    select take and forget all others
			shift+ctrl+t   >    delete active take but keep others

			shift+ctrl+g   >    glue section in for looping, etc. (note this is actually the time-selection glue, don't use this)

			looped source action > /
		*/
	),
};