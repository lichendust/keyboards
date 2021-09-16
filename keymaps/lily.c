#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit( // krita (testing)
	//           100%     fit        reset rot
		KC_ESC,  KC_1,    KC_3,      KC_5,        KC_R,    KC_T,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_N,    TO(1),
	//  canvas   zoom     xx         rotate
		KC_TAB,  XXXXXXX, S(KC_SPC), LSA(KC_SPC), KC_F,    KC_G,   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, TO(2),
		KC_LSFT, C(KC_Z), C(KC_X),   C(KC_C),     C(KC_V), KC_B,   KC_P,     KC_M,    KC_GRV,  KC_COMM, KC_UP,   TO(0),
		XXXXXXX, XXXXXXX, KC_LSFT,   KC_LALT,     KC_LCTL,    KC_SPC,        XXXXXXX, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
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