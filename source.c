#include QMK_KEYBOARD_H

bool oled_task_user(void) {
	oled_write_P(PSTR("\nLayer: "), false);

	switch (get_highest_layer(layer_state)) {
	case 0:
		oled_write_P(PSTR("Main\n"), false);
		break;

	case 1:
		oled_write_P(PSTR("Mouse Mods\n"), false);
		break;
	}
	return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	switch (index) {
	case 0:
		// top left
		/*if (get_highest_layer(1)) {
			clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD)
			return false;
		}*/
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
