/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _COLEMAK1,
  _COLEMAK2,
  _RAISE,
  _LOWER,
  _NAV,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  COLEMAK1,
  COLEMAK2,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV_A    LT(_NAV, KC_A)
#define NAV_O    LT(_NAV, KC_O)
#define NAV_SCLN LT(_NAV, KC_SCLN)
#define RSE_RGHT LT(_RAISE, KC_RGHT)
#define RSE_P0   LT(_RAISE, KC_P0)
#define RSE_SPC  LT(_RAISE, KC_SPC)
#define RSE_RET  LT(_RAISE, KC_ENT)
#define LOW_SPC  LT(_LOWER, KC_SPC)
#define LOW_ESC  LT(_LOWER, KC_ESC)
#define LOW_TAB  LT(_LOWER, KC_TAB)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_TAB  MT(MOD_LCTL, KC_TAB)
#define CTL_QUT  MT(MOD_LCTL, KC_QUOT)
#define CTL_SPC  MT(MOD_LCTL, KC_SPC)
#define CTL_RET  MT(MOD_RCTL, KC_ENT)
#define GUI_LFT  MT(MOD_RGUI, KC_LEFT)
#define GUI_TAB  MT(MOD_LGUI, KC_TAB)
#define GUI_ESC  MT(MOD_LGUI, KC_ESC)
#define ALT_ESC  MT(MOD_LALT, KC_ESC)
#define LSF_SPC  MT(MOD_LSFT, KC_SPC)
#define LSF_TAB  MT(MOD_LSFT, KC_TAB)
#define RSF_SPC  MT(MOD_RSFT, KC_SPC)
#define RSF_BSP  MT(MOD_RSFT, KC_BSPC)
#define RSF_RET  MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   ⇥  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/^| A/NAV|   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;/NAV|  '/⌃ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (/⇧ |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Ret/⇧ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Spc/^|Esc/⌥ |Tab/⌘ |Spc/Lo| Space|Space |Spc/Rs|Left/⌘| Down |  Up  |->/Rse|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  CTL_ESC, NAV_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NAV_SCLN, CTL_QUT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  RSF_RET,
  LOWER,   CTL_SPC, ALT_ESC, GUI_TAB, LOW_SPC, LSF_SPC, RSF_SPC, RSE_SPC, GUI_LFT, KC_DOWN, KC_UP,    RSE_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab/^| A/NAV|   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  | O/NAV| Ret/^|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Ret/⇧|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Space|  ⌥   |   ⌘  |Lower | Bksp |Space |Raise |Left/⌘| Down |  Up  |->/Rse|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, NAV_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    NAV_O,   _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Colemak1: derived from Colemak Mod-DH, switching KM and rotating BGV
 * (just switch DV and HM w/r to Colemak proper)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ⇥  |   Q  |   W  |   F  |   P  |   Z  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/^| A/NAV|   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  | O/NAV| Ret/^|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (/⇧ |   X  |   V  |   C  |   D  |   B  |   K  |   H  |   ,  |   .  |   /  | Ret/⇧|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Spc/^|  ⌥   |   ⌘  | Lower| Space|Space |Raise |Left/⌘| Down |  Up  |->/Rse|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK1] = LAYOUT_planck_grid( \
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_Z,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, NAV_A,   KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    NAV_O,   _______,
  _______, KC_X,    KC_V,    KC_C,    KC_D,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Colemak2
 * ,-----------------------------------------------------------------------------------.
 * |   ⇥  |   Q  |   W  |   F  |   P  |   G  |   Y  |   U  |   I  |   K  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/^| A/NAV|   R  |   S  |   T  |   V  |   M  |   N  |   E  |   L  | O/NAV| Ret/^|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (/⇧ |   Z  |   X  |   C  |   D  |   B  |   J  |   H  |   ,  |   .  |   /  | Ret/⇧|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Spc/^|  ⌥   |   ⌘  | Lower| Space|Space |Raise |Left/⌘| Down |  Up  |->/Rse|
 * `-----------------------------------------------------------------------------------'
 */
/* Colemak2: derived from Colemak Mod-DH, switching KM and rotating BGV
 * (just switch DV and HM w/r to Colemak proper)
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   Z  |   \  |   `  |   J  |   L  |   U  |   Y  |  ;   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | A/Nav|   R  |   S  |   T  |   G  |   -  |   '  |   M  |   N  |   E  |   I  | O/Nav|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   X  |   V  |   C  |   D  |   B  |   (  |   )  |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Spc/^|  ⌥   |   ⌘  | Lower| Space|Space |Ret/Rs|Left/⌘| Down |  Up  |->/Rse|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK2] = LAYOUT_planck_grid( \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_Z,    KC_BSLS, KC_GRV,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  NAV_A,   KC_R,    KC_S,    KC_T,    KC_G,    KC_MINS, KC_QUOT, KC_M,    KC_N,    KC_E,    KC_I,    NAV_O,
  KC_X,    KC_V,    KC_C,    KC_D,    KC_B,    KC_LPRN, KC_RPRN, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
  _______, _______, _______, GUI_ESC, LOW_SPC, LSF_TAB, RSF_BSP, RSE_RET, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |  ,   |   .  |   7  |   8  |   9  |   *  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   %  |   ^  |   &  |   *  |  (   |   )  |   4  |   5  |   6  |   +  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   (  |   )  |   -  |   =  |  [   |   ]  |   1  |   2  |   3  | Enter|  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Shift | Bksp |Space | 0/Rse|   0  |   .  | Enter|  `   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_COMM, KC_DOT,  KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_MINS,
  RAISE,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_QUOT,
  _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_BSLS,
  _______, KC_BSPC, _______, _______, KC_LSFT, KC_BSPC, KC_SPC,  RSE_P0,  KC_P0,   KC_PDOT, KC_PENT, KC_GRV
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab/^|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   [  |   ]  |   -  |   =  |   `  |   \  |   '  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      |      |      |             |      |      | Vol- | Vol+ |  `   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
  _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_QUOT, _______, _______, _______, KC_BSLS,
  BACKLIT, _______, _______, _______, LOWER,   _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_GRV
),

/* Directional navigation layer
 *
 *          Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │     │     │     │     │     │     │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     ┃     ┃     │     │     │     │     │
 *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
 */
[_NAV] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug| LED  |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Colem2|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  COLEMAK,  COLEMAK1,COLEMAK2,_______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case COLEMAK1:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK1);
      }
      return false;
      break;
    case COLEMAK2:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK2);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _LOWER:
      rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF); // LOWER
      break;
    case _RAISE:
      rgb_matrix_set_color(44, 0xFF, 0xFF, 0xFF); // RAISE
      break;
    default:
      break;
  }

  // Disable middle LED between keys in grid layout.
  rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
}
#endif
