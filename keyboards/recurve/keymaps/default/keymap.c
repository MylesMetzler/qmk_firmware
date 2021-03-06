/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "recurve.h"

//make redox:default
//sudo avrdude -p atmega32u4 -P /dev/ttyS6 -c avr109 -U flash:w:redox_default.hex

#define ________ KC_TRNS
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP( /* Base */
      KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINUS,                                KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,                                 KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS, \
      KC_LOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_HOME,  KC_CAPS,            KC_DEL,    KC_PGUP,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,\
      OSM_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_END,   KC_PSCR,            KC_INSERT, KC_PGDN,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLASH, OSM_LSFT,\
      KC_LCTRL, KC_NO,    KC_LGUI,  KC_LALT,  OSL(1),   KC_BSPC,  KC_DEL,   MO(1),    KC_UP,    MO(1),     KC_ENT,   KC_SPC,   OSL(2),   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,\
                                                                            KC_LEFT,  KC_DOWN,  KC_RIGHT \
  ),
  /*  |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         */
  [1] = KEYMAP( /* Functuin keys */
      ________, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                                  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   ________, \
      ________, ________, ________, ________, ________, ________, ________,                               ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________,           ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________,           ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
                                                                            ________, ________, ________\
  ),
  /*  |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         */
  [2] = KEYMAP( /* Functuin keys */
      ________, ________, ________, ________, ________, ________, ________,                               ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________,                               ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________,           ________, ________, ________, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________,           ________, ________, ________, ________, ________, ________, ________, ________, \
      ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, \
                                                                            ________, ________, ________\
  )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
  DDRB |= (1<<4); // caps lock LED on pin B4
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    PORTB |= (1<<4);
  } else {
    PORTB &= ~(1<<4);
  }

}
