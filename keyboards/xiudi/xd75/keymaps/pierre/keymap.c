/* Copyright 2017 Wunder
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

/* Fillers to make layering more clear */
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/* those keycodes were removed when updating, keeping them as dummy defines until cleanup */
#define KC_NLCK KC_NO
#define KC_SLCK KC_NO
#define EEP_RST KC_NO

enum layer_names {
    _QW,  /* Base layer, QWERTY */
    _LW,  /* LOWER */
    _RS,  /* RAISE */
    _FN,  /* FUNCTION */
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  LOWER,
  RAISE,
  FUNC,
  VRSN,
  KMAP,
  RST,
};

/* Tap Dance Declarations */
enum {
  SCL = 0,
  QUO,
};

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
#define ALTBSP ALT_T(KC_BSPC)
#define ALTSLSH ALGR_T(KC_SLSH)
#define SFTBSLS MT(MOD_RSFT, KC_BSLS)
#define MLSHIFT OSM(KC_LSFT)
#define MLCTL OSM(KC_LCTL)
#define CTRLB LCTL(KC_B)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
 * .-------------------------------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  || ESC | F5  | Bkp ||  6  |  7  |  8  |  9  |  0  |  -  |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * | TAB |  Q  |  W  |  E  |  R  |  T  ||  [  |FUNC |  ]  ||  Y  |  U  |  I  |  O  |  P  |  =  |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * | DEL |  A  |  S  |  D  |  F  |  G  ||     |     |     ||  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |LSHFT|  Z  |  X  |  C  |  V  |  B  ||     |PG UP|RCTRL||  N  |  M  |  ,  |  .  | UP  |  \  |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |LCTRL|LGUI |LALTS|LALT |LOWER|SPACE|| Bkp |PG DN|LSHFT||ENTER|RAISE|  /  |LEFT |DOWN |RIGHT|
 * '-------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,   KC_ESC,   KC_F5, KC_BSPC,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,  KC_LBRC,    FUNC, KC_RBRC,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
        KC_DEL , KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    CTRLB,  KC_F14,  KC_F15,   KC_H,   KC_J,    KC_K,    KC_L, TD(SCL), TD(QUO),
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,   KC_F16, KC_RCTL, KC_PGUP,   KC_N,   KC_M, KC_COMM,  KC_DOT,   KC_UP, SFTBSLS,
        KC_LCTL, KC_LGUI, ALTSHFT, KC_LALT, LOWER,  KC_SPC,  KC_BSPC, KC_PGDN, KC_LSFT, KC_ENT,  RAISE, ALTSLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),


/* LOWERED
 * .-------------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  ||     |     |     || F6  | F7  | F8  | F9  | F10 | F11 |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  !  |  @  |  [  |  ]  |  |  ||     |     |     ||     |  7  |  8  |  9  |  *  | F12 |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  #  |  $  |  (  |  )  |  `  ||     |     |     ||     |  4  |  5  |  6  |  +  |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |  %  |  ^  |  {  |  }  |  ~  ||     |     |     ||     |  1  |  2  |  3  |  \  |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     ||     |     |     ||     |  0  |     |     |  =  |     |
 * '-------------------------------------------------------------------------------------------'
 */

  [_LW] = LAYOUT_ortho_5x15( /* LOWERED */
        _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,   _______, _______, _______,    KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11  ,
        _______, KC_EXLM,  KC_AT , KC_LBRC, KC_RBRC, KC_PIPE,   _______, XXXXXXX, _______,   _______,  KC_7  ,  KC_8  ,  KC_9  , KC_ASTR, KC_F12  ,
        _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV ,   _______, _______, _______,   _______,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS, _______ ,
        _______, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_TILD,   _______, _______, _______,   _______,  KC_1  ,  KC_2  ,  KC_3  , KC_BSLS, _______ ,
        _______, _______, _______, _______, ___T___, _______,   _______, _______, _______,   _______,  KC_0  , _______, _______, KC_EQL , _______
    ),

/* RAISED
 * .-------------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     ||     |     |     ||     | <<  | >>  |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |MS UP|     |     ||     |     |     ||     | <-  | ->  |     | PLY |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |MS <-|MS DW|MS ->|     ||     |     |     ||     | BT1 | BT2 |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     ||     |     |     ||     | V-  | V+  | MUT |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     ||     |     |     ||     |     |     |     |     |     |
 * '-------------------------------------------------------------------------------------------'
 */

  [_RS] = LAYOUT_ortho_5x15( /* RAISED */
        KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______,   _______, _______, _______,   _______, KC_MPRV, KC_MNXT, _______, _______, _______ ,
        _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,   _______, XXXXXXX, _______,   _______, KC_WBAK, KC_WFWD, _______, KC_MPLY, _______ ,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,   _______, _______, _______,   _______, KC_BTN1, KC_BTN2, _______, _______, _______ ,
        _______, _______, _______, _______, _______, _______,   _______, _______, _______,   _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______ ,
        _______, _______, _______, _______, XXXXXXX, _______,   _______, _______, _______,   _______, ___T___, _______, _______, _______, _______
    ),


    /* FUNCTION
 * .-------------------------------------------------------------------------------------------.
 * | NLK |     |     |     |     |     ||     |     |     ||     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |SCRL |     |     |HUE+ |HUE- |     || TOG |     | MOD ||     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |CAPS |     |     |SAT+ |SAT- |     ||     |     |     ||     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * | VER |EP_RS|     |LED+ |LED- |     ||     |     |     ||     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----++-----+-----+-----++-----+-----+-----+-----+-----+-----|
 * |RESET| MAP |     |     |     |     ||     |     |     ||     |     |     |     |     |     |
 * '-------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_NLCK, _______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______ ,
        KC_SLCK, _______, _______, RGB_HUI, RGB_HUD, _______,   RGB_TOG, ___T___, RGB_MOD,   RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW, RGB_M_K, RGB_M_G ,
        KC_CAPS, _______, _______, RGB_SAI, RGB_SAD, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______ ,
         VRSN  , EEP_RST, _______, RGB_VAI, RGB_VAD, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______ ,
          RST  ,  KMAP  , _______, _______, XXXXXXX, _______,   _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______
    )
};


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

#ifndef QMK_VERSION
  #define QMK_VERSION "VER"
  #define QMK_BUILDDATE "DATE"
#endif

static uint16_t key_timer;
static bool singular_key = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
	SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
        //SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        //SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " );
      }

      return false;
      break;

    case KMAP:
      if (record->event.pressed) {
        SEND_STRING("http://www.keyboard-layout-editor.com/#/gists/0e924c013c75d1dc4bbf51806b5500ee");
      }

      return false;
      break;


    case LOWER:
      if (record->event.pressed) {
        key_timer = timer_read();
        singular_key = true;
        layer_on(_LW);

      } else if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY
                 || timer_elapsed(key_timer) > LAYER_SKIP_DELAY
                 || !singular_key) {
        layer_off(_LW);
      }

      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        key_timer = timer_read();
        singular_key = true;
        layer_on(_RS);

      } else if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY
                 || timer_elapsed(key_timer) > LAYER_SKIP_DELAY
                 || !singular_key) {
        layer_off(_RS);
      }

      return false;
      break;

    case FUNC:
      if (record->event.pressed) {
        key_timer = timer_read();
        singular_key = true;
        layer_on(_FN);

       } else if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY
                 || timer_elapsed(key_timer) > LAYER_SKIP_DELAY
                 || !singular_key) {
        layer_off(_FN);
      }

      return false;
      break;

    case RST:
      rgblight_disable_noeeprom();

      _delay_ms(50);

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


// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layerQW_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_MINE_QW}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layerLW_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_MINE_LW}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layerRS_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_MINE_RS}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layerFN_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_MINE_FN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerQW_layer,    // Overrides other layers
    my_layerLW_layer,    // Overrides other layers
    my_layerRS_layer,    // Overrides other layers
    my_layerFN_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QW));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LW));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
    return state;
}
