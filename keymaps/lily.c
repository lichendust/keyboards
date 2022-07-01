#include QMK_KEYBOARD_H

enum layers {
    CONTROL = 0,
    KRITA,
    ASEPRITE,
    REAPER,
    BLENDER_A,
    BLENDER_B,
};

enum custom_keycodes {
    RDEL_L = SAFE_RANGE,
    RDEL_R,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RDEL_L:
        if (record->event.pressed) {
           SEND_STRING(SS_TAP(X_K));           // K
           SEND_STRING(SS_TAP(X_DEL));         // Delete
        }
        break;
    case RDEL_R:
        if (record->event.pressed) {
           SEND_STRING(SS_LSFT(SS_TAP(X_K)));  // Shift + K
           SEND_STRING(SS_TAP(X_DEL));         // Delete
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base (control) layer
    [CONTROL] = LAYOUT_planck_mit(
        RESET,   RGB_TOG, RGB_MOD,   RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,       XXXXXXX,       KC_BSPC,

    //
        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,       XXXXXXX,       XXXXXXX,

    //           undo     redo
        XXXXXXX, C(KC_Z), RCS(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TO(BLENDER_A), TO(BLENDER_B), XXXXXXX,

    //                                        prev         play/pause    next
        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_MPRV,     KC_MPLY,      KC_MNXT, TO(CONTROL), TO(KRITA),     TO(ASEPRITE),  TO(REAPER)
    ),

    /*
        krita and aseprite are designed to match _relatively_
        closely, mostly on the left-hand side. the center and
        right-hand side deviate into more specific app functions
    */

    // krita
    [KRITA] = LAYOUT_planck_mit(
    //  esc      fit          rot        100%      deselect    reselect   swap c                  cut      copy       paste
        KC_ESC,  KC_3,        KC_5,      KC_1,     RCS(KC_A),  RCS(KC_D), KC_X,       XXXXXXX,    C(KC_X), C(KC_C),   C(KC_V), _______,

    //  canvas   quick b      brush      eraser    freehand*   marquee    free-trans  apply                brush--    brush++  save             * freehand must be changed in program
        KC_TAB,  KC_PSLS,     KC_B,      KC_E,     KC_J,       C(KC_R),   C(KC_T),    KC_ENT,     XXXXXXX, KC_LBRC,   KC_RBRC, C(KC_S),

    //  brush s  undo         redo       mirror    layer n     layer c    layer del   clip group  group    ungroup             inc. save
        KC_LSFT, _______,     _______,   KC_M,     KC_INS,     KC_DEL,    S(KC_DEL),  RCS(KC_G),  C(KC_G), LCA(KC_G), KC_UP,   LCA(KC_S),

    //  picker   rotate       zoom       pan
        KC_LCTL, LSA(KC_SPC), S(KC_SPC), KC_SPC,   _______,         _______,          _______,    _______, KC_LEFT,   KC_DOWN, KC_RGHT
    ),

    // aseprite
    [ASEPRITE] = LAYOUT_planck_mit(
    //  esc                                 deselect reselect   swap c              cut        copy     paste
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, C(KC_D), RCS(KC_D), KC_X,     XXXXXXX,  C(KC_X),   C(KC_C), C(KC_V), _______,

    //  canvas   contour  brush    eraser   freehand marquee    move      apply                brush--  brush++  save
        KC_TAB,  KC_D,    KC_B,    KC_E,    KC_Q,    KC_M,      KC_V,     KC_ENT,   XXXXXXX,   KC_MINS, KC_EQL,  C(KC_S),

    //           undo     redo     bucket   layer n  cell c     cell dup  cell link group
        KC_LSFT, _______, _______, KC_G,    S(KC_N), KC_DEL,    A(KC_D),  A(KC_M),  LSA(KC_G), XXXXXXX, KC_UP,   XXXXXXX,

    //  picker            zoom*    pan                                                                                      * zoom must changed to "quick zoom" in program
        KC_LALT, XXXXXXX, KC_Z,    KC_SPC,  _______,      _______,        _______,  _______,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // reaper tracking / composing
    [REAPER] = LAYOUT_planck_mit(
    //  esc      m rec    m over
        KC_ESC,  KC_F20,  KC_F21,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_DEL,
    //           solo     mute              glue item  split d  split    split d
        XXXXXXX, KC_S,    KC_M,    XXXXXXX, RCS(KC_G), RDEL_L,  KC_K,    RDEL_R,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
    //           undo     redo
        KC_LSFT, _______, _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_UP,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_SPC,      XXXXXXX, TO(CONTROL), KC_LEFT, KC_DOWN, KC_RGHT

        /*
            notes:

            t / shift+t    >    forwards/backwards through takes
            shift+alt+t    >    select take and forget all others
            shift+ctrl+t   >    delete active take but keep others

            shift+ctrl+g   >    glue section in for looping, etc. (note this is actually the time-selection glue, don't use this)

            looped source action > /
        */
    ),

    // blender animation / general
    [BLENDER_A] = LAYOUT_planck_mit(
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, TO(CONTROL),   XXXXXXX, XXXXXXX, XXXXXXX

        /*
            notes:
            paste flipped poses
            show/hide overlays toggle
        */
    ),

    // blender boarding
    [BLENDER_B] = LAYOUT_planck_mit(
    //  esc      fit      camera
        KC_ESC,  KC_HOME, KC_P0,        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

    //  edit     select   pen tool      overlays               grab                                brush--  brush++  save
        KC_TAB,  KC_A,    S(KC_SPC),    C(KC_GRV),    XXXXXXX, KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, C(KC_S),

    //  shift    undo     redo                                 box
        KC_LSFT, _______, _______,      XXXXXXX,      XXXXXXX, KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,

    //  ctrl     alt      zoom          pan
        KC_LCTL, KC_LALT, LCA(XXXXXXX), LSA(XXXXXXX), _______,     _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
};