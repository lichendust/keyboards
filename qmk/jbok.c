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
    R_DELL = SAFE_RANGE,
    R_DELR,
    R_RECORD,
    R_OVERDUB,
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
        closely, though there is deviation into app-specifics
    */
    // krita
    [KRITA] = LAYOUT_planck_mit(
    //  esc      fit          rot        100%      deselect    reselect   swap c                  cut      copy       paste
        KC_ESC,  KC_3,        KC_5,      KC_1,     RCS(KC_A),  RCS(KC_D), KC_X,       XXXXXXX,    C(KC_X), C(KC_C),   C(KC_V), _______,

    //  canvas   quick b      brush      eraser    freehand*   marquee    free-trans  apply                brush--    brush++  save
        KC_TAB,  KC_PSLS,     KC_B,      KC_E,     KC_J,       C(KC_R),   C(KC_T),    KC_ENT,     XXXXXXX, KC_LBRC,   KC_RBRC, C(KC_S),

    //  brush s  undo         redo       mirror    layer n     layer c    layer del   clip group  group    ungroup             inc. save
        KC_LSFT, _______,     _______,   KC_M,     KC_INS,     KC_DEL,    S(KC_DEL),  RCS(KC_G),  C(KC_G), LCA(KC_G), KC_UP,   LCA(KC_S),

    //  picker   rotate       zoom       pan
        KC_LCTL, LSA(KC_SPC), S(KC_SPC), KC_SPC,   _______,         _______,          _______,    _______, KC_LEFT,   KC_DOWN, KC_RGHT

        /*
            notes:
            * freehand must be changed in program
        */
    ),

    // aseprite
    [ASEPRITE] = LAYOUT_planck_mit(
    //  esc                                 deselect reselect   swap c              cut        copy     paste
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, C(KC_D), RCS(KC_D), KC_X,     XXXXXXX,  C(KC_X),   C(KC_C), C(KC_V), _______,

    //  canvas   contour  brush    eraser   freehand marquee    move      apply                brush--  brush++  save
        KC_TAB,  KC_D,    KC_B,    KC_E,    KC_Q,    KC_M,      KC_V,     KC_ENT,   XXXXXXX,   KC_MINS, KC_EQL,  C(KC_S),

    //           undo     redo     bucket   layer n  cell c     cell dup  cell link group
        KC_LSFT, _______, _______, KC_G,    S(KC_N), KC_DEL,    A(KC_D),  A(KC_M),  LSA(KC_G), XXXXXXX, KC_UP,   XXXXXXX,

    //  picker            zoom*    pan
        KC_LALT, XXXXXXX, KC_Z,    KC_SPC,  _______,      _______,        _______,  _______,   KC_LEFT, KC_DOWN, KC_RGHT

        /*
            notes:
            * zoom must be changed to "quick zoom" in program
        */
    ),

    // reaper tracking / composing
    [REAPER] = LAYOUT_planck_mit(
    //  esc
        KC_ESC,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,     XXXXXXX, LCA(KC_UP),   KC_BSPC,
    //           solo     mute
        XXXXXXX, KC_S,    KC_M,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,     XXXXXXX, LCA(KC_DOWN), KC_DEL,
    //           undo     redo              glue item  split d  split    split d
        KC_LSFT, _______, _______, XXXXXXX, RCS(KC_G), R_DELL,  KC_K,    R_DELR,    XXXXXXX,     XXXXXXX, KC_UP,        XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R_RECORD,       C(KC_R),     R_OVERDUB, TO(CONTROL), KC_LEFT, KC_DOWN,      KC_RGHT

        /*
            notes:

            t / shift+t     >    forwards/backwards through takes
            shift+alt+t     >    select take and forget all others
            shift+ctrl+t    >    delete active take but keep others

            ctrl+alt+d/u    >    select next/prev track
                + shift     >    add to selection

            f6/f5           >    offline/online first plugin on track
                                 need visual feedback from reaper on this, which we don't get.

            alt+m           >    midi editor

            shift+ctrl+g    >    glue section in for looping, etc. (note this is actually the time-selection glue, don't use this)

            toggle loop     >    /
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
            need to paste flipped poses
            need a show/hide overlays toggle
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case R_DELL:
        // reaper: cuts selected regions, then deletes the left side
        if (record->event.pressed) {
           SEND_STRING(SS_TAP(X_K));    // K
           SEND_STRING(SS_TAP(X_BSPC)); // Backspace
        }
        break;
    case R_DELR:
        // reaper: cuts selected regions, then deletes the right side
        if (record->event.pressed) {
           SEND_STRING(SS_LSFT(SS_TAP(X_K))); // Shift + K
           SEND_STRING(SS_TAP(X_BSPC));       // Backspace
        }
        break;
    case R_OVERDUB:
        // reaper: set overdub record mode, then record
        if (record->event.pressed) {
           SEND_STRING(SS_TAP(X_F21));        // F21
           SEND_STRING(SS_LCTL(SS_TAP(X_R))); // Ctrl + R
        }
        break;
    case R_RECORD:
        // reaper: set regular record mode, then record
        if (record->event.pressed) {
           SEND_STRING(SS_TAP(X_F20));        // F20
           SEND_STRING(SS_LCTL(SS_TAP(X_R))); // Ctrl + R
        }
        break;
    }
    return true;
};