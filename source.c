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
	switch (get_highest_layer(layer_state)) {
	case 0:
		switch (index) {
		// top left
		case 0: clockwise ? tap_code(KC_VOLU)  : tap_code(KC_VOLD);

		// top right
		case 1:
			register_code(KC_LEFT_SHIFT);
			clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
			unregister_code(KC_LEFT_SHIFT);

		// big boi
		case 2: clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
		}
	case 1:
		switch (index) {
		// top left
		case 0: clockwise ? tap_code(KC_VOLU)              : tap_code(KC_VOLD);
		// top right
		case 1: clockwise ? tap_code(QK_MOUSE_WHEEL_RIGHT) : tap_code(QK_MOUSE_WHEEL_LEFT);
		// big boi
		case 2: clockwise ? tap_code(QK_MOUSE_WHEEL_DOWN)  : tap_code(QK_MOUSE_WHEEL_UP);
		}
	}
	return false;
}
