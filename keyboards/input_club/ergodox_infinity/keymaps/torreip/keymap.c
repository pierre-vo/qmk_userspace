/* Copyright 2017 Pierre V.
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
#include <stdbool.h>
// #include "debug.h"
#include "action_layer.h"
// #include "action_util.h"
#include "timer.h"
#include "eeconfig.h"
#include "wait.h"
#include "version.h"

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300
#define LAYER_SKIP_DELAY 1000

/* Fillers to make layering more clear */
// #define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/* Layer shorthand */
enum layers {
    BASE = 0, /* default layer */
    SYMB,     /* symbols */
    MDIA,     /* media keys */
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, /* can always be here */
    LOWER,
    RAISE,
    EPRM,
    VRSN,
    RST,
    KMAP,
    RGB_SLD
};

/* Tap Dance Declarations */
enum {
    SCL = 0,
    QUO,
};

/* Short forms for keycodes so that they fit into limited-width cells */
#define M_LOWER M(MACRO_LOWER)
#define M_UPPER M(MACRO_UPPER)
#define ROT_LED M(M_LED) /* Rotate LED */
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
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           | BkSp |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Del    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  |AltShf| LGui | [    |                                       |  ]   |  /   | Left | Dwon |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  |Enter |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| LShift |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_DEL,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        KC_LCTL, KC_LGUI, ALTSHFT, KC_LALT,LOWER,
                                              ALT_T(KC_APP),  KC_ENT,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_BSPC,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_MINS,
             KC_RBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_EQL,
                          KC_H,   KC_J,   KC_K,   KC_L,   TD(SCL),  TD(QUO),
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,    SFTBSLS,
                                  RAISE,  ALTSLSH,KC_LEFT,KC_DOWN,    KC_RGHT,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_LSFT,KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   [  |   ]  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------| Rst  |           | Rst  |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   {  |   }  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_EXLM,KC_AT,  KC_LBRC,KC_RBRC,KC_PIPE,_______,
       _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       _______,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_TILD,_______,
       _______,_______,_______,_______,___T___,
                                       _______,RST,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, _______,
                         KC_0,   KC_DOT,  KC_0,    KC_EQL,  _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
       KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       VRSN,    _______, _______, _______, _______, _______, _______,
       RST,     KMAP,    _______, _______, XXXXXXX,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, KC_MPRV, KC_MNXT, _______, _______, _______,
       _______,  _______, KC_WBAK, KC_WFWD, _______, KC_MPLY, _______,
                 _______, KC_BTN1, KC_BTN2, _______, _______, _______,
       _______,  _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
                          ___T___, _______, _______, _______, _______,
       RST,     _______,
       _______,
       _______, _______, _______
),
};

static uint16_t key_timer;
static bool singular_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        //SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ (" QMK_VERSION "/" LAYOUT_ergodox_VERSION ")");
      }

      return false;
      break;

    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }

      return false;
      break;

    case KMAP:
      if (record->event.pressed) {
        SEND_STRING("http://www.keyboard-layout-editor.com/#/gists/9dd2c2bd6f1120685ee810303563c7f5");
      }

      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        key_timer = timer_read();
        singular_key = true;
        layer_on(SYMB);

      } else if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY
                 || timer_elapsed(key_timer) > LAYER_SKIP_DELAY
                 || !singular_key) {
        layer_off(SYMB);
      }

      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        key_timer = timer_read();
        singular_key = true;
        layer_on(MDIA);

      } else if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY
                 || timer_elapsed(key_timer) > LAYER_SKIP_DELAY
                 || !singular_key) {
        layer_off(MDIA);
      }

      return false;
      break;

    case RST:
      reset_keyboard();
      return false;
      break;

    /* If any other key was pressed during the layer mod hold period,
     * then the layer mod was used momentarily, and should block latching */
    default:
      singular_key = false;
      break;
  }

  return true;

}

/* Tap Dance Definitions */
tap_dance_action_t tap_dance_actions[] = {
  /* Shifting for double quote and semicolon */
  [SCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [QUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),

  /* complex tap dance function (to specify what happens when key is
   * pressed 3+ times, for example). See
   * https://docs.qmk.fm/tap_dance.html for how to define
  [YOUR_TAPDANCE_2] = ACTION_TAP_DANCE_FN(your_function_name),0
  */
};


/* Runs whenever there is a layer state change. */
/* uint32_t layer_state_set_user(uint32_t state) {

#ifdef RGBLIGHT_ENABLE
  switch (biton32(state)) {
    case BASE:
      if (skip) {
        RGB_current_mode = rgblight_get_mode();
        skip = false;
      } else {
        rgblight_mode(RGB_current_mode);
      }
      break;

    case SYMB:
      RGB_current_mode = rgblight_get_mode();
      rgblight_mode(1);
      rgblight_setrgb(0x00, 0xA0, 0xFF);
      break;

    case MDIA:
      RGB_current_mode = rgblight_get_mode();
      rgblight_mode(1);
      rgblight_setrgb(0xFF, 0x00, 0x00);
      break;

    default:
      break;
  }
#endif  / * RGBLIGHT_ENABLE * /

  return state;
}
*/

/* Called at startup */
void matrix_init_user(void) {

  if (!eeconfig_is_enabled())
    eeconfig_init();

  /*#ifdef RGBLIGHT_ENABLE
    rgblight_init();
    RGB_current_mode = rgblight_get_mode();
  #endif */ /* RGBLIGHT_ENABLE */
}

#ifdef ST7565_ENABLE
static void render_status(void) {
    // Host Keyboard Layer Status
    st7565_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            // state->target_lcd_color = LCD_COLOR(84, saturation, 0xFF);
            ergodox_infinity_lcd_color(0, 0, 0);
            st7565_write_P(PSTR("DEFAULT\n"), false);
            break;
        case SYMB:
            // state->target_lcd_color = LCD_COLOR(168, saturation, 0xFF);
            ergodox_infinity_lcd_color(0x00, 0x00, 0xFFFF/2);
            st7565_write_P(PSTR("SYMBOL\n"), false);
            break;
        case MDIA:
            // state->target_lcd_color = LCD_COLOR(0, saturation, 0xFF);
            ergodox_infinity_lcd_color(0xFFFF/2, 0x00, 0x00);
            st7565_write_P(PSTR("MEDIA\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            st7565_write_ln_P(PSTR("Undefined"), false);
    }

    uint8_t mods = get_mods() | get_weak_mods();
    st7565_write_P(PSTR("\n"), false);
    st7565_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI ") : PSTR("    "), false);
    st7565_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    st7565_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    st7565_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR("     "), false);
    st7565_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    st7565_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    st7565_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    st7565_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     st7565_write_P(qmk_logo, false);
// }

void st7565_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        ergodox_infinity_lcd_color(0, 0, 0);
        // render_logo();   // Renders a static logo
        st7565_write_P(PSTR(QMK_VERSION "\n" LAYOUT_ergodox_VERSION), false);
    }
}

#endif // ST7565_ENABLE

