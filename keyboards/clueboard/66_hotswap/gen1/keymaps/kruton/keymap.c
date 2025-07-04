/* Copyright 2017 Zach White <skullydazed@gmail.com>
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

enum layer_names {
    _WM,
    _JP,
    _MS,
    _FL,
    _CL,
};

enum custom_keycodes {
    S_RKROL = SAFE_RANGE,
    S_ODEJY,
    S_RCKBY,
    S_IMPRL,
    S_SCALE,
    S_ONEUP,
    S_COIN,
    S_SONIC,
    S_ZELDA
};

#ifdef AUDIO_ENABLE
  float song_rick_roll[][2] = SONG(RICK_ROLL);
  float song_ode_to_joy[][2]  = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2]  = SONG(ROCK_A_BYE_BABY);
  float song_imperial_march[][2]  = SONG(IMPERIAL_MARCH);
  float song_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2]  = SONG(COIN_SOUND);
  float song_one_up[][2]  = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2]  = SONG(SONIC_RING);
  float song_zelda_puzzle[][2]  = SONG(ZELDA_PUZZLE);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WM: Workman layout
   * ,-----------------------------------------------------------.   ,---.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `| BS|   |INS|
   * |-----------------------------------------------------------|   |---|
   * |Tab  |  Q|  D|  R|  W|  B|  J|  F|  U|  P|  ;|  [|  ]|    \|   |DEL|
   * |-----------------------------------------------------------|   `---'
   * |Cap   |  A|  S|  H|  T|  G|  Y|  N|  E|  O|  I|  '| Enter  |
   * |----------------------------------------------------------------.
   * | Shift  |  Z|  X|  M|  C|  V|  K|  L|  ,|  .|  /|  Shft    | UP |
   * |--------------------------------------------------------------------.
   * |Ctl | OS |Alt |  Space  |  Space  |Code| Alt|Fn| Ctl | LFT|DWN |RIG |
   * `--------------------------------------------------------------------'
   */
[_WM] = LAYOUT(
  QK_GESC, KC_1,  KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,      KC_BSPC,            KC_PGUP,
  KC_TAB,  KC_Q,  KC_D,   KC_R,   KC_W,   KC_B,   KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,KC_LBRC,KC_RBRC, KC_BSLS,                KC_PGDN,
  KC_BSPC, KC_A,  KC_S,   KC_H,   KC_T,   KC_G,   KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,   KC_QUOT,      KC_ENT,
  KC_LSFT,        KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   KC_K,   KC_L,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,                  KC_UP,
  KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,  KC_SPC,                        KC_RGUI,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN, KC_RGHT
),

[_JP] = LAYOUT(
  QK_GESC, KC_1,  KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,      KC_BSPC,            KC_PGUP,
  KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC, KC_BSLS,                KC_PGDN,
  KC_BSPC, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,                  KC_UP,
  KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,  KC_SPC,                        KC_RGUI,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN, KC_RGHT
),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  KC_GRV ,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,      KC_DEL,           KC_VOLU,
  _______,DF(_JP),_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP, KC_END,_______,_______,_______,                KC_VOLD,
  KC_DEL ,DF(_WM),MO(_CL),_______,_______,_______,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,    _______,
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        KC_PGUP,
  _______,_______,_______,                _______,_______,                        _______,_______,MO(_FL),_______,KC_HOME,KC_PGDN,KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = LAYOUT(
  LM_NEXT,S_ODEJY,S_RCKBY,S_IMPRL,S_SCALE,S_ONEUP,S_COIN ,S_SONIC,S_ZELDA,S_RKROL,_______,_______,_______,     LM_TOGG,           LM_BRIU,
  _______,_______,_______,_______,QK_BOOT,_______,_______,_______,_______,_______,_______,_______,_______,_______,                LM_BRID,
  _______,_______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        _______,
  _______,_______,_______,                _______,_______,                        _______,_______,MO(_FL),_______,_______,_______,_______),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef AUDIO_ENABLE
            case S_RKROL:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_rick_roll);
                }
                return false;
            case S_ODEJY:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_ode_to_joy);
                }
                return false;
            case S_RCKBY:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_rock_a_bye_baby);
                }
                return false;
            case S_IMPRL:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_imperial_march);
                }
                return false;
            case S_SCALE:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_scale);
                }
                return false;
            case S_ONEUP:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_one_up);
                }
                return false;
            case S_COIN:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                }
                return false;
            case S_SONIC:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_sonic_ring);
                }
                return false;
            case S_ZELDA:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_zelda_puzzle);
                }
                return false;
        #endif
    }
    return true;
}
