#include QMK_KEYBOARD_H






/* LAYER NAMES
   ==========================================================================
   1. To create a layer, define a (readable) name and set layer value
   2. Under "Layer definitions" section, define keymaps
   ========================================================================== */

enum layer_names {
    L_QWERTY,
    L_LOWER,
    L_RAISE,
    L_ADJUST,
};

/* TAP DANCE
   ==========================================================================
   1. Define TD names here
   2. Register action in tap_dance_actions[]
   ========================================================================== */
enum {
  TD_BRC = 0,
  TD_MIN,
  TD_GV_ESC,
  TD_BS
};

/* Custom Macros
   ==========================================================================
   1. Define Macro names here
   2. Register action in process_record_user()
   ========================================================================== */
enum custom_keycodes {
    MY_DQUO = SAFE_RANGE,
    MY_QUOT,
    MY_GRV,
    MY_TILD,
    MY_RNDM
};

// Random string stuff
static int lower = (int) KC_A;
static int upper = (int) KC_Z;
uint16_t random_keycode(void) {
  return lower + (rand() % (upper - lower + 1));
};
// Random string stuff end


/* CUSTOM KEYMAPS
   ========================================================================== */

// Tap dances
#define TD_ESCP TD(TD_GV_ESC)           // Tap for grave, twice for escape
#define TD_MINS TD(TD_MIN)              // Tap for minus, twice for equal
#define TD_BRAC TD(TD_BRC)              // Tap for open brace, twice for close

// Layers
#define LT1_TAB LT(L_LOWER, KC_TAB)     // Tap for tab, hold for LOWER
#define LT2_ESC LT(L_RAISE, KC_ESC)     // Tap for esc, hold for RAISE
#define LT2_ENT LT(L_RAISE, KC_ENT)     // Tap for enter, hold for RAISE
#define LT1_DEL LT(L_LOWER, KC_DEL)     // Tap for del, hold for LOWER
#define LT2_BSP LT(L_RAISE, KC_BSPACE)     // Tap for bsp, hold for RAISE
#define LT1_SPC LT(L_LOWER, KC_SPC)     // Tap for space, hold for LOWER
#define LT2_LPRN LT(L_RAISE, S(KC_LPRN))    // Tap for (, hold for RAISE
#define LT3_RPRN LT(L_ADJUST, S(KC_RPRN))     // Tap for ), hold for ADJUST

#define LT3_RNDM LT(L_ADJUST, MY_RNDM)     // Tap for random laugh, hold for ADJUST

// Modifiers
#define LG_ZMIN LGUI(KC_EQUAL)          // Command + plus (zoom in)
#define LG_ZMOT LGUI(KC_MINUS)          // Command + minus (zoom out)
#define LG_ZMEX LGUI(KC_ESC)          // Command + esc (exit)

#define MT_SHFT MT(MOD_RSFT, KC_ENT)    // Tap for enter, hold for shift
#define MT_BSSH MT(MOD_RSFT, KC_BSLASH) // Tap for backslash, hold for shift
#define MT_MSSH MT(MOD_RSFT, KC_EQUAL)  // Tap for equal, hold for shift
#define MT_SHGR MT(MOD_RSFT, KC_GRAVE)  // Tap for grave, hold for shift
#define MT_SHCL MT(MOD_LSFT, KC_CAPS)   // Tap for caps lock, hold for shift
//#define MT_SHMN MT(MOD_LSFT, KC_MINUS)   // Tap for caps lock, hold for shift
#define MT_SHMN MT(MOD_LSFT, KC_PGDN)   // Tap for page down, hold for shift
#define MT_SHCR MT(MOD_RSFT, KC_BSLASH)   // Tap for bslash, hold for shift

#define MT_HILF S(A(KC_LEFT))           // Press for shift + alt + left
#define MT_HIRT S(A(KC_RGHT))           // Press for shift + alt + right
#define MT_UNTB S(KC_TAB)               // Press for shift + tab







/* Layer definitions
   ========================================================================== */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------------------.
 * | ESC RS|  1 !  |  2 @  |  3 #  |  4 $  |  5 %  |  6 ^  |  7 &  |  8 *  |  9 (  |  0 )  | BSP RS|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TAB LW|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | DEL LW|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   +   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |  ENT  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |- / LSH|   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | SF/ \ |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  LCTL |       |  GUI  |  ALT  | ( LSFT|     SP/LW     | ) RSFT|   ←   |   ↑   |   ↓   |   →   |
 * `-----------------------------------------------------------------------------------------------
 */

[L_QWERTY] = LAYOUT_preonic_grid(
/*01           02           03           04           05           06           07           08          09          10          11          12         */
  KC_ESC,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPACE, \
  KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,    \
  KC_PGUP,     KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,    \
  MT_SHMN,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MT_SHCR,   \
//KC_LCTL,     TT(L_ADJUST),KC_LGUI,     KC_LALT,     KC_LSPO,     LT1_SPC,     LT1_SPC,     KC_RSPC,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
  KC_LCTL,     KC_LBRC,     KC_RBRC,     KC_LALT,     LT1_SPC,     LT1_SPC,     LT2_ENT,     LT2_ENT,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT   \
),




 /* LOWER
 * ,-----------------------------------------------------------------------------------------------.
 * | ASHFT |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |   F7  |   F8  |   F9  |  F10  |  F11  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | UNTAB |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   +   |   "   |   ~   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | S+A+← | S+A+→ |       |       |       |       |       |   -   |   =   |   '   |   `   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |   {   |zoom in|zoom ex|   }   |   <   |   >   |   ?   |   |   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |   [   |       |       |   ]   |  <<   |page dn|page up|  >>   |
 * `-----------------------------------------------------------------------------------------------'
 */

[L_LOWER] = LAYOUT_preonic_grid(
/*01          02          03          04          05          06                07          08          09          10          11          12         */
  KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,            KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,    \
  MT_UNTB,    S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),          S(KC_6),    S(KC_7),    S(KC_MINUS),S(KC_EQUAL),MY_DQUO,    MY_TILD,   \
  LG_ZMIN,    LCTL(KC_A), LCTL(KC_S), LGUI(KC_D), LCTL(KC_F), _______,          _______,    _______,    KC_MINUS,   KC_EQUAL,   MY_QUOT,    MY_GRV,    \
  LG_ZMOT,    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_DOT),     MT_HILF,    MT_HIRT,    S(KC_COMM), S(KC_DOT),  S(KC_SLSH), KC_PIPE,   \
  LG_ZMEX,    S(KC_LBRC), S(KC_RBRC), MY_RNDM,    _______,    _______,          _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END     \
),






/* RAISE
 * ,-----------------------------------------------------------------------------------------------.
 * | ASHFT | BTSDN | BTSUP |  VUP  |  VDN  |       |       |   /   |   *   |   (   |   )   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |   7   |   8   |   9   |   +   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |   4   |   5   |   6   |   -   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  CAP  |       |       |       |       |       |       |   1   |   2   |   3   |   /   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   0   |   .   |   ,   |       |)
 * `-----------------------------------------------------------------------------------------------'
 */
[L_RAISE] = LAYOUT_preonic_grid(
/*01          02          03          04          05          06          07          08          09          10          11          12         */
  KC_ASTG,    KC_F1,      KC_F2,      KC_VOLU,    KC_VOLD,    _______,    _______,    KC_PSLS,    KC_PAST,    KC_LPRN,    KC_RPRN,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P7,      KC_P8,      KC_P9,      KC_PLUS,    _______,    \
  S(KC_EQUAL),C(KC_A),    C(KC_S),    _______,    _______,    _______,    _______,    KC_P4,      KC_P5,      KC_P6,      KC_MINUS,   _______,    \
  S(KC_MINUS),C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    _______,    _______,    KC_P1,      KC_P2,      KC_P3,      KC_PSLS,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P0,      KC_PDOT,    KC_COMM,    _______     \
),





/* Adjust (Raise + Lower together)
 * ,-----------------------------------------------------------------------------------------------.
 * |  F12  |  FN2  |  FN3  |  FN4  |  FN5  |  FN6  |  FN7  |  FN8  |  FN9  |  F10  |  F11  |  FN1  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TOG SF|       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | DESGN |       |       |       |       |       |       |       |       |       |       | RESET |
 * `-----------------------------------------------------------------------------------------------'
 */

[L_ADJUST] = LAYOUT_preonic_grid(
/*01          02               03          04          05          06          07          08          09          10          11          12         */
  KC_F12,     KC_F1,           KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     \
  _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  KC_ASTG,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    DF(L_QWERTY),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RESET     \
)

};

// this function
uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);
}






/* BLANK
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
/*
[L_BLANK] = LAYOUT_preonic_grid(
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______     \
),
*/






/* Tap Dance Definitions
   ========================================================================== */

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Left Brace, twice for Right Brace
  [TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  //Tap once for Minus, twice for Equal
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
  // Tap once for Grave, tap twice for Escape
  [TD_GV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESCAPE)
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MY_DQUO:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("\" ");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case MY_QUOT:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("' ");
        } else {
            // when keycode QMKURL is released
        }
        break;

    case MY_GRV:
        if (record->event.pressed) {
           SEND_STRING("` "); // selects all and copies
        }
        break;

    case MY_TILD:
        if (record->event.pressed) {
           SEND_STRING("~ "); // selects all and copies
        }
        break;

    case MY_RNDM:
          if (record->event.pressed) {
            // when keycode RANDOMLAUGH is pressed
            for(int i=0;i<=10;i++) {
                tap_code(random_keycode());
            }
            tap_code(KC_ENT);
          } else {
            // when keycode RANDOMLAUGH is released
          }
          break;
    }
    return true;
};
