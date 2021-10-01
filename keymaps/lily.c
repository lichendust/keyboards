#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(
	//  esc      fit          rot        100%      deselect    reselect                        cut      copy       paste
		KC_ESC,  KC_3,        KC_5,      KC_1,     RCS(KC_A),  RCS(KC_D), XXXXXXX,    XXXXXXX, C(KC_X), C(KC_C),   C(KC_V), XXXXXXX,

	//  canvas   quick b      brush                marquee     ellipse    free-trans  apply                                 save
		KC_TAB,  KC_PSLS,     KC_B,      XXXXXXX,  C(KC_R),    KC_J,      C(KC_T),    KC_ENT,  XXXXXXX, XXXXXXX,   XXXXXXX, C(KC_S),

	//  mirror   undo         redo       mirror    clip group  group      ungroup     layer n  layer c  layer del           inc. save
		KC_LSFT, C(KC_Z),     RCS(KC_Z), KC_M,     RCS(KC_G),  C(KC_G),   LCA(KC_G),  KC_INS,  KC_DEL,  S(KC_DEL), KC_UP,   LCA(KC_S),

	//  pick     rotate       zoom       pan       prev              play/pause       next
		KC_LCTL, LSA(KC_SPC), S(KC_SPC), KC_SPC,   KC_MPRV,          KC_MPLY,         KC_MNXT, MO(1),   KC_LEFT,   KC_DOWN, KC_RGHT
	),

	[1] = LAYOUT_planck_mit(
		RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F24,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	)
};