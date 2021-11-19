#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

enum layer_names {
    LAYER_BASE,
    LAYER_FUNC,
    LAYER_MOUSE,
    LAYER_MEDIA
};

#define LED_LVL LED_LEVEL

#define WEB_BCK LALT(KC_LEFT)
#define WEB_FWD LALT(KC_RIGHT)
#define WEB_RLD LALT(KC_R)
#define WEB_NTB LALT(KC_T)
#define WEB_CTB LALT(KC_W)

#define SPC_FUN LT(LAYER_FUNC, KC_SPC)
#define BCK_MOU LT(LAYER_MOUSE, KC_BSPC)
#define MO_MEDA MO(LAYER_MEDIA)

#define MOD_CTL OSM(MOD_LCTL)
#define MOD_ALT OSM(MOD_LALT)
#define MOD_WIN OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,     KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, MOD_ALT, MOD_WIN, MOD_CTL,                                        MOD_CTL, MOD_WIN, MOD_ALT, _______, _______,
                                                 _______, _______,    _______, _______,
                                                          _______,    _______,
                                        SPC_FUN, BCK_MOU, _______,    _______, KC_DEL,  KC_ENTER
  ),
  [LAYER_FUNC] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ESC,
    _______, _______, _______, _______, _______, KC_F11,  KC_F11,     KC_F12,  KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    RESET,   LED_LVL,
                                                          _______,    _______,
                                        _______, MO_MEDA, _______,    _______, KC_CAPS, KC_PSCREEN
  ),
  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    KC_ESC,  _______, _______, _______, _______, _______, _______,    KC_ACL0, _______, _______, _______, _______, _______, KC_ESC,
    _______, _______, _______, _______, _______, _______, _______,    KC_ACL1, WEB_CTB, WEB_BCK, WEB_FWD, WEB_NTB, _______, _______,
    _______, _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_ACL2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
    _______, _______, _______, _______, _______,                                        KC_BTN3, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                                          _______,    _______,
                                        MO_MEDA, _______, _______,    _______, KC_BTN2, KC_BTN1
  ),
  [LAYER_MEDIA] = LAYOUT_ergodox_pretty(
    KC_ESC,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, KC_ESC,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                        KC_MUTE, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                                          _______,    _______,
                                        _______, _______, _______,    _______, KC_MSTP, KC_MPLY
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

