
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

#include "fix16.h"

#define FIXMATH_NO_64BIT
#define FIXMATH_OPTIMIZE_8BIT


FIX16_RAMFUNC fix16_t fix16_mul_new_16_16(fix16_t inArg0, fix16_t inArg1)
{
  // Each argument is divided to 16-bit parts.
  // AB
  // * CD
  // -----------
  // BD 16 * 16 -> 32 bit products
  // CB
  // AD
  // AC
  // |----| 64 bit product
  int32_t A = (inArg0 >> 16), C = (inArg1 >> 16);
  uint32_t B = (inArg0 & 0xFFFF), D = (inArg1 & 0xFFFF);

  int32_t AC = A*C;
  int32_t AD_CB = A*D + C*B;
  uint32_t BD = B*D;

  int32_t product_hi = AC + (AD_CB >> 16);

  // Handle carry from lower 32 bits to upper part of result.
  uint32_t ad_cb_temp = AD_CB << 16;
  uint32_t product_lo = BD + ad_cb_temp;
  if (product_lo < BD)
    product_hi++;

#ifndef FIXMATH_NO_OVERFLOW
  // The upper 17 bits should all be the same (the sign).
  if (product_hi >> 31 != product_hi >> 15)
    return fix16_overflow;
#endif

#ifdef FIXMATH_NO_ROUNDING
  return (product_hi << 16) | (product_lo >> 16);
#else
  // Subtracting 0x8000 (= 0.5) and then using signed right shift
  // achieves proper rounding to result-1, except in the corner
  // case of negative numbers and lowest word = 0x8000.
  // To handle that, we also have to subtract 1 for negative numbers.
  uint32_t product_lo_tmp = product_lo;
  product_lo -= 0x8000;
  product_lo -= (uint32_t)product_hi >> 31;
  if (product_lo > product_lo_tmp)
    product_hi--;

  // Discard the lowest 16 bits. Note that this is not exactly the same
  // as dividing by 0x10000. For example if product = -1, result will
  // also be -1 and not 0. This is compensated by adding +1 to the result
  // and compensating this in turn in the rounding above.
  fix16_t result = (product_hi << 16) | (product_lo >> 16);
  result += 1;
  return result;
#endif
}




//=============================================================================
// Alternative 32-bit implementation of fix16_div. Fastest on e.g. Atmel AVR.
// This does the division manually, and is therefore good for processors that
// do not have hardware division.
//=============================================================================
#if defined(FIXMATH_OPTIMIZE_8BIT)
FIX16_RAMFUNC fix16_t fix16_div(fix16_t a, fix16_t b)
{
  // This uses the basic binary restoring division algorithm.
  // It appears to be faster to do the whole division manually than
  // trying to compose a 64-bit divide out of 32-bit divisions on
  // platforms without hardware divide.
  
  if (b == 0)
  {
#ifdef FIX16_OVERFLOW_DETECT
	fault_mask |= FAULT_FIX16_OVERFLOW;
	fault(0);
	return fix16_overflow;
#else
	if ((a >= 0) == (b >= 0))
		return fix16_max;
	else
		return fix16_min;
#endif
  }
  
  uint32_t remainder = (a >= 0) ? a : (-a);
  uint32_t divider = (b >= 0) ? b : (-b);

  uint32_t quotient = 0;
  uint32_t bit = 0x10000;
  
  // The algorithm requires D >= R
  while (divider < remainder)
  {
    divider <<= 1;
    bit <<= 1;
  }
  
  #ifndef FIXMATH_NO_OVERFLOW
  if (!bit)
  {
#ifdef FIX16_OVERFLOW_DETECT
	fault_mask |= FAULT_FIX16_OVERFLOW;
	fault(0);
	return fix16_overflow;
#else
	if ((a >= 0) == (b >= 0))
		return fix16_max;
	else
		return fix16_min;
#endif
  }
  #endif
  
  if (divider & 0x80000000)
  {
    // Perform one step manually to avoid overflows later.
    // We know that divider's bottom bit is 0 here.
    if (remainder >= divider)
    {
        quotient |= bit;
        remainder -= divider;
    }
    divider >>= 1;
    bit >>= 1;
  }
  
  // Main division loop
  while (bit && remainder)
  {
    if (remainder >= divider)
    {
        quotient |= bit;
        remainder -= divider;
    }
    
    remainder <<= 1;
    bit >>= 1;
  }   
      
  #ifndef FIXMATH_NO_ROUNDING
  if (remainder >= divider)
  {
    quotient++;
  }
  #endif
  
  fix16_t result = quotient;
  
  // Figure out the sign of result
  if ((a ^ b) & 0x80000000)
  {
    #ifndef FIXMATH_NO_OVERFLOW
    if (result == fix16_min)
    {
#ifdef FIX16_OVERFLOW_DETECT
	fault_mask |= FAULT_FIX16_OVERFLOW;
	fault(0);
	return fix16_overflow;
#else
	if ((a >= 0) == (b >= 0))
		return fix16_max;
	else
		return fix16_min;
#endif
    }
    #endif
    
    result = -result;
  }
  
  return result;
}
#endif


