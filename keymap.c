#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum layer {
    _BASE,
    _FN1,
    // EMOJI
    _LAYERS_END, // last layer
};

enum encoders {
  _ENC_L,
  _ENC_R,
};


// mac keys
#define MC_LOPT KC_LALT
#define MC_ROPT KC_RALT

#define MC_LCMD KC_LGUI
#define MC_RCMD KC_RGUI

#define MUTE LGUI(S(KC_W))
#define XC_B LGUI(KC_B)
#define XC_R LGUI(KC_R)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
// ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F1,   KC_ESC,     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_MUTE, \
// ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    KC_F2,   KC_F3,      KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL, \
// ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    KC_F4,   KC_F5,      KC_LCTRL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,             KC_PGUP, \
// ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
    MUTE,    KC_F8,      KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,   KC_PGDN, \
// ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
    XC_B,    XC_R,       MO(_FN1),  KC_LCTRL,   KC_LOPT,   MC_LCMD,    KC_BSPC,                      _______, KC_SPC,       MC_RCMD, KC_ROPT, _______, KC_LEFT, KC_DOWN, KC_RGHT
// └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┘        └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT_65_with_macro(
// ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______,    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
// ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______, _______,    RGB_TOG,      RGB_MOD, _______, _______, _______, _______,          _______, KC_PGUP, _______, _______, _______, _______, _______, _______,     _______, \
// ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______, _______,    _______,        _______, _______, KC_PGDN, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,            KC_END,  \
// ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
    _______, _______,    _______,              _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______, KC_HOME, \
// ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
    _______, _______,    _______,   _______,    _______,   _______,    _______,                      _______, _______,      _______, _______, _______, _______, _______, _______
// └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┘        └────────┴────────┴────────┘
  )
};

const uint16_t encodermaps[][2][2] = {
  [_BASE] = {
    [_ENC_L] = { KC_UP,   KC_DOWN },
    [_ENC_R] = { KC_VOLD, KC_VOLU },
  },
  [_FN1] = {
    [_ENC_L] = { KC_PGUP, KC_PGDN },
    [_ENC_R] = { KC_VOLD, KC_VOLU },
  },
            // CCW,     CW
};

void encoder_update_user(uint8_t index, bool clockwise) {
  for (int l = 0; l < _LAYERS_END; l++) {
    if (layer_state_is(l)) {
      uint16_t code = encodermaps[l][index][clockwise];
      tap_code(code);
      return;
    }
  }
}
