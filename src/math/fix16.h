
//=============================================================================
// Copyright (C) 2017, Active-Semi International
//
// THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
// AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
// APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
// (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
// ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
// DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
// ONLY BY CERTAIN AUTHORIZED PERSONS.
//
//=============================================================================

#ifndef __libfixmath_fix16_h__
#define __libfixmath_fix16_h__

#ifdef __cplusplus
extern "C"
{
#endif

/* These options may let the optimizer to remove some calls to the functions.
 * Refer to http://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html
 */
#ifndef FIXMATH_FUNC_ATTRS
# ifdef __GNUC__
#   define FIXMATH_FUNC_ATTRS __attribute__((nothrow, pure))
# else
#   define FIXMATH_FUNC_ATTRS
# endif
#endif

#define RAMFUNC_LINK

#ifdef RAMFUNC_LINK
#define FIX16_RAMFUNC PAC5XXX_RAMFUNC
#else
#define FIX16_RAMFUNC
#endif

#include <stdint.h>

#include "pac52XX.h"

#define FIXMATH_NO_OVERFLOW
#define FIXMATH_NO_ROUNDING

typedef int32_t fix16_t;

#define FOUR_DIV_PI  				0x145F3           	/*!< Fix16 value of 4/PI */
#define _FOUR_DIV_PI2				0xFFFF9840       	/*!< Fix16 value of -4/PI² */
#define X4_CORRECTION_COMPONENT		0x399A 				/*!< Fix16 value of 0.225 */
#define PI_DIV_4					0x0000C90F          /*!< Fix16 value of PI/4 */
#define THREE_PI_DIV_4				0x00025B2F      	/*!< Fix16 value of 3PI/4 */

#define fix16_max					0x7FFFFFFF 			/*!< the maximum value of fix16_t */
#define fix16_min					0x80000000 			/*!< the minimum value of fix16_t */
#define fix16_overflow				0x80000000 			/*!< the value used to indicate overflows when FIXMATH_NO_OVERFLOW is not specified */

#define fix16_pi					205887     			/*!< fix16_t value of pi */
#define fix16_e						78145     			/*!< fix16_t value of e */
#define fix16_one					0x00010000 			/*!< fix16_t value of 1 */
#define fix16_neg_one				0xFFFF0000			/*!< fix16_t value of -1 */


/* Conversion functions between fix16_t and float/integer.
 * These are inlined to allow compiler to optimize away constant numbers
 */
FIX16_RAMFUNC static inline fix16_t fix16_from_int(int a) { return a * fix16_one; }
FIX16_RAMFUNC static inline float fix16_to_float(fix16_t a) { return (float)a / fix16_one; }
FIX16_RAMFUNC static inline double fix16_to_dbl(fix16_t a) { return (double)a / fix16_one; }

FIX16_RAMFUNC static inline int fix16_to_int(fix16_t a)
{
#ifdef FIXMATH_NO_ROUNDING
    return a >> 16;
#else
    if (a >= 0)
        return (a + fix16_one / 2) / fix16_one;
    else
        return (a - fix16_one / 2) / fix16_one;
#endif
}

FIX16_RAMFUNC static inline fix16_t fix16_from_float(float a)
{
    float temp = a * fix16_one;
#ifndef FIXMATH_NO_ROUNDING
    temp += (temp >= 0) ? 0.5f : -0.5f;
#endif
    return (fix16_t)temp;
}

FIX16_RAMFUNC static inline fix16_t fix16_from_dbl(double a)
{
    double temp = a * fix16_one;
#ifndef FIXMATH_NO_ROUNDING
    temp += (temp >= 0) ? 0.5f : -0.5f;
#endif
    return (fix16_t)temp;
}

/* Subtraction and addition with (optional) overflow detection. */
#ifdef FIXMATH_NO_OVERFLOW

FIX16_RAMFUNC static inline  fix16_t fix16_add(fix16_t inArg0, fix16_t inArg1) { return (inArg0 + inArg1); }
FIX16_RAMFUNC static inline PAC5XXX_RAMFUNC fix16_t fix16_sub(fix16_t inArg0, fix16_t inArg1) { return (inArg0 - inArg1); }

#else

extern FIX16_RAMFUNC fix16_t fix16_add(fix16_t a, fix16_t b) FIXMATH_FUNC_ATTRS;
extern FIX16_RAMFUNC fix16_t fix16_sub(fix16_t a, fix16_t b) FIXMATH_FUNC_ATTRS;

/* Saturating arithmetic */
extern FIX16_RAMFUNC fix16_t fix16_sadd(fix16_t a, fix16_t b) FIXMATH_FUNC_ATTRS;
extern FIX16_RAMFUNC fix16_t fix16_ssub(fix16_t a, fix16_t b) FIXMATH_FUNC_ATTRS;

#endif

/*! Multiplies the two given fix16_t's and returns the result.
*/
extern FIX16_RAMFUNC  fix16_t fix16_mul(fix16_t inArg0, fix16_t inArg1) FIXMATH_FUNC_ATTRS;

/*! Divides the first given fix16_t by the second and returns the result.
*/
extern FIX16_RAMFUNC  fix16_t fix16_div(fix16_t inArg0, fix16_t inArg1) FIXMATH_FUNC_ATTRS;

#ifndef FIXMATH_NO_OVERFLOW
/*! Performs a saturated multiplication (overflow-protected) of the two given fix16_t's and returns the result.
*/
extern FIX16_RAMFUNC fix16_t fix16_smul(fix16_t inArg0, fix16_t inArg1) FIXMATH_FUNC_ATTRS;

/*! Performs a saturated division (overflow-protected) of the first fix16_t by the second and returns the result.
*/
extern FIX16_RAMFUNC fix16_t fix16_sdiv(fix16_t inArg0, fix16_t inArg1) FIXMATH_FUNC_ATTRS;
#endif

extern FIX16_RAMFUNC fix16_t fix16_mul_new_16_16(fix16_t inArg0, fix16_t inArg1) FIXMATH_FUNC_ATTRS;

#ifdef __cplusplus
}
#include "fix16.hpp"
#endif

#endif
