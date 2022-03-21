#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// BASE LAYER
	[0] = LAYOUT_planck_mit(
		RESET,   RGB_TOG, RGB_MOD,   RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F24,

	//
		XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

	//           undo     redo
		XXXXXXX, C(KC_Z), RCS(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

	//                                        prev         play/pause    next
		XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_MPRV,     KC_MPLY,      KC_MNXT, TO(0),   TO(1),   TO(2),   TO(3)
	),



	// KRITA
	[1] = LAYOUT_planck_mit(
	//  esc      fit          rot        100%      deselect    reselect                        cut      copy       paste
		KC_ESC,  KC_3,        KC_5,      KC_1,     RCS(KC_A),  RCS(KC_D), XXXXXXX,    XXXXXXX, C(KC_X), C(KC_C),   C(KC_V), _______,

	//  canvas   quick b      brush      eraser    clip group  group      ungroup     apply             brush--    brush++  save
		KC_TAB,  KC_PSLS,     KC_B,      KC_E,     RCS(KC_G),  C(KC_G),   LCA(KC_G),  KC_ENT,  XXXXXXX, KC_LBRC,   KC_RBRC, C(KC_S),

	//  mirror   undo         redo       mirror    ellipse     marquee    free-trans  layer n  layer c  layer del           inc. save
		KC_LSFT, _______,     _______,   KC_M,     KC_J,       C(KC_R),   C(KC_T),    KC_INS,  KC_DEL,  S(KC_DEL), KC_UP,   LCA(KC_S),

	//  pick     rotate       zoom       pan
		KC_LCTL, LSA(KC_SPC), S(KC_SPC), KC_SPC,   _______,         _______,          _______, _______, KC_LEFT,   KC_DOWN, KC_RGHT
	),



	// BLENDER STORYBOARDING
	[2] = LAYOUT_planck_mit(
	//  esc      fit      camera
		KC_ESC,  KC_HOME, KC_P0,        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

	//  edit     select   pen tool      overlays               grab                                brush--  brush++  save
		KC_TAB,  KC_A,    S(KC_SPC),    C(KC_GRV),    XXXXXXX, KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, C(KC_S),

	//  shift    undo     redo                                 box
		KC_LSFT, _______, _______,      XXXXXXX,      XXXXXXX, KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,

	//  ctrl     alt      zoom          pan
		KC_LCTL, KC_LALT, LCA(XXXXXXX), LSA(XXXXXXX), _______,     _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
	),



	// BLENDER GENERAL / ANIMATION
	[3] = LAYOUT_planck_mit(
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

	// ASEPRITE
	[4] = LAYOUT_planck_mit(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LALT, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX,     XXXXXXX,      XXXXXXX, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX
	),

	// REAPER
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

			shift+ctrl+g   >    glue section in for looping, etc.

			looped source action > /
		*/
	),
};