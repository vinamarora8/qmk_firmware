// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/oled.h"

// clang-format off
enum layers {
    _QWERTY,
    _SYMBOLS
};

#define SYMBOLS MO(_SYMBOLS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_RCTL,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_LALT,    KC_LGUI, SYMBOLS,  KC_SPC,   KC_SPC, SYMBOLS, KC_RGUI, KC_RALT
),

[_SYMBOLS] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_LBRC, KC_LT,   KC_GT,  KC_RBRC, KC_TILD,                     KC_PIPE, KC_GRV,  KC_QUOT, KC_DQUO, KC_PGUP, _______,
  _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_DEL,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_EQL,  KC_UNDS, KC_MINS, KC_PLUS, KC_BSLS, _______,
                             _______, _______, KC_ESC,  KC_BSPC, KC_BSPC,  KC_ESC,  _______, _______
)
};


#ifdef OLED_ENABLE

/*
static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}
*/

static void render_infinity_logo(void) {
    // created using https://joric.github.io/qle/
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,224,240,240,248,248,120,124,124,124,124,124,252,248,248,248,240,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,224, 96,112,112, 48, 56, 56, 56, 56, 56,120,112,112,240,224,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,254,255, 31,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 31, 63,127,255,255,254,252,248,224,204,140,  6,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7, 63,255,254,248,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 15, 63,255,248,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224, 96, 49, 27,  7, 31, 63,127,255,255,254,252,248,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,254,255,255, 63,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7, 14, 14, 14, 28, 28, 28, 28, 12, 12, 14, 14,  6,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 15, 31, 31, 31, 63, 63, 63, 63, 63, 63, 63, 31, 31, 31, 15,  7,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_lulu_logo(void) {
    oled_write_raw_P(bs_logo_img, sizeof(bs_logo_img));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_infinity_logo();
    } else {
        render_lulu_logo();
    }
    return false;
}
#endif
