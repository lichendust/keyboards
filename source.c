#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
	switch (index) {
	case 0:
		// top left
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
		break;
	case 1:
		// top right
		if (clockwise) {
			tap_code(KC_RIGHT);
		} else {
			tap_code(KC_LEFT);
		}
		break;
	case 2:
		// big boi
		if (clockwise) {
			tap_code(KC_RIGHT);
		} else {
			tap_code(KC_LEFT);
		}
		break;
	}
	return false;
}
