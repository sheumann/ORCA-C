/****************************************************************
*
*  stddef.h - Standard Language Additions
*
*  February 1989
*  Mike Westerfield
*
*  Copyright 1989, 1993
*  Byte Works, Inc.
*
****************************************************************/

#ifndef __stddef__
#define __stddef__

#ifndef NULL
#define NULL  (void *) 0L
#endif

typedef long ptrdiff_t;

#ifndef __size_t__
#define __size_t__ 1
typedef unsigned long size_t;
#endif

typedef unsigned short wchar_t;

#define offsetof(type,member) ((size_t) (&(((type *)0L)->member)))

#endif
