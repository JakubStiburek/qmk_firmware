/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NUM,
    _FUNCTION,
    _MEOR
};

// macros
enum macros {
    SWITCH_LANG = 0,
    LOGOUT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SWITCH_LANG:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_SPC);
                unregister_code(KC_LCTL);
            } else {
                // when keycode is released
            }
            break;
        case LOGOUT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_Q);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_Q);
            } else {
                // when keycode is released
            }
            break;
    }
    return true;
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Layer: QWERTY
 * TODO update
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  LGUI  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Enter  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | CapsL| HYPR |  |MO(4) |  PgUP|   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ESC  | LAlt | LCtl | Space| MO(1)|  | LT2( | LT3( |  +   | KC_NO| Macro|
 *                        |      |      |      |      |      |  | RGUI)| + =  |      |      | _0   |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R  ,   KC_T  ,                                                           KC_Y  ,   KC_U ,  KC_I   ,   KC_O ,  KC_P   , KC_BSPC,
     KC_LGUI , KC_A ,  KC_S   ,  KC_D  ,   KC_F  ,   KC_G  ,                                                           KC_H  ,   KC_J ,  KC_K   ,   KC_L , KC_SCLN , KC_ENT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V  ,   KC_B  , KC_CAPS , KC_HYPR  , KC_PGUP       , LOGOUT             , KC_N  ,   KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                                KC_ESC , KC_LALT , KC_LCTL , KC_SPC  , MO(_NUM) , MO(_FUNCTION) , LT(_MEOR,KC_EQL)   , KC_PLUS ,  KC_BSLS , SWITCH_LANG
    ),
 /*
  * Layer: NUM
  * TODO layout
  */
     [_NUM] = LAYOUT(
      KC_TRNS  , KC_TILD ,  KC_P7   ,  KC_P8  ,   KC_P9 ,   KC_P0   ,                                           KC_AT  ,   KC_LPRN ,    KC_RPRN ,   KC_HASH , KC_PERC , KC_TRNS,
      KC_TRNS  , KC_PSLS ,  KC_P4   ,  KC_P5  ,   KC_P6 ,   KC_PMNS ,                                          KC_SLSH ,   KC_LBRC ,    KC_RBRC ,   KC_BSLS , KC_ASTR , KC_TRNS,
      KC_TRNS  , KC_PAST ,  KC_P1   ,  KC_P2  ,   KC_P3 ,   KC_PPLS , KC_NO   , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_DLR  ,    KC_LT  ,     KC_GT  ,   KC_AMPR , KC_MINS , KC_TRNS,
                                      KC_TRNS , KC_TRNS ,   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_EXLM ,   KC_QUOT ,     KC_GRV
     ),
/*s
  * Layer: FUNCTION
  * TODO layout
  */
     [_FUNCTION] = LAYOUT(
      KC_NO  , KC_NO ,  KC_NO   ,  KC_NO  ,   KC_NO ,   KC_NO ,                                  KC_NO , KC_F9 , KC_F10 , KC_F11 , KC_F12 , KC_NO,
      KC_NO  , KC_NO ,  C(KC_4) , C(KC_5) , C(KC_6) ,   KC_NO ,                                  KC_NO , KC_F5 , KC_F6  , KC_F7  , KC_F8  , KC_NO,
      KC_NO  , KC_NO ,  C(KC_1) , C(KC_2) , C(KC_3) ,   KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,  KC_NO , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_NO,
                                      KC_NO , KC_NO ,   KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,  KC_NO , KC_NO , KC_NO
     ),
 /*
   * Layer: FUNCTION
   * TODO layout
   */
 [_MEOR] = LAYOUT(
       KC_NO    , KC_NO ,  KC_NO , KC_MRWD , KC_MFFD , KC_MPLY ,                             KC_PGUP , KC_HOME , KC_UP    , KC_END   , KC_NO  , KC_NO,
       KC_LGUI  , KC_NO ,  KC_NO , KC_NO   , KC_NO   , KC_NO ,                               KC_PGDN , KC_LEFT , KC_DOWN  , KC_RIGHT , KC_NO  , KC_NO,
       KC_NO    , KC_NO ,  KC_NO , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO    , KC_NO    , KC_NO  , KC_NO,
                                             KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,  KC_NO  , KC_NO    , KC_NO
      )
};

void scroll(int direction, int speed) {
    if (direction == 1) {
    while (speed > 0) {
        tap_code(KC_WH_D);
        speed--;
    }
    } else {
    while (speed > 0) {
        tap_code(KC_WH_U);
        speed--;
    }
    }
}

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      scroll(1, 5);
    } else {
      scroll(0, 5);
    }
  }
  return false;
}
