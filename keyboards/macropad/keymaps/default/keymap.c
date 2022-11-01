// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _VOL,
    _PO1,
    _PO2,
    _PAG,
    _COL,
};


#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_vol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_po1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_po2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_pag_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_vol_layer,
    my_po1_layer,
    my_po2_layer,
    my_pag_layer
);
#endif // RGBLIGHT_LAYERS


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base KC_MPLY */
    [_VOL] = LAYOUT(
        QK_BOOT,   KC_MPLY, TO(_PO1), QK_BOOT, QK_BOOT, QK_BOOT
    ),
    [_PO1] = LAYOUT(
        QK_BOOT,   TO(_PO2), TO(_PAG), QK_BOOT, QK_BOOT, QK_BOOT
    ),
    [_PO2] = LAYOUT(
        QK_BOOT,   TO(_PO1), TO(_PAG), QK_BOOT, QK_BOOT, QK_BOOT
    ),
    [_PAG] = LAYOUT(
        QK_BOOT,   KC_HOME, TO(_COL), QK_BOOT, QK_BOOT, QK_BOOT
    ),
    [_COL] = LAYOUT(
        QK_BOOT,   RGB_MOD, TO(_VOL), QK_BOOT, QK_BOOT, QK_BOOT
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_VOL] = { ENCODER_CCW_CW(KC_VOLU,  KC_VOLD) },
    [_PO1] = { ENCODER_CCW_CW(KC_UP,    KC_DOWN) },
    [_PO2] = { ENCODER_CCW_CW(KC_RGHT,  KC_LEFT) },
    [_PAG] = { ENCODER_CCW_CW(KC_PGUP,  KC_PGDN) },
    [_COL] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif


void matrix_init_user(void) {
  // rgblight_enable();
  // rgblight_sethsv(HSV_RED);
  // rgblight_decrease_val_noeeprom();
  // rgblight_decrease_val_noeeprom();
  // rgblight_decrease_val_noeeprom();
  // rgblight_decrease_val_noeeprom();
  // rgblight_sethsv_noeeprom(0, 255, 130);
}

#ifdef RGBLIGHT_LAYERS
void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, _VOL));
    rgblight_set_layer_state(1, layer_state_cmp(state, _PO1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _PO2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _PAG));
    // rgblight_set_layer_state(4, layer_state_cmp(state, _COL));

    return state;
}

// bool led_update_user(led_t led_state) {
    // rgblight_set_layer_state(0, led_state.caps_lock);
    // return true;
// }

void suspend_power_down_user(void) {
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    rgblight_enable();
}

#endif // RGBLIGHT_LAYERS

/*

void matrix_scan_user(void) {

}

*/
