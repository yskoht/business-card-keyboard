#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DEFAULT 0
#define _RAISE 1
#define _LOWER 2

enum custom_keycodes {
  DEFAULT= SAFE_RANGE,
  RAISE,
  LOWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
    KC_A, KC_B,   KC_1, KC_2,
    KC_C, KC_D,   KC_3, KC_4
  ),
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),
};

static bool raise_pressed = false;
static bool lower_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
      }
      else {
        layer_off(_RAISE);
        if (raise_pressed) {
          register_code(KC_RCMD);
          unregister_code(KC_RCMD);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed= true;
        layer_on(_LOWER);
      }
      else {
        layer_off(_LOWER);
        if (lower_pressed) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        lower_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        raise_pressed = false;
        lower_pressed = false;
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
}

