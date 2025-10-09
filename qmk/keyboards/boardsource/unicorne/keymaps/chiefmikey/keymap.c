#include QMK_KEYBOARD_H

/*
 * ChiefMikey's Unicorne Keymap
 *
 * A custom keymap for the Unicorne split keyboard featuring:
 * - Colemak-DH base layout with QWERTY fallback
 * - Custom application launchers (macOS shortcuts)
 * - Screenshot utilities
 * - RGB controls and media keys
 * - Tap dance for mouse buttons
 *
 * Layers:
 * - _BASE: Main typing layer
 * - _LOWER: Numbers, symbols, and navigation
 * - _RAISE: Function keys, RGB controls, and media
 * - _ADJUST: System functions and app launchers
 */

// Layer definitions
enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Custom keycodes
enum custom_keycodes {
    EMAIL = SAFE_RANGE,    // Send email address
    BIT,                   // Send bitwarden string
    SC_SELECT,             // Screenshot selection (Cmd+Shift+4)
    SC_AREA,               // Screenshot area (Cmd+Shift+5)
    SC_AREA2,              // Screenshot area with Enter (Cmd+Shift+5+Enter)
    ITERM2,                // Launch iTerm2 (Cmd+Option+I)
    VSCODE,                // Launch VS Code (Cmd+Option+V)
    CHROME,                // Launch Chrome (Cmd+Option+C)
    SLACK,                 // Launch Slack (Cmd+Option+L)
    SPOTIFY                // Launch Spotify (Cmd+Option+S)
};

// Tap dance actions
enum {
    B1_B2
};

// Define tap dance actions
tap_dance_action_t tap_dance_actions[] = {
    [B1_B2] = ACTION_TAP_DANCE_DOUBLE(KC_MS_BTN1, KC_MS_BTN2),
};

// Key aliases for readability
#define MT_LCTL_GRV    MT(MOD_LCTL, KC_GRV)   // Control when held, Grave when tapped
#define MT_LALT_SPC    MT(MOD_LALT, KC_SPC)   // Alt when held, Space when tapped
#define LT_ADJ_ENT     LT(_ADJUST, KC_ENT)    // Adjust layer when held, Enter when tapped
#define LT_LOWER_SPC   LT(_LOWER, KC_SPC)     // Lower layer when held, Space when tapped
#define LT_RAISE_BSLS  LT(_RAISE, KC_RGUI)    // Raise layer when held, right cmd when tapped

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                // Just type the email directly
                SEND_STRING("wolfemikl@gmail.com");
            }
            break;

        case BIT:
            if (record->event.pressed) {
                SEND_STRING("644215-341561-007271-388454-339020-202070-542564-646173");
            }
            break;
        case SC_SELECT:
            if (record->event.pressed) {
                // Use direct key combination for screenshot selection
                SEND_STRING(SS_LGUI(SS_LSFT("4")));
            }
            break;

        case SC_AREA:
            if (record->event.pressed) {
                // Use direct key combination for screenshot area
                SEND_STRING(SS_LGUI(SS_LSFT("5")));
            }
            break;
        case SC_AREA2:
            if (record->event.pressed) {
                // Use direct key combination for screenshot area and enter
                SEND_STRING(SS_LGUI(SS_LSFT("5")));
                wait_ms(100);
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case ITERM2:
            if (record->event.pressed) {
                // Use direct key combination - set up Cmd+Option+I in macOS System Preferences
                SEND_STRING(SS_LGUI(SS_LALT("i")));
            }
            break;
        case VSCODE:
            if (record->event.pressed) {
                // Use direct key combination - set up Cmd+Option+V in macOS System Preferences
                SEND_STRING(SS_LGUI(SS_LALT("v")));
            }
            break;
        case CHROME:
            if (record->event.pressed) {
                // Use direct key combination - set up Cmd+Option+C in macOS System Preferences
                SEND_STRING(SS_LGUI(SS_LALT("c")));
            }
            break;
        case SLACK:
            if (record->event.pressed) {
                // Use direct key combination - set up Cmd+Option+L in macOS System Preferences
                SEND_STRING(SS_LGUI(SS_LALT("l")));
            }
            break;
        case SPOTIFY:
            if (record->event.pressed) {
                // Use direct key combination - set up Cmd+Option+S in macOS System Preferences
                SEND_STRING(SS_LGUI(SS_LALT("s")));
            }
            break;
    }
    return true;
}

// Keymap definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _BASE Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Ctrl/`|   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |-------.    ,-------|   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI |Alt/SPC|Adj/ENT|      /       \      |Adj/ENT|Low/SPC|Rse/BS|
 *                   `----------------------'     '---------''---------------------------'
 */
[_BASE] = LAYOUT(
    KC_ESC,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    MT_LCTL_GRV,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                                KC_LGUI, MT_LALT_SPC, LT_ADJ_ENT,            LT_ADJ_ENT, LT_LOWER_SPC, LT_RAISE_BSLS
),
/* _LOWER Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |                    |   7  |   8  |   9  |   0  |   =  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   @  |   $  |   [  |   (  |   {  |                    |   }  |   )  |   ]  |   -  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Home |   &  |   #  |   %  |   !  |   +  |-------.    ,-------|   ^  |      |      |      |   \  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   *  |      |      |      /       \      |      |      |      |
 *                   `----------------------'     '---------''----------------------'
 */
[_LOWER] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                       KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  KC_BSPC,
    KC_TAB,  KC_AT,   KC_DLR,  KC_LBRC, KC_LPRN, KC_LCBR,                    KC_RCBR, KC_RPRN, KC_RBRC, KC_MINS, _______, _______,
    KC_HOME, KC_AMPR, KC_HASH, KC_PERC, KC_EXLM, KC_PLUS,                    KC_CIRC, _______, _______, _______, KC_BSLS, KC_DEL,
                                    KC_ASTR, _______, _______,            _______, _______, _______
),

/* _RAISE Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  +   |  1   |  2   |  3   |  4   |  5   |                    |RGB_SAI|RGB_VAI|RGB_SPI|Play |Vol+  |Mute |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  -   |  6   |  7   |  8   |  9   |  0   |-------.    ,-------|RGB_SAD|RGB_VAD|RGB_SPD|Prev |Vol-  |Next |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |RGB_HUD|RGB_HUI|RGB_RMOD|    /       \      |RGB_MOD|RGB_HUI|      |
 *                   `----------------------'     '---------''----------------------'
 */
[_RAISE] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                 KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_PPLS,  KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,                 RGB_SAI,  RGB_VAI,  RGB_SPI,  KC_MPLY,  KC_VOLU,  KC_MUTE,
    KC_PMNS,  KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,                 RGB_SAD,  RGB_VAD,  RGB_SPD,  KC_MPRV,  KC_VOLD,  KC_MNXT,
                                   RGB_HUD,  RGB_HUI,  RGB_RMOD,              RGB_MOD,  RGB_HUI,  _______
),

/* _ADJUST Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |SC_SEL|                    |EMAIL |  Up  |      |      |      |Clicky|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |ITERM2|VSCODE|SC_AREA|SC_AR2|                    | Left | Down |Right |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |CHROME|SLACK |SPOTIFY|      |-------.    ,-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |RGB_TOG|      |QK_BOOT|      /       \      |TD(B1_B2)|      |      |
 *                   `----------------------'     '---------''----------------------'
 */
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______,_______, SC_SELECT,                EMAIL, _______,   KC_UP, _______, _______, QK_AUDIO_CLICKY_TOGGLE,
    _______, _______, ITERM2, VSCODE, SC_AREA, SC_AREA2,                _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, CHROME, SLACK,  SPOTIFY, _______,                 _______, _______, _______, _______, _______, _______,
                                RGB_TOG, _______, QK_BOOT,                TD(B1_B2), _______, BIT
),
};
