#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
//#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
//#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

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
    KC_ESCAPE, KC_1,     KC_2,    KC_3,          KC_4,          KC_5,      KC_RALT,              KC_RALT,         KC_6,       KC_7,           KC_8,          KC_9,    KC_0,      KC_ESCAPE,
    KC_TAB,    KC_Q,     KC_W,    KC_E,          KC_R,          KC_T,      LALT_T(KC_EQUAL),     LALT_T(KC_MINUS),KC_Y,       KC_U,           KC_I,          KC_O,    KC_P,      KC_BSLASH,
    KC_GRAVE,  KC_A,     KC_S,    KC_D,          KC_F,          KC_G,                                             KC_H,       KC_J,           KC_K,          KC_L,    KC_SCOLON, KC_QUOTE,
    KC_LSHIFT, KC_Z,     KC_X,    KC_C,          KC_V,          KC_B,      KC_LBRACKET,          KC_RBRACKET,     KC_N,       KC_M,           KC_COMMA,      KC_DOT,  KC_SLASH,  KC_RSHIFT,
    MO(ADMIN), _______,  _______, OSM(MOD_LGUI), OSM(MOD_LCTL),                                                               OSM(MOD_LCTL),  OSM(MOD_LGUI), _______, _______,   MO(ADMIN),
                                                                OSL(FN),   OSL(MOUSE),           _______,         OSL(MEDIA),
                                                                           _______,              _______,
                                                 KC_SPACE,      KC_BSPACE, _______,              _______,         KC_DELETE,  KC_ENTER
  ),
  [FN] = LAYOUT_ergodox_pretty(
    TO(BASE), KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,          _______,         _______, KC_F6,       KC_F7,     KC_F8,   KC_F9,    KC_F10,  TO(BASE),
    _______,  _______, _______, _______, _______,       KC_F11,         KC_F11,          KC_F12,  KC_F12,      _______,   _______, _______,  _______, _______,
    _______,  _______, _______, _______, _______,       _______,                                  KC_LEFT,     KC_DOWN,   KC_UP,   KC_RIGHT, _______, _______,
    _______,  _______, _______, _______, _______,       LCTL(KC_T),     LCTL(KC_R),      _______, KC_HOME,     KC_PGDOWN, KC_PGUP, KC_END,   _______, _______,
    _______,  _______, _______, _______, _______,                                                              _______,   _______, _______,  _______, _______,
                                                        _______,        _______,         _______, _______,
                                                                        _______,         _______,
                                         LALT(KC_LEFT), LALT(KC_RIGHT), LCTL(KC_W),      _______, KC_CAPSLOCK, KC_PSCREEN
  ),
  [MOUSE] = LAYOUT_ergodox_pretty(
    TO(BASE), _______, _______, _______, _______,    _______,    KC_ACL0,      KC_ACL0, _______,    _______,    _______,    _______,     _______, TO(BASE),
    _______,  _______, KC_WH_U, _______, _______,    _______,    KC_ACL1,      KC_ACL1, _______,    _______,    _______,    _______,     _______, _______,
    _______,  KC_WH_L, KC_WH_D, KC_WH_R, _______,    _______,                           KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT, _______, _______,
    _______,  _______, _______, _______, _______,    _______,    KC_ACL2,      KC_ACL2, KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,     _______, _______,
    _______,  _______, _______, _______, KC_MS_BTN3,                                                KC_MS_BTN3, _______,    _______,     _______, _______,
                                                     _______,    _______,      _______, _______,
                                                                 _______,      _______,
                                         KC_MS_BTN1, KC_MS_BTN2, _______,      _______, KC_MS_BTN2, KC_MS_BTN1
  ),
  [MEDIA] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_VOLU, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MUTE,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                 _______, _______,     _______, _______,
                                                                       _______,          _______,
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

