/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   TT(1),  KC_SPC,     KC_SPC,   KC_ENT, MO(2)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_G,    KC_C,    KC_W,    KC_E,    KC_R,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_F,    KC_A,    KC_S,    KC_D,    KC_V,                      KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_VOLD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  _______,    _______,  _______, KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_LBRC,                       KC_RBRC,  KC_MINS, KC_EQL, KC_RBRC, KC_BSLS,  KC_F5,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,                      KC_RPRN, KC_UNDS, KC_PLUS, KC_PIPE, KC_PIPE, KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Functions"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

enum combo_events {
    UNDERSCORE,
    MINUSDASH,
    EQUALSKEY,
    PLUSKEY,
    LEFTSQUAREBRACKET,
    RIGHTSQUAREBRACKET,
    LEFTBRACKET,
    RIGHTBRACKET,
    LEFTCURLY,
    RIGHTCURLY,
    ATKEY,
    STARKEY,
    AMPUR,
    HASHKEY,
    EXCLM,
    QMARK,
    DOLLARS,
    FORWARDSLASHKEY,
    BACKSLASHKEY,
    CARETKEY,
    PIPEKEY,
    PERCENTAGEKEY,
    BACKTICK,
    LEFTANGLEBRACKET,
    RIGHTTRIANGLEBRACKET,
    TILDEKEY,
    HOMEKEY,
    ENDKEY,
    PAGEUPKEY,
    PAGEDOWNKEY,

    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM underscore[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM minusdash[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM equalskey[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM pluskey[] = {KC_H, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM leftsquarebracket[] = {KC_U, KC_SPC, COMBO_END};
const uint16_t PROGMEM rightsquarebracket[] = {KC_I, KC_SPC, COMBO_END};
const uint16_t PROGMEM leftbracket[] = {KC_SPC, KC_J, COMBO_END};
const uint16_t PROGMEM rightbracket[] = {KC_SPC, KC_K, COMBO_END};
const uint16_t PROGMEM leftcurly[] = {KC_SPC, KC_M, COMBO_END};
const uint16_t PROGMEM rightcurly[] = {KC_SPC, KC_COMM, COMBO_END};
const uint16_t PROGMEM atkey[] = {KC_U, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM starkey[] = {KC_N, KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM ampur[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM hashkey[] = {KC_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM exclm[] = {KC_U, KC_I, KC_L, COMBO_END};
const uint16_t PROGMEM qmark[] = {KC_K, KC_J, KC_O, COMBO_END};
const uint16_t PROGMEM dollars[] = {KC_M, KC_COMM, KC_O, COMBO_END};
const uint16_t PROGMEM forwardslashkey[] = {KC_M, KC_K, KC_O, COMBO_END};
const uint16_t PROGMEM backslashkey[] = {KC_U, KC_K, KC_DOT, COMBO_END};
const uint16_t PROGMEM caretkey[] = {KC_I, KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM pipekey[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM percentagekey[] = {KC_U, KC_DOT, COMBO_END};
const uint16_t PROGMEM backtick[] = {KC_Y, KC_J, COMBO_END};
const uint16_t PROGMEM righttrianglebracket[] = {KC_U, KC_K, KC_SPC, COMBO_END};
const uint16_t PROGMEM leftanglebracket[] = {KC_I, KC_J, MO(2), COMBO_END};
const uint16_t PROGMEM tildekey[] = {KC_P, KC_J, COMBO_END};
const uint16_t PROGMEM homekey[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM endkey[] = {KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pageupkey[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM pagedownkey[] = {KC_N, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [UNDERSCORE] = COMBO(underscore, KC_UNDS),
    [MINUSDASH] = COMBO(minusdash, KC_MINS),
    [EQUALSKEY] = COMBO(equalskey, KC_EQL),
    [PLUSKEY] = COMBO(pluskey, KC_PLUS),
    [LEFTSQUAREBRACKET] = COMBO(leftsquarebracket, KC_LBRC),
    [RIGHTSQUAREBRACKET] = COMBO(rightsquarebracket, KC_RBRC),
    [LEFTBRACKET] = COMBO(leftbracket, KC_LPRN),
    [RIGHTBRACKET] = COMBO(rightbracket, KC_RPRN),
    [LEFTCURLY] = COMBO(leftcurly, KC_LCBR),
    [RIGHTCURLY] = COMBO(rightcurly, KC_RCBR),
    [ATKEY] = COMBO(atkey, KC_AT),
    [STARKEY] = COMBO(starkey, KC_ASTR),
    [AMPUR] = COMBO(ampur, KC_AMPR),
    [HASHKEY] = COMBO(hashkey, KC_HASH),
    [EXCLM] = COMBO(exclm, KC_EXLM),
    [QMARK] = COMBO(qmark, KC_QUES),
    [DOLLARS] = COMBO(dollars, KC_DLR),
    [FORWARDSLASHKEY] = COMBO(forwardslashkey, KC_SLSH),
    [BACKSLASHKEY] = COMBO(backslashkey, KC_BSLS),
    [CARETKEY] = COMBO(caretkey, KC_CIRC),
    [PIPEKEY] = COMBO(pipekey, KC_PIPE),
    [PERCENTAGEKEY] = COMBO(percentagekey, KC_PERC),
    [BACKTICK] = COMBO(backtick, KC_GRV),
    [LEFTANGLEBRACKET] = COMBO(leftanglebracket, KC_LT),
    [RIGHTTRIANGLEBRACKET] = COMBO(righttrianglebracket, KC_GT),
    [TILDEKEY] = COMBO(tildekey, KC_TILD),
    [HOMEKEY] = COMBO(homekey, KC_HOME),
    [ENDKEY] = COMBO(endkey, KC_END),
    [PAGEUPKEY] = COMBO(pageupkey, KC_PGUP),
    [PAGEDOWNKEY] = COMBO(pagedownkey, KC_PGDN),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
