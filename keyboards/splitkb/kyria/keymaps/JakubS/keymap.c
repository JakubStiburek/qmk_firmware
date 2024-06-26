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
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
            } else {
                // when keycode is released
            }
            break;
        case LOGOUT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_L);
                unregister_code(KC_LGUI);
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
 * ,-------------------------------------------.                                  ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |   <--  |
 * |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
 * |  CMD   |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  | ;  : | Enter  |
 * |--------+------+------+------+------+------+---------------.  ,---------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | CapsL| HYPR   |  |MO(4)   | LOCK |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+--------|  |--------+------+------+------+------+----------------------'
 *                        | ESC  | LAlt | LCtl | Space| MO(NUM)|  | MO(FU  | MO(ME|  =   | +    | LANG |
 *                        |      |      |      |      |        |  | NCTION)| OR)  |      |      |SCROLL|
 *                        `------------------------------------'  `------------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E   ,  KC_R    , KC_T    ,                                                      KC_Y    ,  KC_U    , KC_I        ,   KC_O ,  KC_P   , KC_BSPC,
     KC_LCTL , KC_A ,  KC_S   ,  KC_D   ,  KC_F    , KC_G    ,                                                      KC_H    ,  KC_J    , KC_K        ,   KC_L , KC_SCLN , KC_ENT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C   ,  KC_V    , KC_B    , KC_CAPS , KC_HYPR  ,/**/ KC_BSLS       , LOGOUT    , KC_N    ,  KC_M    , KC_COMM     , KC_DOT , KC_SLSH , KC_RSFT,
                                 KC_ESC ,  KC_LALT , KC_LGUI , KC_SPC  , MO(_NUM) ,/**/ MO(_FUNCTION) , MO(_MEOR) , KC_EQL  ,  KC_PLUS , SWITCH_LANG
    ),
 /*
  * Layer: NUM
  * ,-------------------------------------------.                                  ,-------------------------------------------.
  * |  Tab   |   ~  |   7  |   8  |   9  |   0  |                                  |   @  |   (  |   )  |   #  |   %  |   <--  |
  * |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
  * |  CMD   |   /  |   4  |   5  |   6  |   -  |                                  |   /  |   [  |   ]  |   \  |   *  | Enter  |
  * |--------+------+------+------+------+------+---------------.  ,---------------+------+------+------+------+------+--------|
  * | LShift |   *  |   1  |   2  |   3  |   +  | CapsL| HYPR   |  |MO(4)   | LOCK |   $  |   <  |   >  |   &  |   -  | RShift |
  * `----------------------+------+------+------+------+--------|  |--------+------+------+------+------+----------------------'
  *                        | ESC  | LAlt | LCtl | Space| MO(NUM)|  | MO(FU  | MO(ME|   !  |   '  |   `  |
  *                        |      |      |      |      |        |  | NCTION)| OR)  |      |      |SCROLL|
  *                        `------------------------------------'  `------------------------------------'
  */
     [_NUM] = LAYOUT(
      KC_TRNS  , KC_TILD ,  KC_P7   ,  KC_P8  ,   KC_P9   , KC_P0   ,                                               KC_AT   ,   KC_LPRN ,  KC_RPRN , KC_HASH , KC_PERC , KC_TRNS,
      KC_TRNS  , KC_PSLS ,  KC_P4   ,  KC_P5  ,   KC_P6   , KC_PMNS ,                                               KC_SLSH ,   KC_LBRC ,  KC_RBRC , KC_BSLS , KC_ASTR , KC_TRNS,
      KC_TRNS  , KC_PAST ,  KC_P1   ,  KC_P2  ,   KC_P3   , KC_PPLS , KC_TRNS  , KC_TRNS ,/**/ KC_TRNS , KC_TRNS ,  KC_DLR  ,   KC_LT   ,  KC_GT   , KC_AMPR , KC_MINS , KC_TRNS,
                                       KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS ,/**/ KC_TRNS , KC_TRNS ,  KC_EXLM ,   KC_QUOT ,  KC_GRV
     ),
/*s
  * Layer: FUNCTION
  * ,-------------------------------------------.                                  ,-------------------------------------------.
  * |  Tab   |   o  |   o  |   o  |   o  |   o  |                                  |   o  |  F9  |  F10 |  F11 |  F12 |   <--  |
  * |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
  * |  CMD   |   o  |   4  |   5  |   6  |   o  |                                  |   o  |  F5  |  F6  |  F7  |  F8  | Enter  |
  * |--------+------+------+------+------+------+---------------.  ,---------------+------+------+------+------+------+--------|
  * | LShift |   o  |   1  |   2  |   3  |   o  |   o  |    o   |  |    o   |   o  |   o  |  F1  |  F2  |  F3  |  F4  | RShift |
  * `----------------------+------+------+------+------+--------|  |--------+------+------+------+------+----------------------'
  *                        | ESC  | LAlt | LCtl | Space| MO(NUM)|  |    o   |   o  |   o  |   o  |   o  |
  *                        |      |      |      |      |        |  |        |      |      |      |SCROLL|
  *                        `------------------------------------'  `------------------------------------'
  */
     [_FUNCTION] = LAYOUT(
      KC_TRNS  , KC_NO ,  KC_NO   , KC_NO   , KC_NO   ,   KC_NO   ,                                          KC_NO , KC_F9 , KC_F10 , KC_F11 , KC_F12 , KC_TRNS,
      KC_TRNS  , KC_NO ,  C(KC_4) , C(KC_5) , C(KC_6) ,   KC_NO   ,                                          KC_NO , KC_F5 , KC_F6  , KC_F7  , KC_F8  , KC_TRNS,
      KC_TRNS  , KC_NO ,  C(KC_1) , C(KC_2) , C(KC_3) ,   KC_NO   , KC_NO   , KC_NO   ,/**/ KC_NO , KC_NO ,  KC_NO , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_TRNS,
                                    KC_TRNS , KC_TRNS ,   KC_TRNS , KC_TRNS , KC_TRNS ,/**/ KC_NO , KC_NO ,  KC_NO , KC_NO , KC_NO
     ),
 /*
  * Layer: MEOR
  * ,-------------------------------------------.                                  ,-------------------------------------------.
  * |  Tab   |   o  |   o  |  <<  |  >>  |  |>  |                                  |    PGUP  |  HOME  |   ↑  |  END |   o  |   <--  |
  * |--------+------+------+------+------+------|                                  |----------+--------+------+------+------+--------|
  * |  CMD   |   o  |   o  |   o  |   o  |   o  |                                  |   PGDOWN |  <-    |   ↓  |  ->  |   o  | Enter  |
  * |--------+------+------+------+------+------+---------------.  ,---------------+----------+--------+------+------+------+--------|
  * | LShift |   o  |   o  |   o  |   o  |   o  |   o  |    o   |  |    o   |   o  |     o    |    o   |   o  |   o  |   o  | RShift |
  * `----------------------+------+------+------+------+--------|  |--------+------+----------+--------+------+----------------------'
  *                        | ESC  | LAlt | LCtl | Space| MO(NUM)|  |    o   |   o  |     o    |    o   |   o  |
  *                        |      |      |      |      |        |  |        |      |          |        |SCROLL|
  *                        `------------------------------------'  `------------------------------------------'
  */
 [_MEOR] = LAYOUT(
       KC_TRNS  , KC_NO ,  KC_NO , KC_MRWD , KC_MFFD , KC_MPLY ,                                           KC_PGUP , KC_HOME , KC_UP    , KC_END   , KC_NO  , KC_TRNS,
       KC_TRNS  , KC_NO ,  KC_NO , KC_NO   , KC_NO   , KC_NO   ,                                           KC_PGDN , KC_LEFT , KC_DOWN  , KC_RIGHT , KC_NO  , KC_TRNS,
       KC_TRNS  , KC_NO ,  KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,/**/ KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO    , KC_NO    , KC_NO  , KC_TRNS,
                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,/**/ KC_TRNS , KC_NO , KC_NO   , KC_NO   , KC_NO    , KC_NO
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
      scroll(1, 3);
    } else {
      scroll(0, 3);
    }
  }
  return false;
}
