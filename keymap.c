#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

enum layers {
  COLEMAK_SOFT,
  COLEMAK_HARD,
  CAPSLOCK,
  LEFT_LAYERS,
  RIGHT_LAYERS,
  FUNCTION,
  NUMBERS,
  DEVELOPMENT,
  LEFT_MODS,
  RIGHT_MODS,
  BROWSER
};

enum macros {
  _BSPC,
  CTL_BSPC,
  _DOWN,
  _ENT,
  _EQL,
  _LALT,
  _LCTL,
  _LEFT,
  _LSFT,
  _MINS,
  _QUOT,
  _RALT,
  _RIGHT,
  _RSFT,
  _SLSH,
  _UP,
  ALT_TAB,
  _END,
  _ESC,
  _HOME,
  LOGIN,
  RALT_Q,
  RALT_SCLN,
  RALT_W,
  RALT_SFT_Q,
  RALT_SFT_SCLN,
  RALT_SFT_W,
  SFT__LEFT_LAYERS,
  SFT__RIGHT_LAYERS,
  SET_FUNCTION,
  SET_NUMBERS,
  SET_DEVELOPMENT,
  CTL__LEFT_MODS,
  CTL__RIGHT_MODS,
  SFT__SPC,
  SPC__BROWSER
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_SOFT] = LAYOUT(
    M(SPC__BROWSER), CM_G, CM_D, CM_B, M(RALT_SCLN), RESET, M(LOGIN), _______, CM_COMM, M(SFT__RIGHT_LAYERS), CM_DOT, TG(NUMBERS), \
    CM_Q, CM_W, CM_F, CM_P, M(RALT_W), DF(COLEMAK_SOFT), _______, _______, CM_L, CM_U, CM_Y, CM_SCLN, \
    CM_A, CM_R, CM_S, CM_T, M(RALT_Q), DF(COLEMAK_HARD), _______, _______, CM_N, CM_E, CM_I, CM_O, \
    CM_Z, CM_X, CM_C, CM_V, M(SFT__LEFT_LAYERS), TG(CAPSLOCK_SOFT), _______, KC_SPC, CM_H, CM_K, CM_M, CM_J \
  ),

  [COLEMAK_HARD] = LAYOUT(
    M(SPC__BROWSER), KC_G, KC_D, KC_B, XXXXXXX, RESET, M(LOGIN), _______, KC_COMM, M(SFT__RIGHT_LAYERS), KC_DOT, TG(NUMBERS), \
    KC_Q, KC_W, KC_F, KC_P, XXXXXXX, DF(COLEMAK_SOFT), _______, _______, KC_L, KC_U, KC_Y, KC_SCLN, \
    KC_A, KC_R, KC_S, KC_T, XXXXXXX, DF(COLEMAK_HARD), _______, _______, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, M(SFT__LEFT_LAYERS), TG(CAPSLOCK_HARD), _______, KC_SPC, KC_H, KC_K, KC_M, KC_J \
  ),

  [CAPSLOCK_SOFT] = LAYOUT(
    _______, S(CM_G), S(CM_D), S(CM_B), M(RALT_SFT_SCLN), _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), M(RALT_SFT_W), _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), M(RALT_SFT_Q), _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
    S(CM_Z), S(CM_X), S(CM_C), S(CM_V), _______, _______, _______, _______, S(CM_H), S(CM_K), S(CM_M), S(CM_J) \
  ),

  [CAPSLOCK_HARD] = LAYOUT(
    _______, S(KC_G), S(KC_D), S(KC_B), M(RALT_SFT_SCLN), _______, _______, _______, _______, _______, _______, _______, \
    S(KC_Q), S(KC_W), S(KC_F), S(KC_P), M(RALT_SFT_W), _______, _______, _______, S(KC_L), S(KC_U), S(KC_Y), _______, \
    S(KC_A), S(KC_R), S(KC_S), S(KC_T), M(RALT_SFT_Q), _______, _______, _______, S(KC_N), S(KC_E), S(KC_I), S(KC_O), \
    S(KC_Z), S(KC_X), S(KC_C), S(KC_V), _______, _______, _______, _______, S(KC_H), S(KC_K), S(KC_M), S(KC_J) \
  ),

  [LEFT_LAYERS] = LAYOUT(
    _______, M(_ENT), M(CTL__LEFT_MODS), M(_ESC), _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(_HOME), M(_UP), M(_END), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_FUNCTION), M(_LEFT), M(_DOWN), M(_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_NUMBERS), M(SET_DEVELOPMENT), M(CTL_BSPC), M(_BSPC), _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [LEFT_MODS] = LAYOUT(
    _______, _______, M(CTL__LEFT_MODS), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(_LSFT), _______, M(_LCTL), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(_LALT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, M(_RALT), _______, _______, _______, _______, _______, _______ \
  ),

  [RIGHT_LAYERS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, M(_SLSH), _______, M(_EQL), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_QUOT), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_MINS), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(CTL__RIGHT_MODS), _______, _______, _______, _______ \
  ),

  [RIGHT_MODS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_LCTL), M(_RALT), M(_RSFT), M(_LALT), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(CTL__RIGHT_MODS), _______, _______, _______, _______ \
  ),

  [FUNCTION] = LAYOUT(
    _______, KC_PGUP, KC_DEL, KC_PGDOWN, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, LCTL(KC_PGUP), KC_TAB, LCTL(KC_PGDOWN), _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    M(SET_FUNCTION), KC_LSFT, KC_LALT, KC_LCTL, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, _______, _______, KC_BTN3, _______, KC_RALT, _______, _______, KC_F1, KC_F2, KC_F3, _______ \
  ),

  [NUMBERS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, _______, KC_LEFT, M(ALT_TAB), _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, LCTL(CM_X), LCTL(CM_C), LCTL(CM_V), _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_BSPC, \
    M(SET_NUMBERS), KC_LSFT, KC_LALT, KC_LCTL, _______, KC_RALT, _______, _______, KC_0, KC_DOT, _______, KC_ENT \
  ),

  [DEVELOPMENT] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, S(KC_1), _______, \
    _______, _______, LCTL(CM_S), _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______, \
    _______, M(SET_DEVELOPMENT), _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ \
  ),

  [BROWSER] = LAYOUT(
    _______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(CM_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
  )
};

const uint16_t PROGMEM fn_actions[] = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RALT_SCLN:
      SEND_STRING(SS_RALT(";"));
      return false;
    case RALT_Q:
      SEND_STRING(SS_RALT("q"));
      return false;
    case RALT_W:
      SEND_STRING(SS_RALT("w"));
      return false;
    case RALT_SFT_SCLN:
      SEND_STRING(SS_LSFT(SS_RALT(";")));
      return false;
    case RALT_SFT_Q:
      SEND_STRING(SS_LSFT(SS_RALT("q")));
      return false;
    case RALT_SFT_W:
      SEND_STRING(SS_LSFT(SS_RALT("w")));
      return false;
    case LOGIN:
      SEND_STRING("arst"SS_TAP(X_ENTER));
      return false;
    case _ENT:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
      }
      return false;
    case SFT__LEFT_LAYERS:
      if (record->event.pressed) {
        layer_on(LEFT_LAYERS);
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        layer_off(LEFT_LAYERS);
      }
      return false;
    case SFT__RIGHT_LAYERS:
      if (record->event.pressed) {
        layer_on(RIGHT_LAYERS);
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case SET_FUNCTION:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(FUNCTION);
      } else {
        clear_mods();
        layer_off(FUNCTION);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case SET_NUMBERS:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(NUMBERS);
      } else {
        clear_mods();
        layer_off(NUMBERS);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case SET_DEVELOPMENT:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(DEVELOPMENT);
      } else {
        clear_mods();
        layer_off(DEVELOPMENT);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case CTL__LEFT_MODS:
      if (record->event.pressed) {
        layer_on(LEFT_MODS);
        register_code(KC_LCTL);
      } else {
        clear_mods();
        layer_off(LEFT_MODS);
        layer_off(RIGHT_LAYERS);
      }
      return false;
    case CTL__RIGHT_MODS:
      if (record->event.pressed) {
        layer_on(RIGHT_MODS);
        register_code(KC_LCTL);
      } else {
        clear_mods();
        layer_off(RIGHT_MODS);
        layer_off(LEFT_LAYERS);
      }
      return false;
    case _UP:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_UP);
      } else {
        unregister_code(KC_UP);
      }
      return false;
    case _LEFT:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
      }
      return false;
    case _DOWN:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_DOWN);
      } else {
        unregister_code(KC_DOWN);
      }
      return false;
    case _RIGHT:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_RIGHT);
      } else {
        unregister_code(KC_RIGHT);
      }
      return false;
    case _HOME:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_HOME);
      } else {
        unregister_code(KC_HOME);
      }
      return false;
    case _END:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_END);
      } else {
        unregister_code(KC_END);
      }
      return false;
    case _ESC:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_ESC);
      } else {
        unregister_code(KC_ESC);
      }
      return false;
    case ALT_TAB:
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_TAB));
      return false;
    case _SLSH:
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_SLSH);
      } else {
        unregister_code(KC_SLSH);
      }
      return false;
    case _QUOT:
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_QUOT);
      } else {
        unregister_code(KC_QUOT);
      }
      return false;
    case _MINS:
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_MINS);
      } else {
        unregister_code(KC_MINS);
      }
      return false;
    case _EQL:
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_EQL);
      } else {
        unregister_code(KC_EQL);
      }
      return false;
    case _BSPC:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_BSPC);
      }
      return false;
    case CTL_BSPC:
      SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_BSPACE)SS_UP(X_LCTRL));
      return false;
    case _RALT:
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_RALT);
      } else {
        unregister_code(KC_RALT);
      }
      return false;
    case _LALT:
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
    case _LSFT:
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
      }
      return false;
    case _RSFT:
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
    case _LCTL:
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
      }
      return false;
    case SPC__BROWSER:
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(BROWSER);
      } else {
        if (timer_elapsed(key_timer) < 125) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        clear_mods();
        layer_off(BROWSER);
      }
      return false;
  }
  return true;
};