#include "lets_split.h"
#include "keymap_colemak.h"
#include "eeconfig.h"

#define QUICK 125
#define NORMAL 150
#define SLOW 300

enum layers {
  COLEMAK,
  CAPSLOCK,
  LAYER0,
  LAYER1,
  LAYER2,
  LAYER3,
  LAYER4,
  LAYER5,
  LAYER6,
  LAYER7,
  LAYER8,
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
  SET_LAYER1,
  SET_LAYER2,
  SET_LAYER3,
  SET_LAYER4,
  SET_LAYER5,
  SET_LAYER6,
  SET_LAYER7,
  SPC_LAYER8,
  SFT__LAYER0,
  SFT__SPC,
  SPC__BROWSER,
  VOLDOWN__GUI_LEFT,
  VOLUP__GUI_RIGHT,
  _G,
  _D,
  _B,
  _Q,
  _W,
  _F,
  _P,
  _A,
  _R,
  _S,
  _T,
  _Z,
  _X,
  _C,
  _V,
  _COMM,
  _DOT,
  _L,
  _U,
  _Y,
  _SCLN,
  _N,
  _E,
  _I,
  _O,
  _H,
  _K,
  _M,
  _J
};

#define _______ KC_TRNS

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = KEYMAP( \
    M(SPC__BROWSER), M(_G), M(_D), M(_B), M(RALT_SCLN), _______, _______, _______, M(_COMM), M(SET_LAYER1), M(_DOT), _______, \
    M(_Q), M(_W), M(_F), M(_P), M(RALT_W), _______, _______, _______, M(_L), M(_U), M(_Y), M(_SCLN), \
    M(_A), M(_R), M(_S), M(_T), M(RALT_Q), RESET, M(LOGIN), _______, M(_N), M(_E), M(_I), M(_O), \
    M(_Z), M(_X), M(_C), M(_V), M(SFT__LAYER0), TG(CAPSLOCK), TG(LAYER3), KC_SPC, M(_H), M(_K), M(_M), M(_J) \
  ),

  [CAPSLOCK] = KEYMAP( \
    _______, S(CM_G), S(CM_D), S(CM_B), M(RALT_SFT_SCLN), _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), M(RALT_SFT_W), _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), M(RALT_SFT_Q), _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
    S(CM_Z), S(CM_X), S(CM_C), S(CM_V), _______, _______, _______, _______, S(CM_H), S(CM_K), S(CM_M), S(CM_J) \
  ),

  [LAYER0] = KEYMAP( \
    _______, M(ENT__T__N), M(SET_LAYER7), M(ESC__D__ALT_F3), _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(HOME__W), M(_UP), M(END__S__R), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_LAYER2), M(_LEFT), M(_DOWN), M(_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_LAYER3), M(SET_LAYER5), _______, M(_BSPC), M(SFT__LAYER0), _______, _______, _______, _______, _______, _______, _______ \
  ),

  [LAYER7] = KEYMAP( \
    _______, _______, M(SET_LAYER7), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, M(_LSFT), _______, M(_LCTL), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(_LALT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, M(SFT__LAYER0), M(_RALT), _______, _______, _______, _______, _______, _______ \
  ),

  [LAYER1] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_SLSH), M(SET_LAYER1), M(_EQL), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_QUOT), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_MINS), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(SPC_LAYER8), _______, _______, _______, _______ \
  ),

  [LAYER8] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, M(SET_LAYER1), _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, M(_LCTL), M(_RALT), M(_RSFT), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M(_LALT), \
    _______, _______, _______, _______, _______, _______, _______, M(SPC_LAYER8), _______, _______, _______, _______ \
  ),

  [LAYER2] = KEYMAP( \
    _______, _______, KC_TAB, KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(KC_PGUP), LCTL(KC_UP), LCTL(KC_PGDOWN), _______, _______, _______, _______, _______, _______, _______, _______, \
    M(SET_LAYER2), LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_BTN3, M(SFT__LAYER0), _______, _______, _______, _______, _______, _______, _______ \
  ),

  [LAYER3] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, _______, KC_LEFT, M(ALT_TAB), _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, M(VOLDOWN__GUI_LEFT), KC__MUTE, M(VOLUP__GUI_RIGHT), _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_BSPC, \
    M(SET_LAYER3), LCTL(CM_Z), LCTL(S(CM_Z)), KC_LSFT, M(SFT__LAYER0), _______, _______, M(SET_LAYER6), KC_0, KC_DOT, _______, KC_ENT \
  ),

  [LAYER6] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, _______, _______, _______, _______, _______, _______, M(SET_LAYER6), KC_F1, KC_F2, KC_F3, _______ \
  ),

  [LAYER5] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, S(KC_1), _______, \
    _______, _______, LCTL(CM_C), LCTL(CM_V), _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______, \
    _______, M(SET_LAYER5), LCTL(CM_X), LCTL(KC_BSPC), _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ \
  ),

  [BROWSER] = KEYMAP( \
    M(SPC__BROWSER), S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
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
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      }
      break;
    }
    case RALT_Q: {
      if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(CM_Q);
        unregister_code(CM_Q);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      }
      break;
    }
    case RALT_W: {
      if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(CM_W);
        unregister_code(CM_W);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      }
      break;
    }
    case RALT_SFT_SCLN: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_SCLN);
        unregister_code(CM_SCLN);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
      }
      break;
    }
    case RALT_SFT_Q: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_Q);
        unregister_code(CM_Q);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
      }
      break;
    }
    case RALT_SFT_W: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(CM_W);
        unregister_code(CM_W);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
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
    case SFT__LAYER0: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(LAYER0);
        register_code(KC_LSFT);
      } else {
        layer_off(LAYER0);
        unregister_code(KC_RSFT);
        if (timer_elapsed(key_timer) > NORMAL) {
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case SET_LAYER1: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(LAYER1);
        register_code(KC_RSFT);
      } else {
        layer_off(LAYER1);
        unregister_code(KC_LSFT);
        if (timer_elapsed(key_timer) > NORMAL) {
          unregister_code(KC_RSFT);
        }
      }
      break;
    }
    case SET_LAYER2: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(LAYER2);
      } else {
        layer_off(LAYER2);
      }
      break;
    }
    case SET_LAYER3: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(LAYER3);
      } else {
        layer_off(LAYER3);
        unregister_code(KC_LSFT);
      }
      break;
    }
    case SET_LAYER5: {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        layer_on(LAYER5);
      } else {
        layer_off(LAYER5);
      }
      break;
    }
    case SET_LAYER6: {
      if (record->event.pressed) {
        layer_on(LAYER6);
      } else {
        layer_off(LAYER6);
      }
      break;
    }
    case SET_LAYER7: {
      if (record->event.pressed) {
        layer_on(LAYER7);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_RALT);
        layer_off(LAYER7);
      }
      break;
    }
    case SPC_LAYER8: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(LAYER8);
        register_code(KC_LCTL);
        unregister_code(KC_LSFT);
      } else {
        layer_off(LAYER8);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_RSFT);
        unregister_code(KC_RALT);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
      }
      break;
    }
    case SFT__SPC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
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
    case _G: {
      if (record->event.pressed) {
        register_code(CM_G);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_G);
      }
      break;
    }
    case _D: {
      if (record->event.pressed) {
        register_code(CM_D);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_D);
      }
      break;
    }
    case _B: {
      if (record->event.pressed) {
        register_code(CM_B);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_B);
      }
      break;
    }
    case _Q: {
      if (record->event.pressed) {
        register_code(CM_Q);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_Q);
      }
      break;
    }
    case _W: {
      if (record->event.pressed) {
        register_code(CM_W);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_W);
      }
      break;
    }
    case _F: {
      if (record->event.pressed) {
        register_code(CM_F);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_F);
      }
      break;
    }
    case _P: {
      if (record->event.pressed) {
        register_code(CM_P);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_P);
      }
      break;
    }
    case _A: {
      if (record->event.pressed) {
        register_code(CM_A);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_A);
      }
      break;
    }
    case _R: {
      if (record->event.pressed) {
        register_code(CM_R);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_R);
      }
      break;
    }
    case _S: {
      if (record->event.pressed) {
        register_code(CM_S);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_S);
      }
      break;
    }
    case _T: {
      if (record->event.pressed) {
        register_code(CM_T);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_T);
      }
      break;
    }
    case _Z: {
      if (record->event.pressed) {
        register_code(CM_Z);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_Z);
      }
      break;
    }
    case _X: {
      if (record->event.pressed) {
        register_code(CM_X);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_X);
      }
      break;
    }
    case _C: {
      if (record->event.pressed) {
        register_code(CM_C);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_C);
      }
      break;
    }
    case _V: {
      if (record->event.pressed) {
        register_code(CM_V);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_V);
      }
      break;
    }
    case _COMM: {
      if (record->event.pressed) {
        register_code(CM_COMM);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_COMM);
      }
      break;
    }
    case _DOT: {
      if (record->event.pressed) {
        register_code(CM_DOT);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_DOT);
      }
      break;
    }
    case _L: {
      if (record->event.pressed) {
        register_code(CM_L);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_L);
      }
      break;
    }
    case _U: {
      if (record->event.pressed) {
        register_code(CM_U);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_U);
      }
      break;
    }
    case _Y: {
      if (record->event.pressed) {
        register_code(CM_Y);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_Y);
      }
      break;
    }
    case _SCLN: {
      if (record->event.pressed) {
        register_code(CM_SCLN);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_SCLN);
      }
      break;
    }
    case _N: {
      if (record->event.pressed) {
        register_code(CM_N);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_N);
      }
      break;
    }
    case _E: {
      if (record->event.pressed) {
        register_code(CM_E);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_E);
      }
      break;
    }
    case _I: {
      if (record->event.pressed) {
        register_code(CM_I);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_I);
      }
      break;
    }
    case _O: {
      if (record->event.pressed) {
        register_code(CM_O);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_O);
      }
      break;
    }
    case _H: {
      if (record->event.pressed) {
        register_code(CM_H);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_H);
      }
      break;
    }
    case _K: {
      if (record->event.pressed) {
        register_code(CM_K);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_K);
      }
      break;
    }
    case _M: {
      if (record->event.pressed) {
        register_code(CM_M);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_M);
      }
      break;
    }
    case _J: {
      if (record->event.pressed) {
        register_code(CM_J);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      } else {
        unregister_code(CM_J);
      }
      break;
    }
  }
  return MACRO_NONE;
};
