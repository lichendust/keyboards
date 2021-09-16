#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(
	//  esc      reset rot    fit        100%      deselect    reselect                      cut      copy     paste
		KC_ESC,  KC_5,        KC_3,      KC_1,     RCS(KC_A),  RCS(KC_D), XXXXXXX,  XXXXXXX, C(KC_X), C(KC_C), C(KC_V),  MO(1),

	//  canvas   brush                             marquee     ellipse    free-trans                                    save
		KC_TAB,  KC_B,        XXXXXXX,   XXXXXXX,  C(KC_R),    KC_J,      C(KC_T),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_S),

	//  mirror   undo         redo       mirror                                                                         inc. save
		KC_LSFT, C(KC_Z),     RCS(KC_Z), KC_M,     XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   LCA(KC_S),

	//  canvas   rotate       zoom       pan       prev              play/pause     next
		XXXXXXX, LSA(KC_SPC), S(KC_SPC), KC_SPC,   KC_MPRV,          KC_MPLY,       KC_MNXT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
	),

	[1] = LAYOUT_planck_mit(
		RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	)
};