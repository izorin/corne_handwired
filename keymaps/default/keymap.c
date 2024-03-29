// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

    [0] = LAYOUT_split_3x6_3(
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_LCTL,   KC_A, LALT_T(KC_S),  LCTL_T(KC_D), LSFT_T(KC_F), LGUI_T(KC_G),     RGUI_T(KC_H), RSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC	,
                                     KC_ESC,  MO(1),   KC_SPC,                             KC_BSPC, MO(2),   KC_ENT
    )
    // ,

    // [1] = LAYOUT_split_3x6_3(
    // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_NUBS,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     KC_LCTL, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_RSFT, KC_LBRC,  KC_RBRC, KC_RIGHT, KC_EQL, KC_MINS,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_CAPS , KC_PAGE_DOWN, KC_PAGE_UP, KC_HOME, KC_END, XXXXXXX,
    // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                         KC_ESC, MO(1),  KC_SPC,      KC_BSPC,   MO(2), KC_ENT    
 

    // ),

    // [2] = LAYOUT_split_3x6_3(
    // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //   KC_TAB,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10, KC_F11,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     KC_LSFT, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                         KC_ESC, XXXXXXX,  KC_BTN1,     KC_BTN2,   XXXXXXX, KC_ENT 

    // )

};

