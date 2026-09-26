#include QMK_KEYBOARD_H

enum layers {
    _BASIC = 0,
    _KRITA,
    _MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASIC] = LAYOUT(
               C(KC_S), TO(1),   KC_PSLS,
        KC_P7, KC_P8,   KC_P9,   KC_PAST,
        KC_P4, KC_P5,   KC_P6,   KC_PMNS,
        KC_P1, KC_P2,   KC_P3,   KC_PPLS,
        KC_P0, KC_P0,   KC_PDOT, KC_PENT
    ),
    [_KRITA] = LAYOUT(
                  C(KC_S),  KC_1,    KC_2,
        KC_TAB,   KC_SLSH,  KC_B,    KC_E,
        MO(2),    KC_RGHT,  KC_LSFT, C(KC_F),
        KC_V,     KC_Z,     KC_GRV,  S(KC_I),
        KC_LGUI,  KC_LALT,  KC_LCTL, KC_SPC
    ),
    [_MEDIA] = LAYOUT(
                 XXXXXXX, TO(0),   XXXXXXX,
        XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,
        KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU,
        XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

/*#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU,  KC_VOLD), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), },
    [1] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), },
};
#endif*/

bool encoder_update_user(uint8_t index, bool anti_clockwise) {
	switch (get_highest_layer(layer_state)) {
	case 0:
		anti_clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT);
		break;

	case 1:
		register_code(KC_LEFT_SHIFT);
		anti_clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT);
		unregister_code(KC_LEFT_SHIFT);
		break;

	case 2:
		anti_clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
		break;
	}

	return false;
}
