#include QMK_KEYBOARD_H

enum layers {
	_BL = 1, // blender
	_NP = 6, // numpad layer
	_FN = 5, // main fn layer
	_CT = 9, // control layer
};


// TAP DANCES
enum tap_dances {
	HOME = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[HOME] = ACTION_TAP_DANCE_DOUBLE(KC_H, SGUI(KC_H)) // HH to go to browser home
};


// MACROS
enum macros {
	RSYNC_EXC = SAFE_RANGE,
	RSYNC_RUN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case RSYNC_EXC:
			if (record->event.pressed) {
				SEND_STRING("ls -a > .exclude; vim .exclude");
			}
			break;
		case RSYNC_RUN:
			if (record->event.pressed) {
				SEND_STRING("rsync -av --delete --delete-excluded --ignore-errors --exclude-from=\"$HOME/.exclude\" ./ /Volumes/");
			}
			break;
	}
	return true;
};


// KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = UNDERTOW(
	//  1               2        3        4        5        6        7        8        9        10       11       12       13       14       15
		KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		LT(_NP,KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
		MO(_FN),        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   TD(HOME), KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,          KC_ENT,
		KC_LSFT,        KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NUHS, KC_UP,   KC_RSFT,
		KC_LGUI,        KC_LALT, KC_LCTL,                           KC_SPC,                              KC_RCTL, MO(_CT), KC_LEFT, KC_DOWN, KC_RGHT
	),

	[_FN] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______,
		_______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, _______,          _______,
		KC_CAPS, _______, KC_BRID, KC_BRIU, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
	),

	// numpad layer
	[_NP] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PEQL,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
		_______, _______, _______,                            _______,                            KC_P0,   _______, _______, _______, _______
	),

	// blender
	[_BL] = UNDERTOW(
	//  1        2        3        4        5        6        7        8           9        10       11       12       13       14       15
		_______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_F11,  KC_F12,           XXXXXXX,
		MO(_NP), XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, KC_F13,     KC_F14,  KC_F15,  _______, XXXXXXX, XXXXXXX,
		MO(_FN), S(KC_A), _______, A(KC_I), XXXXXXX, _______, _______, S(A(KC_A)), A(KC_A), A(KC_A), XXXXXXX, XXXXXXX, XXXXXXX,          _______,
		_______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______,
		_______, _______, _______,                            _______,                               _______, _______, _______, _______, _______
	),

	// control layer
	[_CT] = UNDERTOW(
	//  1        2        3        4        5        6        7        8        9        10       11       12       13        14      15
		RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______, TO(_BL), TO(0),   TO(_NP)
	),
};