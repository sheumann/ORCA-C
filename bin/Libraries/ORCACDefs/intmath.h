/********************************************
*
* Integer Math Tool Set
*
* Copyright Apple Computer, Inc.1986-90
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __INTMATH__
#define __INTMATH__

/* Error Codes */
#define imBadInptParam 0x0B01           /* bad input parameter */
#define imIllegalChar 0x0B02            /* Illegal character in string */
#define imOverflow 0x0B03               /* integer or long integer overflow */
#define imStrOverflow 0x0B04            /* string overflow */

/* Limit Values */
#define minLongint 0x80000000           /* minimum negative signed long integer */
#define minFrac 0x80000000              /* pinned value for negative Frac overflow */
#define minFixed 0x80000000             /* pinned value for negative Fixed overflow */
#define minInt 0x8000                   /* Minimum negative signed integer */
#define maxInt 0x7FFF                   /* Maximum positive signed integer */
#define maxUInt 0xFFFF                  /* Maximum positive unsigned integer */
#define maxLongint 0x7FFFFFFF           /* maximum positive signed Longint */
#define maxFrac 0x7FFFFFFF              /* pinned value for positive Frac overflow */
#define maxFixed 0x7FFFFFFF             /* pinned value for positive Fixed overflow */
#define maxULong 0xFFFFFFFFL            /* maximum unsigned Long */

struct IntDivRec {
   Word quotient;                       /* quotient from SDivide */
   Word remainder;                      /* remainder from SDivide */
   };
typedef struct IntDivRec IntDivRec, *IntDivRecPtr;

struct LongDivRec {
   Longint quotient;                    /* Quotient from LongDiv */
   Longint remainder;                   /* remainder from LongDiv */
   };
typedef struct LongDivRec LongDivRec, *LongDivRecPtr;

typedef LongDivRec DivRec, *DivRecPtr; /* for backward compatability */

struct LongMulRec {
   Longint lsResult;                    /* low 2 words of product */
   Longint msResult;                    /* High 2 words of product */
   };
typedef struct LongMulRec LongMulRec, *LongMulRecPtr;

struct WordDivRec {
   Word quotient;                       /* Quotient from UDivide */
   Word remainder;                      /* remainder from UDivide */
   };
typedef struct WordDivRec WordDivRec, *WordDivRecPtr;

extern pascal void IMBootInit(void) inline(0x010B,dispatcher);
extern pascal void IMStartUp(void) inline(0x020B,dispatcher);
extern pascal void IMShutDown(void) inline(0x030B,dispatcher);
extern pascal Word IMVersion(void) inline(0x040B,dispatcher);
extern pascal void IMReset(void) inline(0x050B,dispatcher);
extern pascal Boolean IMStatus(void) inline(0x060B,dispatcher);
extern pascal Integer Dec2Int(Pointer, Word, Boolean) inline(0x280B,dispatcher);
extern pascal Longint Dec2Long(Pointer, Word, Boolean) inline(0x290B,dispatcher);
extern pascal Frac Fix2Frac(Fixed) inline(0x1C0B,dispatcher);
extern pascal Longint Fix2Long(Fixed) inline(0x1B0B,dispatcher);
extern pascal void Fix2X(Fixed, ExtendedPtr) inline(0x1E0B,dispatcher);
extern pascal Fixed FixATan2(Longint, Longint) inline(0x170B,dispatcher);
extern pascal Fixed FixDiv(Longint, Longint) inline(0x110B,dispatcher);
extern pascal Fixed FixMul(Fixed, Fixed) inline(0x0F0B,dispatcher);
extern pascal Fixed FixRatio(Integer, Integer) inline(0x0E0B,dispatcher);
extern pascal Integer FixRound(Fixed) inline(0x130B,dispatcher);
extern pascal Fixed Frac2Fix(Frac) inline(0x1D0B,dispatcher);
extern pascal void Frac2X(Frac, ExtendedPtr) inline(0x1F0B,dispatcher);
extern pascal Frac FracCos(Fixed) inline(0x150B,dispatcher);
extern pascal Frac FracDiv(Longint, Longint) inline(0x120B,dispatcher);
extern pascal Frac FracMul(Frac, Frac) inline(0x100B,dispatcher);
extern pascal Frac FracSin(Fixed) inline(0x160B,dispatcher);
extern pascal Frac FracSqrt(Frac) inline(0x140B,dispatcher);
extern pascal Word Hex2Int(Pointer, Word) inline(0x240B,dispatcher);
extern pascal LongWord Hex2Long(Pointer, Word) inline(0x250B,dispatcher);
extern pascal LongWord HexIt(Word) inline(0x2A0B,dispatcher);
extern pascal Word HiWord(LongWord) inline(0x180B,dispatcher);
extern pascal void Int2Dec(Integer, Pointer, Word, Boolean) inline(0x260B,dispatcher);
extern pascal void Int2Hex(Word, Pointer, Word) inline(0x220B,dispatcher);
extern pascal void Long2Dec(Longint, Pointer, Word, Boolean) inline(0x270B,dispatcher);
extern pascal Fixed Long2Fix(Longint) inline(0x1A0B,dispatcher);
extern pascal void Long2Hex(LongWord, Pointer, Word) inline(0x230B,dispatcher);
extern LongDivRec LongDivide(Longint, Longint);
extern LongMulRec LongMul(Longint, Longint);
extern pascal Word LoWord(LongWord) inline(0x190B,dispatcher);
extern pascal Longint Multiply(Integer, Integer) inline(0x090B,dispatcher);
extern IntDivRec SDivide(Integer, Integer);
extern WordDivRec UDivide(Word, Word);
extern pascal Fixed X2Fix(ExtendedPtr) inline(0x200B,dispatcher);
extern pascal Frac X2Frac(ExtendedPtr) inline(0x210B,dispatcher);

#endif
