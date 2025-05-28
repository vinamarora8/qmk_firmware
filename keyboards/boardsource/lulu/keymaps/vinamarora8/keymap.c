// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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

