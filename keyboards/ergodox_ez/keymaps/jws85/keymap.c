#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

#define WEB_BCK LALT(KC_LEFT)
#define WEB_FWD LALT(KC_RIGHT)
#define WEB_RLD LALT(KC_R)
#define WEB_NTB LALT(KC_T)
#define WEB_CTB LALT(KC_W)

#define CONTROL KC_LCTL
#define META KC_LALT
#define SUPER KC_LGUI

enum layer_names {
    BASE,
    FN,
    MOUSE,
    MEDIA,
    ADMIN
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE, KC_1,     KC_2,  KC_3,   KC_4,     KC_5,      KC_RALT,      KC_RALT,     KC_6,       KC_7,     KC_8,     KC_9,    KC_0,      KC_ESCAPE,
    KC_TAB,    KC_Q,     KC_W,  KC_E,   KC_R,     KC_T,      KC_EQUAL,     KC_MINUS,    KC_Y,       KC_U,     KC_I,     KC_O,    KC_P,      KC_BSLASH,
    KC_GRAVE,  KC_A,     KC_S,  KC_D,   KC_F,     KC_G,                                 KC_H,       KC_J,     KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
    KC_LSHIFT, KC_Z,     KC_X,  KC_C,   KC_V,     KC_B,      KC_LBRACKET,  KC_RBRACKET, KC_N,       KC_M,     KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSHIFT,
    MO(ADMIN), _______,  META,  SUPER,  CONTROL,                                                    CONTROL,  SUPER,    META,    _______,   MO(ADMIN),
                                                  OSL(FN),   OSL(MOUSE),   _______,     OSL(MEDIA),
                                                             _______,      _______,
                                        KC_SPACE, KC_BSPACE, _______,      _______,     KC_DELETE,  KC_ENTER
  ),
  [FN] = LAYOUT_ergodox_pretty(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,       KC_F7,     KC_F8,   KC_F9,    KC_F10,  _______,
    _______, _______, _______, _______, _______, KC_F11,  KC_F11,       KC_F12,  KC_F12,      _______,   _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,                        KC_LEFT,     KC_DOWN,   KC_UP,   KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, KC_HOME,     KC_PGDOWN, KC_PGUP, KC_END,   _______, _______,
    _______, _______, _______, _______, _______,                                              _______,   _______, _______,  _______, _______,
                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, KC_CAPSLOCK, KC_PSCREEN
  ),
  [MOUSE] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,      KC_ACL0, _______,    _______,    _______,    _______,     _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      KC_ACL1, WEB_CTB,    WEB_BCK,    WEB_FWD,    WEB_NTB,     _______, _______,
    _______, _______, _______, _______, _______, _______,                        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      KC_ACL2, KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,     _______, _______,
    _______, _______, _______, _______, _______,                                             KC_MS_BTN3, _______,    _______,     _______, _______,
                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, KC_MS_BTN2, KC_MS_BTN1
  ),
  [MEDIA] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_VOLU, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MUTE,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                 _______, _______,     _______, _______,
                                                          _______,     _______,
                                        KC_MPLY, KC_MSTP, _______,     _______, _______, _______
  ),
  [ADMIN] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______,     _______, _______, _______, _______, _______, _______, LALT(KC_PSCREEN),
    KC_R,    KC_E,    KC_I,    KC_S,    KC_U,      KC_B,                          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______,
                                                   _______, RESET,       RESET,   _______,
                                                            _______,     _______,
                                        LED_LEVEL, _______, _______,     _______, _______, LED_LEVEL
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

