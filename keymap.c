#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LAYERTWO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        MO(1),            KC_BSPC,             RM_PREV,  RM_TOGG, RM_NEXT,    KC_F1,   KC_F2,   KC_F3,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,    KC_PAUS,  KC_SCRL, KC_PSCR,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_INS,   KC_HOME, KC_PGUP,    KC_HOME,          KC_END,
        KC_P4,   KC_P5,   KC_P6,               KC_END,   KC_DEL,  KC_PGDN,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,              KC_UP,                        KC_B,
        KC_P0,            KC_PDOT,             KC_LEFT,  KC_DOWN, KC_RGHT
    ),
    [_LAYERTWO] = LAYOUT(
        _______,          KC_BSPC,             RM_PREV,  RM_TOGG, RM_NEXT,    KC_A,    QK_RBT,  QK_BOOT,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,    KC_PAUS,  KC_SCRL, KC_PSCR,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_INS,   KC_HOME, KC_PGUP,    KC_HOME,          KC_END,
        KC_P4,   KC_P5,   KC_P6,               KC_END,   KC_DEL,  KC_PGDN,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,              KC_UP,                        KC_B,
        KC_P0,            KC_PDOT,             KC_LEFT,  KC_DOWN, KC_RGHT
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
	switch (index) {
	case 0:
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
		break;
	case 1:
		if (clockwise) {
			tap_code(KC_LEFT);
		} else {
			tap_code(KC_RIGHT);
		}
		break;
	case 2:
		if (clockwise) {
			tap_code(KC_PGDN);
		} else {
			tap_code(KC_PGUP);
		}
		break;
	}
}
