#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QW,     /* Base layer, QWERTY */
  _LW,     /* LOWER */
  _RS,     /* RAISE */
  _FN,     /* FUNCTION */
  _AD,     /* ADJUST */
};

#define LOWER     MO(_LW)
#define RAISE     MO(_RS)
#define FUNCTION  MO(_FN)
#define ADJUST    MO(_AD)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
//  LOWER,
//  RAISE,
//  ADJUST,
//  FUNC,
  VRSN,
  KMAP,
  RST,
};

/* Tap Dance Declarations */
enum {
  SCL = 0,
  QUO,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
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

/* Fillers to make layering more clear */
#define XXXXXXX KC_NO
#define ___T___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QW] = LAYOUT(
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  FUNCTION,      KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
  OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LW] = LAYOUT(
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, _______, KC_PIPE,
  _______, _______,  _______, _______, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RS] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_MUTE, _______, KC_BSLS,
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |RGBMOD|RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |RGBRMO|RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_AD] = LAYOUT(
  TSKMGR,  _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL,
  _______, _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_STEP,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RST
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RST  ,  KMAP  ,  VRSN  , _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

/* Tap Dance Definitions */
tap_dance_action_t tap_dance_actions[] = {
  /* Shifting for double quote and semicolon */
  [SCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [QUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};


#ifndef QMK_VERSION
  #define QMK_VERSION "VER"
  #define QMK_BUILDDATE "DATE"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    case KMAP:
      if (record->event.pressed) {
        SEND_STRING("http://www.keyboard-layout-editor.com/#/gists/0e924c013c75d1dc4bbf51806b5500ee");
      }
      return false;
      break;

    case RST:
      rgblight_disable_noeeprom();

      _delay_ms(250);


      reset_keyboard();
      return false;
      break;

  }
  return true;
}

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layerQW_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MINE_QW}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layerLW_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MINE_LW}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layerRS_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MINE_RS}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layerFN_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MINE_FN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layerAD_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MINE_AD}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerQW_layer,    // Overrides other layers
    my_layerLW_layer,    // Overrides other layers
    my_layerRS_layer,    // Overrides other layers
    my_layerFN_layer,    // Overrides other layers
    my_layerAD_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL+3);
    rgblight_set_speed_noeeprom(180);
}

/*
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QW));
    return state;
}*/

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LW, _RS, _AD);

    rgblight_set_layer_state(1, layer_state_cmp(state, _LW));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(4, layer_state_cmp(state, _AD));
    return state;
}

