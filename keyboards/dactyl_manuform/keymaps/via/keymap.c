/* Copyright 2021 pierre
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
/* A QWERTY 3 Layer layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;


/* Layer shorthand */
enum layers {
  _QWERTY = 0, /* default layer */
  _LOWER,      /*  */
  _RAISE,      /*  */
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

/* Short forms for keycodes so that they fit into limited-width cells */
#define M_LOWER M(MACRO_LOWER)
#define M_UPPER M(MACRO_UPPER)
#define ROT_LED M(M_LED)   /* Rotate LED */
#define CTLENTER MT(MOD_RCTL, KC_ENT)
#define SHIFTQUOTE MT(MOD_RSFT, KC_QUOT)
#define ALTRIGHT MT(MOD_LALT, KC_RGHT)
#define MVERSION M(M_VERSION)
#define ALTSLASH LALT(KC_SLSH)
#define ALTSHFT LALT(KC_LSFT)
#define ALTSLSH ALGR_T(KC_SLSH)
#define SFTBSLS MT(MOD_RSFT, KC_BSLS)
#define MLSHIFT OSM(KC_LSFT)
#define MLCTL OSM(KC_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
  // left hand
   KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_MUTE,
   KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
   KC_LSFT,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_ESC,
   KC_LCTL,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                      KC_LGUI,   KC_LALT,
                               KC_SPC,  KC_BSPC,
                               LOWER,   KC_LCTL,
                               KC_LALT, KC_ESC,
        // right hand
                     KC_MUTE, KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                     KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_EQL,
                     KC_MEH,  KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                              KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,
                                                ALTSLSH,  KC_SLSH,
        KC_TAB,  KC_ENT,
        KC_RSFT, RAISE,
        KC_PGUP, KC_PGDN),

[_RAISE] = LAYOUT(
  // left hand
   _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    KC_F6,
   _______,   _______,   _______,    KC_UP,    _______,   _______,  _______,
   _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   _______,  QK_BOOT,
   _______,   _______,   _______,   _______,   _______,   _______,
                         KC_MPRV,   KC_MNXT,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    _______,
                     _______,   _______,   _______,   _______,   _______,   _______,   _______,
                     QK_BOOT,   _______,   KC_L,      _______,   _______,   _______,   _______,
                                _______,   _______,   _______,   _______,   _______,   _______,
                                                      _______,   _______,
        KC_DEL, _______,
        _______, _______,
        _______, _______),

[_LOWER] = LAYOUT(
  // left hand
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  QK_BOOT,
   _______,   _______,   _______,   _______,   _______,   _______,
                         _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   _______,   _______,   _______,   KC_PMNS,   KC_PPLS,   _______,
                     _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
                     _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
                                _______,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
                                                      KC_P0,     KC_PDOT,
        _______, _______,
        _______, _______,
        _______, _______),

};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    //                  Encoder 1                                     Encoder 2
};
#endif


#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM layer_ind_DEFAULT[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM layer_ind_LOWER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, RGB_AZURE}
);
const rgblight_segment_t PROGMEM layer_ind_RAISE[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED}
);

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_ind_DEFAULT,
    layer_ind_LOWER,
    layer_ind_RAISE
);
#endif // RGBLIGHT_LAYERS

void matrix_init_user(void) {

}

void keyboard_pre_init_user(void) {
  setPinInputHigh(D0);
  setPinInputHigh(D1);
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;

#ifdef RGBLIGHT_LAYERS
  // Enable the LED layers
  rgblight_layers = _rgb_layers;
  //rgblight_set_layer_state(_QWERTY, true);
#endif // RGBLIGHT_LAYERS
}


#ifdef RGBLIGHT_LAYERS

layer_state_t default_layer_state_set_user_rgb(layer_state_t state)
 {
    // dprintf("         layer   =%d\n", (uint8_t)state);
    for (uint8_t i=_QWERTY; i<=_RAISE; i++) {
      bool is_on = layer_state_cmp(state, i);
      // dprintf("         layer[%d]=%u\n", i, is_on);
      rgblight_set_layer_state(i, is_on);
    }

    return state;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // dprintf("         layer   =%d\n", (uint8_t)state);
    for (uint8_t i=_QWERTY; i<=_RAISE; i++) {
      bool is_on = layer_state_cmp(state, i);
      // dprintf("         layer[%d]=%u\n", i, is_on);
      rgblight_set_layer_state(i, is_on);
    }

    return state;
}

// void suspend_power_down_user(void) {
    // rgblight_disable();
// }

// void suspend_wakeup_init_user(void) {
    // rgblight_enable();
// }
#endif // RGBLIGHT_LAYERS
