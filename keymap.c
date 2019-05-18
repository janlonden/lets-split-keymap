#include QMK_KEYBOARD_H
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

enum custom_layers {
  COLEMAK_SOFT = 0,
  COLEMAK_HARD,
  CAPSLOCK_SOFT,
  CAPSLOCK_HARD,
  BROWSER,
  LEFT_LAYERS,
  LEFT_MODS,
  FUNCTION,
  NUMBERS,
  DEVELOPMENT,
  RIGHT_LAYERS,
  RIGHT_MODS
};

enum custom_keycodes {
  _BSPACE = SAFE_RANGE,
  CTRL_BSPACE,
  _DOWN,
  _ENTER,
  _EQUAL,
  _LALT,
  _LCTRL,
  _LEFT,
  _LSHIFT,
  _MINUS,
  _QUOTE,
  _RALT,
  _RIGHT,
  _RSHIFT,
  _SLASH,
  _UP,
  _END,
  _ESCAPE,
  _HOME,
  RALT_Q,
  RALT_O,
  RALT_W,
  RALT_SHIFT_Q,
  RALT_SHIFT_O,
  RALT_SHIFT_W,
  SHIFT__LEFT_LAYERS,
  SHIFT__RIGHT_LAYERS,
  SET_FUNCTION,
  SET_NUMBERS,
  SET_DEVELOPMENT,
  CTRL__LEFT_MODS,
  CTRL__RIGHT_MODS,
  SPACE__BROWSER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_SOFT] = LAYOUT_ortho_4x12(
    SPACE__BROWSER, CM_G, CM_D, CM_B, RALT_O, KC_PSCREEN, _______, _______, KC_COMMA, SHIFT__RIGHT_LAYERS, KC_DOT, _______, \
    CM_Q, CM_W, CM_F, CM_P, RALT_W, DF(COLEMAK_SOFT), _______, _______, CM_L, CM_U, CM_Y, CM_SCLN, \
    CM_A, CM_R, CM_S, CM_T, RALT_Q, DF(COLEMAK_HARD), _______, _______, CM_N, CM_E, CM_I, CM_O, \
    CM_Z, CM_X, CM_C, CM_V, SHIFT__LEFT_LAYERS, TG(CAPSLOCK_SOFT), LCTL(CM_D), KC_SPACE, CM_H, CM_K, CM_M, CM_J \
  ),

  [COLEMAK_HARD] = LAYOUT_ortho_4x12(
    SPACE__BROWSER, KC_G, KC_D, KC_B, XXXXXXX, KC_PSCREEN, _______, _______, KC_COMMA, SHIFT__RIGHT_LAYERS, KC_DOT, _______, \
    KC_Q, KC_W, KC_F, KC_P, XXXXXXX, DF(COLEMAK_SOFT), _______, _______, KC_L, KC_U, KC_Y, KC_SCOLON, \
    KC_A, KC_R, KC_S, KC_T, XXXXXXX, DF(COLEMAK_HARD), _______, _______, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, SHIFT__LEFT_LAYERS, TG(CAPSLOCK_HARD), LCTL(KC_D), KC_SPACE, KC_H, KC_K, KC_M, KC_J \
  ),

  [CAPSLOCK_SOFT] = LAYOUT_ortho_4x12(
    _______, S(CM_G), S(CM_D), S(CM_B), RALT_SHIFT_O, _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), RALT_SHIFT_W, _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), RALT_SHIFT_Q, _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
    S(CM_Z), S(CM_X), S(CM_C), S(CM_V), _______, _______, _______, _______, S(CM_H), S(CM_K), S(CM_M), S(CM_J) \
  ),

  [CAPSLOCK_HARD] = LAYOUT_ortho_4x12(
    _______, S(KC_G), S(KC_D), S(KC_B), _______, _______, _______, _______, _______, _______, _______, _______, \
    S(KC_Q), S(KC_W), S(KC_F), S(KC_P), _______, _______, _______, _______, S(KC_L), S(KC_U), S(KC_Y), _______, \
    S(KC_A), S(KC_R), S(KC_S), S(KC_T), _______, _______, _______, _______, S(KC_N), S(KC_E), S(KC_I), S(KC_O), \
    S(KC_Z), S(KC_X), S(KC_C), S(KC_V), _______, _______, _______, _______, S(KC_H), S(KC_K), S(KC_M), S(KC_J) \
  ),

  [LEFT_LAYERS] = LAYOUT_ortho_4x12(
    _______, _ENTER, CTRL__LEFT_MODS, _ESCAPE, _______, RESET, _______, _______, _______, _______, _______, _______, \
    _______, _HOME, _UP, _END, _______, _______, _______, _______, _______, _______, _______, _______, \
    SET_FUNCTION, _LEFT, _DOWN, _RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, \
    SET_NUMBERS, SET_DEVELOPMENT, CTRL_BSPACE, _BSPACE, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [LEFT_MODS] = LAYOUT_ortho_4x12(
    _______, _______, CTRL__LEFT_MODS, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _LSHIFT, _______, _LCTRL, _______, _______, _______, _______, _______, _______, _______, _______, \
    _LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _RALT, _______, _______, _______, _______, _______, _______ \
  ),

  [RIGHT_LAYERS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _SLASH, _______, _EQUAL, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _QUOTE, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _MINUS, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, CTRL__RIGHT_MODS, _______, _______, _______, _______ \
  ),

  [RIGHT_MODS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _LCTRL, _RALT, _RSHIFT, _LALT, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, CTRL__RIGHT_MODS, _______, _______, _______, _______ \
  ),

  [FUNCTION] = LAYOUT_ortho_4x12(
    _______, KC_PGUP, KC_DEL, KC_PGDOWN, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, LCTL(KC_PGUP), KC_TAB, LCTL(KC_PGDOWN), _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    SET_FUNCTION, KC_LSHIFT, KC_LALT, KC_LCTRL, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, _______, _______, KC_BTN3, _______, KC_RALT, _______, _______, KC_F1, KC_F2, KC_F3, _______ \
  ),

  [NUMBERS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, _______, KC_LALT, KC_TAB, _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_BSPACE, \
    SET_NUMBERS, KC_LSHIFT, KC_LALT, KC_LCTRL, _______, KC_RALT, _______, _______, KC_0, KC_DOT, _______, KC_ENTER \
  ),

  [DEVELOPMENT] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_EXCLAIM, _______, \
    _______, _______, LCTL(CM_S), _______, _______, _______, _______, _______, S(KC_LBRACKET), S(KC_RBRACKET), S(KC_BSLASH), _______, \
    _______, SET_DEVELOPMENT, _______, _______, _______, _______, _______, _______, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, _______ \
  ),

  [BROWSER] = LAYOUT_ortho_4x12(
    _______, S(KC_SPACE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(KC_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
  )
};

static uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RALT_O:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("p"));
      }
      return false;
    case RALT_Q:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("q"));
      }
      return false;
    case RALT_W:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("w"));
      }
      return false;
    case RALT_SHIFT_O:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("p")));
      }
      return false;
    case RALT_SHIFT_Q:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("q")));
      }
      return false;
    case RALT_SHIFT_W:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("w")));
      }
      return false;
    case _ENTER:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_ENTER);
      } else {
        unregister_code(KC_ENTER);
      }
      return false;
    case SHIFT__LEFT_LAYERS:
      if (record->event.pressed) {
        layer_on(LEFT_LAYERS);
        register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
        layer_off(LEFT_LAYERS);
      }
      return false;
    case SHIFT__RIGHT_LAYERS:
      if (record->event.pressed) {
        layer_on(RIGHT_LAYERS);
        register_code(KC_RSHIFT);
      } else {
        unregister_code(KC_RSHIFT);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case SET_FUNCTION:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        layer_on(FUNCTION);
      } else {
        layer_off(FUNCTION);
      }
      return false;
    case SET_NUMBERS:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        layer_on(NUMBERS);
      } else {
        layer_off(NUMBERS);
      }
      return false;
    case SET_DEVELOPMENT:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        layer_on(DEVELOPMENT);
      } else {
        layer_off(DEVELOPMENT);
      }
      return false;
    case CTRL__LEFT_MODS:
      if (record->event.pressed) {
        layer_on(LEFT_MODS);
        register_code(KC_LCTRL);
      } else {
        unregister_code(KC_LCTRL);
        layer_off(LEFT_MODS);
      }
      return false;
    case CTRL__RIGHT_MODS:
      if (record->event.pressed) {
        layer_on(RIGHT_MODS);
        register_code(KC_LCTRL);
      } else {
        unregister_code(KC_LCTRL);
        layer_off(RIGHT_MODS);
      }
      return false;
    case _UP:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_UP);
      } else {
        unregister_code(KC_UP);
      }
      return false;
    case _LEFT:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
      }
      return false;
    case _DOWN:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_DOWN);
      } else {
        unregister_code(KC_DOWN);
      }
      return false;
    case _RIGHT:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_RIGHT);
      } else {
        unregister_code(KC_RIGHT);
      }
      return false;
    case _HOME:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_HOME);
      } else {
        unregister_code(KC_HOME);
      }
      return false;
    case _END:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_END);
      } else {
        unregister_code(KC_END);
      }
      return false;
    case _ESCAPE:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_ESCAPE);
      } else {
        unregister_code(KC_ESCAPE);
      }
      return false;
    case _SLASH:
      if (record->event.pressed) {
        unregister_code(KC_RSHIFT);
        register_code(KC_SLASH);
      } else {
        unregister_code(KC_SLASH);
      }
      return false;
    case _QUOTE:
      if (record->event.pressed) {
        unregister_code(KC_RSHIFT);
        register_code(KC_QUOTE);
      } else {
        unregister_code(KC_QUOTE);
      }
      return false;
    case _MINUS:
      if (record->event.pressed) {
        unregister_code(KC_RSHIFT);
        register_code(KC_MINUS);
      } else {
        unregister_code(KC_MINUS);
      }
      return false;
    case _EQUAL:
      if (record->event.pressed) {
        unregister_code(KC_RSHIFT);
        register_code(KC_EQUAL);
      } else {
        unregister_code(KC_EQUAL);
      }
      return false;
    case _BSPACE:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_BSPACE);
      } else {
        unregister_code(KC_BSPACE);
      }
      return false;
    case CTRL_BSPACE:
      if (record->event.pressed) {
        unregister_code(KC_LSHIFT);
        register_code(KC_LCTRL);
        register_code(KC_BSPACE);
      } else {
        unregister_code(KC_BSPACE);
        unregister_code(KC_LCTRL);
      }
      return false;
    case _RALT:
      if (record->event.pressed) {
        unregister_code(KC_LCTRL);
        register_code(KC_RALT);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
    case _LALT:
      if (record->event.pressed) {
        unregister_code(KC_LCTRL);
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
    case _LSHIFT:
      if (record->event.pressed) {
        unregister_code(KC_LCTRL);
        register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
      }
      return false;
    case _RSHIFT:
      if (record->event.pressed) {
        unregister_code(KC_LCTRL);
        register_code(KC_RSHIFT);
      } else {
        unregister_code(KC_RSHIFT);
      }
      return false;
    case _LCTRL:
      if (record->event.pressed) {
        unregister_code(KC_LCTRL);
        register_code(KC_LCTRL);
      } else {
        unregister_code(KC_LCTRL);
      }
      return false;
    case SPACE__BROWSER:
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(BROWSER);
      } else {
        if (timer_elapsed(key_timer) < 150) {
          register_code(KC_SPACE);
          unregister_code(KC_SPACE);
        }
        layer_off(BROWSER);
      }
      return false;
  }
  return true;
};
