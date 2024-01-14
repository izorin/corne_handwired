// Copyright 2023 ivan (@iazorin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#define SPLIT_USB_DETECT

#define SOFT_SERIAL_PIN D2
#define SELECT_SOFT_SERIAL_SPEED 1


 #define MATRIX_COLS 12
 #define MATRIX_ROWS 8

#define MATRIX_COL_PINS {F6, F7, B1, B3, B2, B6}
#define MATRIX_ROW_PINS {D7, E6, B4, B5}

// #define MATRIX_COL_PINS_RIGHT {F7, F6, B1, B3, B2, B6}
#define MATRIX_COL_PINS_RIGHT {B6, B2, B3, B1, F6, F7}
#define MATRIX_ROW_PINS_RIGHT {D7, E6, B4, B5}

#define TAPPING_TOGGLE 2
