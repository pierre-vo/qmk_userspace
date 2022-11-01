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

#pragma once

#include "quantum.h"

//#ifdef USE_I2C
//#include <stddef.h>
//#ifdef __AVR__
//  #include <avr/io.h>
//  #include <avr/interrupt.h>
//#endif
//#endif

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L17, L16, L15, L14, L13, L12, L11,      \
    L27, L26, L25, L24, L23, L22, L21,      \
    L37, L36, L35, L34, L33, L32, L31,      \
    L47, L46, L45, L44, L43, L42,           \
              L55, L54,                     \
                        L53, L52,           \
                                  L56, L41, \
                                  L57, L51, \
         R11, R12, R13, R14, R15, R16, R17, \
         R21, R22, R23, R24, R25, R26, R27, \
         R31, R32, R33, R34, R35, R36, R37, \
              R42, R43, R44, R45, R46, R47, \
                        R54, R55,           \
              R52, R53,                     \
    R41, R56,                               \
    R51, R57                                \
  ) \
  { \
    { L51, L52, L53, L54, L55, L56, L57 }, \
    { L41, L42, L43, L44, L45, L46, L47 }, \
    { L31, L32, L33, L34, L35, L36, L37 }, \
    { L21, L22, L23, L24, L25, L26, L27 }, \
    { L11, L12, L13, L14, L15, L16, L17 }, \
    { R51, R52, R53, R54, R55, R56, R57 }, \
    { R41, R42, R43, R44, R45, R46, R47 }, \
    { R31, R32, R33, R34, R35, R36, R37 }, \
    { R21, R22, R23, R24, R25, R26, R27 }, \
    { R11, R12, R13, R14, R15, R16, R17 } \
}
