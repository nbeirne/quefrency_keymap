#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum layer {
    _BASE,
    _SPC, // swap space key with backspace

    _MOD, // modifiers
    // EMOJI
    _LAYERS_END, // last layer
};

enum encoders {
  _ENC_L,
  _ENC_R,
};

enum tapdance {
  TD_LAYER,
};

// mac keys

#define MC_LOPT KC_LALT
#define MC_ROPT KC_RALT

#define MC_LCMD KC_LGUI
#define MC_RCMD KC_RGUI


// emoji popup
//#define EMOJI LCMD(LGUI(KC_SPC))
#define EMOJI LCTL(LGUI(KC_SPC))
// spotlight / alphred
#define SPOT LCMD(KC_SPC)
// mute with mutekey
#define MUTE LCTL(S(KC_M))

// brightness up/down for the encoder.
#define BR_UP KC_SLCK
#define BR_DOWN KC_PAUS

// debugger commands
#define D_RES KC_F5
#define D_STP KC_F10


// possible encoder params:
// brightness up/down
// volume up/down     + mute

// possible macros
// emoji popup
// spotlight
// debugger next/resume
// mute mic
// music prev/next
// must play/pause
// do not disturb / focus mode toggle

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
// ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F1,   KC_ESC,     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_MUTE, \
// ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    EMOJI,   SPOT,       KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL, \
// ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    D_RES,   D_STP,      KC_LCTRL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,             KC_PGUP, \
// ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
    KC_MPRV, KC_MNXT,    KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,   KC_PGDN, \
// ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
    MUTE,    KC_MPLY,    MO(_MOD),  KC_LCTRL,   KC_LOPT,   MC_LCMD,    KC_BSPC,                      _______, KC_SPC,       MC_RCMD, KC_ROPT, _______, KC_LEFT, KC_DOWN, KC_RGHT
// └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┘        └────────┴────────┴────────┘
  ),

  [_SPC] = LAYOUT_65_with_macro(
// ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______,    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, \
// ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______, _______,    _______,      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,     _______, \
// ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______, _______,    _______,        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,            _______, \
// ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
    _______, _______,    _______,              _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______, _______, \
// ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
    _______, _______,    _______,   _______,    _______,   _______,    KC_SPC,                       _______, KC_BSPC,      _______, _______, _______, _______, _______, _______
// └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┘        └────────┴────────┴────────┘
  ),

  [_MOD] = LAYOUT_65_with_macro(
// ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______,    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
// ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______, _______,    RGB_TOG,      RGB_MOD, _______, _______, _______, _______,          _______, KC_PGUP, _______, _______, _______, _______, _______, _______,     _______, \
// ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______, _______,    _______,        _______, _______, KC_PGDN, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,            KC_END,  \
// ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
    _______, _______,    _______,              _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      KC_PGUP, KC_HOME, \
// ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
    _______, _______,    _______,   _______,    _______,   _______,    TG(_SPC),                      _______, _______,      _______, _______, _______, KC_HOME, KC_PGDN, KC_END
// └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┘        └────────┴────────┴────────┘
  ),

};


#if defined(ENCODER_MAP_ENABLE)

#define NUMENCODERS 2

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [_BASE] = { ENCODER_CCW_CW(BR_UP,   BR_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_MOD] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(BR_UP,   BR_DOWN) },
};

#endif


//void dance_layer_finished(qk_tap_dance_state_t* state, void* user_data)
//{
//    if (state->count == 1)
//    {
//        layer_on(_FN1);
//    }
//}
//
//void dance_layer_reset(qk_tap_dance_state_t* state, void* user_data)
//{
//    if (state->count == 1)
//    {
//        layer_off(_FN1);
//    }
//    else
//    {
//        uint8_t layer = biton32(layer_state);
//        if (layer == _FN2) {
//            // TODO: set color...
//            layer_off(_FN2);
//        } else {
//            layer_on(_FN2);
//        }
//    }
//}
//
////All tap dance functions would go here. Only showing this one.
//qk_tap_dance_action_t tap_dance_actions[] = {
// [TD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_finished, dance_layer_reset)
//};
