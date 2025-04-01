/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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


enum custom_keycodes {
    STR1 = SAFE_RANGE,
    M_EURO,
    M_RUB,
    M_POUND,
    M_PLUSMINUS,
    M_SECTIONSIGN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case STR1:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("somestring");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case M_EURO:
        if (record->event.pressed) {
            register_unicode(0x20AC);
            return false;
        }
        break;

    case M_RUB:
        if (record->event.pressed) {
            register_unicode(0x20BD);
            return false;
        }
        break;
    case M_POUND:
        if (record->event.pressed) {
            register_unicode(0x00A3);
            return false;
        }
        break;
    case M_PLUSMINUS:
        if (record->event.pressed) {
            register_unicode(0x00B1);
            return false;
        }
        break;
    case M_SECTIONSIGN:
        if (record->event.pressed) {
            register_unicode(0x00A7);
            return false;
        }
        break;
    }
    return true;
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _NAVNUM,
    _SYM,
    _FUNC,
    _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_QWERTY] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	KC_U,				KC_I,				KC_O,				KC_P,
	MT(MOD_LGUI, KC_A),	MT(MOD_LALT, KC_S),	MT(MOD_LCTL, KC_D),	MT(MOD_LSFT, KC_F),	KC_G,			KC_H,	MT(MOD_LSFT, KC_J),	MT(MOD_LCTL, KC_K),	MT(MOD_LALT, KC_L),	MT(MOD_LGUI, KC_SCLN),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_N,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_1,				LT(3,KC_DEL),		LT(1,KC_SPC),		KC_TAB,				KC_CAPS,		KC_NUM,	KC_ESC,				KC_BSPC,			LT(2,KC_ENT),		KC_4
),

/* COLEMAK
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |                      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |                      |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   K  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_COLEMAK] = LAYOUT(
	KC_Q,				KC_W,				KC_F,				KC_P,				KC_G,			KC_J,	KC_L,				KC_U,				KC_Y,				KC_SCLN,
	MT(MOD_LGUI, KC_A),	MT(MOD_LALT, KC_R),	MT(MOD_LSFT, KC_S),	MT(MOD_LCTL, KC_T),	KC_D,			KC_H,	MT(MOD_RCTL, KC_N),	MT(MOD_RSFT, KC_E),	MT(MOD_RALT, KC_I),	MT(MOD_RGUI, KC_O),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_K,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_1,				LT(3,KC_DEL),		LT(1,KC_SPC),		KC_TAB,				KC_CAPS,		KC_NUM,	KC_ESC,				KC_BSPC,			LT(2,KC_ENT),		KC_4
),

/* NAVNUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   0  |   1  |   2  |   3   |  -  |                      | PgUP | Home |  Up  |  End  | Ins |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   /  |   4  |   5  |   6  |   +  |                      | PgDn | Left | Down | Right | Del |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   *  |   7  |   8  |   9  |   =  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAVNUM] = LAYOUT(
	KC_0,		KC_1,		    KC_2,			KC_3,	    KC_MINS,			KC_PGUP,	KC_HOME,KC_UP,		KC_END,			KC_INS,
	MT(MOD_LGUI,KC_SLSH),	MT(MOD_LALT,KC_4),		    MT(MOD_LSFT,KC_5),		    MT(MOD_LCTL,KC_6),	    KC_PLUS,			KC_PGDN,	MT(MOD_RCTL,KC_LEFT),MT(MOD_RSFT,KC_DOWN),	MT(MOD_RALT,KC_RIGHT),		MT(MOD_RGUI,KC_DEL),
	KC_ASTR,	KC_7,			KC_8,			KC_9,		KC_EQL,				KC_NO,		KC_NO,	KC_NO,		KC_NO,			KC_NO,
	KC_TAB,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,			KC_NUM,		KC_ESC,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |                      |   ^  |   &  |   *  |   (  |  )   |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   \  |   §  |   ±  |   £  |   `  |                      |   '  |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   |  |   ₽  |      |   €  |   "  |  |CAPS |    |NUMLK|  |   ~  |   _  |   +  |   {  |   }  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYM] = LAYOUT(
	KC_EXLM,	KC_AT,			KC_HASH,		KC_DLR, 	KC_PERC,		KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,		KC_RPRN,
	MT(MOD_LGUI,KC_BSLS),	MT(MOD_LALT,M_SECTIONSIGN),	MT(MOD_LSFT,M_PLUSMINUS),	MT(MOD_LCTL,M_POUND),	KC_GRV, 		KC_QUOT,	MT(MOD_RCTL, KC_MINS),	MT(MOD_RSFT, KC_EQL),		MT(MOD_RALT,KC_LBRC),		MT(MOD_RGUI,KC_RBRC),
	KC_PIPE,	M_RUB,			KC_NO,		    M_EURO,	    KC_DQT,		    KC_TILD,	KC_UNDS,	KC_PLUS,	KC_LCBR,		KC_RCBR,
	KC_1,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,		KC_NUM,		KC_ESC,		KC_BSPC,	LT(2,KC_ENT),	KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   %  |   @  |   [  |   ]  |   \  |                      |      |      |   ^  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   #  |   !  |   (  |   )  |   |  |                      |   _  |   '  |   "  |   ~  |   `  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   $  |   £  |   {  |   }  |   &  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
/* [_SYM] = LAYOUT( */
/* 	KC_PERC,	KC_AT,			KC_LBRC,		KC_RBRC,	KC_BSLS,		KC_NO,		KC_NO,		KC_CIRC,	KC_NO,			KC_NO, */
/* 	KC_HASH,	KC_EXLM,		KC_LPRN,		KC_RPRN,	KC_PIPE,		KC_UNDS,	KC_QUOT,	KC_DQT,		KC_TILD,		KC_GRV, */
/* 	KC_DLR,		KC_NO,			KC_LCBR,		KC_RCBR,	KC_AMPR,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO, */
/* 	KC_1,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,		KC_NUM,		KC_ESC,		KC_BSPC,	LT(2,KC_ENT),	KC_4 */
/* ), */

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |MSLCLK| MSUP |MSRCLK|      |                      |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Caps |  MSL | MSDW | MSR  | PRTSC|                      |  F6  |  F7  |  F8  |  F9  |  F10  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |            |  |CAPS |    |NUMLK|  |  F11 |  F12 |  F13 |  F14 |  F15 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
	STR1,	MS_BTN1,	MS_UP,			MS_BTN2,KC_NO,			KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,
	KC_CAPS,MS_LEFT,	MS_DOWN,		MS_RGHT,KC_PSCR,			KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,
	QK_BOOT,KC_NO,		KC_NO,			KC_NO,	KC_NO,	        KC_F11,	KC_F12,	KC_F13,	KC_F14, KC_F15,
	KC_1,	LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,	KC_CAPS,		KC_NUM,	KC_ESC,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),
};
