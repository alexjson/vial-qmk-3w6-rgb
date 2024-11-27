/* Copyright 2021 weteor
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

enum unicode_names { SE_O, SE_OS, SE_AE,SE_AES, SE_OA, SE_OAS };

const uint32_t PROGMEM unicode_map[] = {
    [SE_O] = 0x00F6,  // Ö
    [SE_OS] = 0x00D6,  // Ö
    [SE_AES] = 0x00C4,  // Ä
    [SE_AE] = 0x00E4,  // Ä
    [SE_OA] = 0x00E5,  // Ã
    [SE_OAS] = 0x00C5  // Ã
};

#define SWE_O UP(SE_O, SE_OS)
#define SWE_A UP(SE_AE, SE_AES)
#define SWE_OA UP(SE_OA, SE_OAS)


// Left-hand home row mods
#define H_A LGUI_T(KC_A)
#define H_S LALT_T(KC_S)
#define H_D LCTL_T(KC_D)
#define H_F LSFT_T(KC_F)

// Right-hand home row mods
#define H_J RSFT_T(KC_J)
#define H_K RCTL_T(KC_K)
#define H_L LALT_T(KC_L)
#define H_SCLN RGUI_T(KC_SCLN)


enum layers
{
    _ALPHA_QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
    _MSE,
    _SWE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    
    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  
        H_A,          H_S,     H_D,     H_F,    KC_G,                                                 KC_H,    H_J,    H_K,    H_L,    H_SCLN,
        KC_Z,         KC_X,    KC_C,    KC_V,    LT(_MSE, KC_B),                                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
            
                        LT(_NAV, KC_DEL), LT(_NUM,KC_ESC), LT(_SYM, KC_SPC),                          KC_ENT, KC_BSPC, KC_TAB
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX,   KC_MINS,  KC_PLUS, KC_CIRC,                                KC_DLR, KC_RBRC, KC_LBRC, KC_TILD, KC_GRV,
        KC_AMPR, KC_PERC, KC_HASH, KC_AT,  KC_EXLM,                                KC_DQUO, KC_RPRN, KC_LPRN, KC_PIPE, XXXXXXX, 
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_ASTR,                                KC_QUOT, KC_RCBR, KC_LCBR, KC_BSLS, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_EQUAL, TO(_SWE) 
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  KC_DEL,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_HOME,                                KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX         
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F9, KC_F10, KC_F11, KC_F12,                                    XXXXXXX,  KC_1,  KC_2,  KC_3, XXXXXXX,
        XXXXXXX,  KC_F5,  KC_F6,  KC_F7,  KC_F8,                                    XXXXXXX,  KC_4,  KC_5,  KC_6, XXXXXXX,
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,                                    XXXXXXX,  KC_7,  KC_8,  KC_9, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_0, XXXXXXX 
    ),
    [_MSE] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX,
                                         XXXXXXX, XXXXXXX, XXXXXXX,     KC_MS_BTN1, KC_MS_BTN2, XXXXXXX
    ),
    [_SWE] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SWE_O,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, SWE_OA, SWE_A,
                                         KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, TG(_SWE) 
    ),
};
