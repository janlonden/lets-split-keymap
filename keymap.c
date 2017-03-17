#include "lets_split.h"
#include "keymap_colemak.h"
#include "eeconfig.h"

#define QUICK 125
#define NORMAL 150
#define SLOW 300

enum layers {
  COLEMAK,
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
  END__S__R,
  ENT__T__N,
  ESC__D__ALT_F3,
  HOME__W,
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
  SPC__BROWSER,
  VOLDOWN__GUI_LEFT,
  VOLUP__GUI_RIGHT,
  END_SFT_HOME_DEL
};

#define _______ KC_TRNS

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = KEYMAP( \
    M(SPC__BROWSER), CM_G, CM_D, CM_B, M(RALT_SCLN), RESET, M(LOGIN), _______, CM_COMM, M(SFT__RIGHT_LAYERS), CM_DOT, TG(NUMBERS), \
    CM_Q, CM_W, CM_F, CM_P, M(RALT_W), _______, _______, _______, CM_L, CM_U, CM_Y, CM_SCLN, \
    CM_A, CM_R, CM_S, CM_T, M(RALT_Q), _______, _______, _______, CM_N, CM_E, CM_I, CM_O, \
    CM_Z, CM_X, CM_C, CM_V, M(SFT__LEFT_LAYERS), TG(CAPSLOCK), M(END_SFT_HOME_DEL), KC_SPC, CM_H, CM_K, CM_M, CM_J \
  ),

  [CAPSLOCK] = KEYMAP( \
    _______, S(CM_G), S(CM_D), S(CM_B), M(RALT_SFT_SCLN), _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), M(RALT_SFT_W), _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), M(RALT_SFT_Q), _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
    S(CM_Z), S(CM_X), S(CM_C), S(CM_V), _______, _______, _______, _______, S(CM_H), S(CM_K), S(CM_M), S(CM_J) \
  ),

  [LEFT_LAYERS] = KEYMAP( \
    _______, M(ENT__T__N), M(CTL__LEFT_MODS), M(ESC__D__ALT_F3), _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(HOME__W), M(_UP), M(END__S__R), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_FUNCTION), M(_LEFT), M(_DOWN), M(_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_NUMBERS), M(SET_DEVELOPMENT), _______, M(_BSPC), _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [LEFT_MODS] = KEYMAP( \
    _______, _______, M(CTL__LEFT_MODS), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(_LSFT), _______, M(_LCTL), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(_LALT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, M(_RALT), _______, _______, _______, _______, _______, _______ \
  ),

  [RIGHT_LAYERS] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_SLSH), _______, M(_EQL), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_QUOT), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_MINS), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(CTL__RIGHT_MODS), _______, _______, _______, _______ \
  ),

  [RIGHT_MODS] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_LCTL), M(_RALT), M(_RSFT), M(_LALT), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(CTL__RIGHT_MODS), _______, _______, _______, _______ \
  ),

  [FUNCTION] = KEYMAP( \
    _______, _______, KC_TAB, KC_DEL, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, LCTL(KC_PGUP), LCTL(KC_UP), LCTL(KC_PGDOWN), _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    M(SET_FUNCTION), LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, _______, _______, KC_BTN3, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, _______ \
  ),

  [NUMBERS] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, _______, KC_LEFT, M(ALT_TAB), _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, M(VOLDOWN__GUI_LEFT), KC__MUTE, M(VOLUP__GUI_RIGHT), _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_BSPC, \
    M(SET_NUMBERS), LCTL(CM_Z), LCTL(S(CM_Z)), KC_LSFT, _______, _______, _______, _______, KC_0, KC_DOT, _______, KC_ENT \
  ),

  [DEVELOPMENT] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_GRV, KC_PGDOWN, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, S(KC_1), _______, \
    _______, _______, LCTL(CM_C), LCTL(CM_V), _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______, \
    _______, M(SET_DEVELOPMENT), LCTL(CM_X), LCTL(KC_BSPC), _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ \
  ),

  [BROWSER] = KEYMAP( \
    _______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(CM_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
  )
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case RALT_SCLN: {
      if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(CM_SCLN);
        unregister_code(CM_SCLN);
        unregister_code(KC_RALT);
        unregister_code(CM_SCLN);
      }
      break;
    }
    case RALT_Q: {
      if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(CM_Q);
        unregister_code(CM_Q);
        unregister_code(KC_RALT);
        unregister_code(CM_Q);
      }
      break;
    }
    case RALT_W: {
      if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(CM_W);
        unregister_code(CM_W);
        unregister_code(KC_RALT);
        unregister_code(CM_W);
      }
      break;
    }
    case RALT_SFT_SCLN: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_SCLN);
        unregister_code(CM_SCLN);
        unregister_code(KC_LSFT);
        unregister_code(KC_RALT);
      }
      break;
    }
    case RALT_SFT_Q: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_Q);
        unregister_code(CM_Q);
        unregister_code(KC_LSFT);
        unregister_code(KC_RALT);
      }
      break;
    }
    case RALT_SFT_W: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_W);
        unregister_code(CM_W);
        unregister_code(KC_LSFT);
        unregister_code(KC_RALT);
      }
      break;
    }
    case LOGIN: {
      if (record->event.pressed) {
        register_code(CM_A);
        unregister_code(CM_A);
        register_code(CM_R);
        unregister_code(CM_R);
        register_code(CM_S);
        unregister_code(CM_S);
        register_code(CM_T);
        unregister_code(CM_T);
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
      break;
    }
    case ENT__T__N: {
      if (record->event.pressed) {
        key_timer = timer_read();
        unregister_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_T);
          unregister_code(CM_T);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_N);
          unregister_code(CM_N);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case SFT__LEFT_LAYERS: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(LEFT_LAYERS);
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        layer_off(LEFT_LAYERS);
      }
      break;
    }
    case SFT__RIGHT_LAYERS: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(RIGHT_LAYERS);
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
        layer_off(RIGHT_LAYERS);
      }
      break;
    }
    case SET_FUNCTION: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(FUNCTION);
      } else {
        layer_off(FUNCTION);
      }
      break;
    }
    case SET_NUMBERS: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(NUMBERS);
      } else {
        layer_off(NUMBERS);
      }
      break;
    }
    case SET_DEVELOPMENT: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(DEVELOPMENT);
      } else {
        layer_off(DEVELOPMENT);
      }
      break;
    }
    case CTL__LEFT_MODS: {
      if (record->event.pressed) {
        layer_on(LEFT_MODS);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        layer_off(LEFT_MODS);
      }
      break;
    }
    case CTL__RIGHT_MODS: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(RIGHT_MODS);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        layer_off(RIGHT_MODS);
      }
      break;
    }
    case _UP: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_UP);
      } else {
        unregister_code(KC_UP);
      }
      break;
    }
    case _LEFT: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
      }
      break;
    }
    case _DOWN: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_DOWN);
      } else {
        unregister_code(KC_DOWN);
      }
      break;
    }
    case _RIGHT: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_RIGHT);
      } else {
        unregister_code(KC_RIGHT);
      }
      break;
    }
    case HOME__W: {
      if (record->event.pressed) {
        key_timer = timer_read();
        unregister_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_HOME);
          unregister_code(KC_HOME);
        } else {
          register_code(KC_LCTL);
          register_code(CM_W);
          unregister_code(CM_W);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case END__S__R: {
      if (record->event.pressed) {
        key_timer = timer_read();
        unregister_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_END);
          unregister_code(KC_END);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_S);
          unregister_code(CM_S);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_R);
          unregister_code(CM_R);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case ESC__D__ALT_F3: {
      if (record->event.pressed) {
        key_timer = timer_read();
        unregister_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LALT);
          register_code(KC_F3);
          unregister_code(KC_F3);
          unregister_code(KC_LALT);
        }
      }
      break;
    }
    case ALT_TAB: {
      if (record->event.pressed) {
        return MACRO(D(LALT), D(TAB), U(TAB), END);
      }
      break;
    }
    case VOLDOWN__GUI_LEFT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC__VOLDOWN);
          unregister_code(KC__VOLDOWN);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
          unregister_code(KC_LGUI);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case VOLUP__GUI_RIGHT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC__VOLUP);
          unregister_code(KC__VOLUP);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_RIGHT);
          unregister_code(KC_RIGHT);
          unregister_code(KC_LGUI);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case _SLSH: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_SLSH);
      } else {
        unregister_code(KC_SLSH);
      }
      break;
    }
    case _QUOT: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_QUOT);
      } else {
        unregister_code(KC_QUOT);
      }
      break;
    }
    case _MINS: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_MINS);
      } else {
        unregister_code(KC_MINS);
      }
      break;
    }
    case _EQL: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_EQL);
      } else {
        unregister_code(KC_EQL);
      }
      break;
    }
    case _BSPC: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_BSPC);
      }
      break;
    }
    case _RALT: {
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_RALT);
      } else {
        unregister_code(KC_RALT);
      }
      break;
    }
    case _LALT: {
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      break;
    }
    case _LSFT: {
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
      }
      break;
    }
    case _RSFT: {
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
    }
    case _LCTL: {
      if (record->event.pressed) {
        unregister_code(KC_LCTL);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
      }
      break;
    }
    case _ENT: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
      }
      break;
    }
    case SPC__BROWSER: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(BROWSER);
      } else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        layer_off(BROWSER);
      }
      break;
    }
    case END_SFT_HOME_DEL: {
      if (record->event.pressed) {
        register_code(KC_END);
        unregister_code(KC_END);
        register_code(KC_LSFT);
        register_code(KC_HOME);
        unregister_code(KC_HOME);
        unregister_code(KC_LSFT);
        register_code(KC_DEL);
        unregister_code(KC_DEL);
      }
      break;
    }
  }
  return MACRO_NONE;
};
