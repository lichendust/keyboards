#include QMK_KEYBOARD_H

enum layers {
	BL = 1, // blender
	OS = 4,
	NP = 6, // numpad layer
	FN = 5, // main fn layer
	CT = 9, // control layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = UNDERTOW(
	//  1               2        3        4        5        6       7         8        9        10       11       12       13       14       15
		KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		LT(NP,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
		MO(FN),         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,          KC_ENT,
		KC_LSFT,        KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PDOT, KC_UP,   KC_RSFT,
		KC_LGUI,        KC_LALT, KC_LCTL,                           KC_SPC,                              MO(FN),  MO(CT),  KC_LEFT, KC_DOWN, KC_RGHT
	),

	[FN] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______,
		_______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, _______,          _______,
		_______, _______, KC_BRID, KC_BRIU, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, _______, KC_CAPS,
		_______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
	),

	// numpad layer
	[NP] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,          _______,
		KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PEQL,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
		_______, _______, _______,                            _______,                            KC_P0,   _______, _______, _______, _______
	),

	// blender
	[BL] = UNDERTOW(
	//  1              2        3        4        5        6        7        8             9         10         11        12       13       14       15
		_______,       _______, _______, _______, _______, _______, _______, _______,      _______, S(KC_F6),  S(KC_F12), KC_F11,  KC_F12,           _______,
		LT(NP,KC_TAB), _______, _______, _______, _______, _______, _______, _______,      _______, _______,   _______,   _______, _______,
		MO(FN),        _______, _______, _______, _______, _______, _______, S(C(KC_SPC)), KC_SPC,  KC_SPC,    _______,   _______, _______,          _______,
		_______,       _______, _______, _______, _______, _______, _______, _______,      _______, _______,   _______,   _______, _______, _______, _______,
		_______,       _______, _______,                            _______,                                   _______,   _______, _______, _______, _______
	),

	// OS SWAP
	[OS] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_LCTL, _______, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______
	),

	// control layer
	[CT] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13        14      15
		RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_DEL,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(OS),  XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______, TO(BL),  TO(0),   TO(NP)
	),
};