#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(
	//  esc      100%     fit        reset rot    deselect   reselect
		KC_ESC,  KC_1,    KC_3,      KC_5,        RCS(KC_A), RCS(KC_D), XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, MO(1),

	//  brush    bsize                            marquee    ellipse    free-trans                                        save
		KC_B,    KC_LSFT, XXXXXXX,   XXXXXXX,     C(KC_R),   KC_J,      C(KC_T),    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, C(KC_S),

	//  mirror   undo     redo       cut          copy       paste                                                        inc. save
		KC_M,    C(KC_Z), RCS(KC_Z), C(KC_X),     C(KC_C),   C(KC_V),   XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, KC_UP,   LCA(KC_S),

	//  canvas   pan      zoom       rotate       prev            play/pause        next
		KC_TAB,  KC_SPC,  S(KC_SPC), LSA(KC_SPC), KC_MPRV,        KC_MPLY,          KC_MNXT,   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
	),

	[1] = LAYOUT_planck_mit(
		RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	)
};