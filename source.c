#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
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
	return false;
}
