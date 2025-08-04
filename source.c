#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
	case 0:
		clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
		break;

	case 1:
		register_code(KC_LEFT_SHIFT);
		clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
		unregister_code(KC_LEFT_SHIFT);
		break;

	case 2:
		clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
		break;
	}

	return false;
}
