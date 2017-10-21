/****************************************************************
*
*  float.h - limits on the size of real numbers
*
*  October 1989
*  Mike Westerfield
*
*  Copyright 1989
*  Byte Works, Inc.
*
****************************************************************/

#ifndef __float__
#define __float__

#define FLT_ROUNDS      1

#define FLT_RADIX       2

#define FLT_MANT_DIG    24
#define DBL_MANT_DIG    53
#define LDBL_MANT_DIG   53

#define FLT_DIG         6
#define DBL_DIG         15
#define LDBL_DIG        15

#define FLT_MIN_EXP     -125
#define DBL_MIN_EXP     -1021
#define LDBL_MIN_EXP    -1021

#define FLT_MIN_10_EXP  -37
#define DBL_MIN_10_EXP  -307
#define LDBL_MIN_10_EXP -307

#define FLT_MAX_EXP     128
#define DBL_MAX_EXP     1024
#define LDBL_MAX_EXP    1024

#define FLT_MAX_10_EXP  38
#define DBL_MAX_10_EXP  308
#define LDBL_MAX_10_EXP 308

#define FLT_MAX         3.40282347E+38F
#define DBL_MAX         1.7976931348623157E+308
#define LDBL_MAX        1.7976931348623157E+308

#define FLT_EPSILON     1.19209290E-07F
#define DBL_EPSILON     2.2204460492503131E-16
#define LDBL_EPSILON    2.2204460492503131E-16

#define FLT_MIN         1.17549435E-38F
#define DBL_MIN         2.2250738585072014E-308
#define LDBL_MIN        2.2250738585072014E-308

#endif
