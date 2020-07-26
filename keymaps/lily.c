#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(
		LT(2,KC_ESC), KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,     KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
		LT(1,KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   TD(HOME), KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT,      KC_GRV,  KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,     KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
		KC_LCTL,      KC_LALT, KC_LGUI, KC_CAPS, MO(1),     KC_SPC,       MO(2), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
	),
	[1] = LAYOUT_planck_mit(
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, KC_DEL,
		_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		RESET,   _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
	),
	[2] = LAYOUT_planck_mit(
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
		_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
		_______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
	)
};