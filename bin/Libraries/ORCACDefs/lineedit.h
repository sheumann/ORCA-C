/********************************************
*
* LineEdit Tool Set
*
* Copyright Apple Computer, Inc.1986-90
* All Rights Reserved
*
* Copyright 1992, 1993, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __LINEEDIT__
#define __LINEEDIT__

/* Error Codes */
#define leDupStrtUpErr 0x1401           /* duplicate LEStartup call */
#define leResetError 0x1402             /* can't reset Line Edit */
#define leNotActiveErr 0x1403           /* Line Edit not active */
#define leScrapErr 0x1404               /* desk scrap too big to copy */

/* Justification Codes */
#define leJustLeft 0x0000
#define leJustCenter 0x0001
#define leJustFill 0x0002
#define leJustRight 0xFFFF

/* LEClassifyKey result values */
#define leKeyIsSpecial 0x8000
#define leKeyIsNumber 0x4000
#define leKeyIsHex 0x2000
#define leKeyIsAlpha 0x1000
#define leKeyIsNonControl 0x0800

struct LERec {
   Handle leLineHandle;
   Word leLength;
   Word leMaxLength;
   Rect leDestRect;
   Rect leViewRect;
   GrafPortPtr lePort;
   Word leLineHite;
   Word leBaseHite;
   Word leSelStart;
   Word leSelEnd;
   Word leActFlg;
   Word leCarAct;
   Word leCarOn;
   LongWord leCarTime;
   VoidProcPtr leHiliteHook;
   VoidProcPtr leCaretHook;
   Word leJust;
   Word lePWChar;
   };
typedef struct LERec LERec, *LERecPtr, **LERecHndl;

extern pascal void LEBootInit(void) inline(0x0114,dispatcher);
extern pascal void LEStartUp(Word, Word) inline(0x0214,dispatcher);
extern pascal void LEShutDown(void) inline(0x0314,dispatcher);
extern pascal Word LEVersion(void) inline(0x0414,dispatcher);
extern pascal void LEReset(void) inline(0x0514,dispatcher);
extern pascal Boolean LEStatus(void) inline(0x0614,dispatcher);
extern pascal void LEActivate(LERecHndl) inline(0x0F14,dispatcher);
extern pascal void LEClick(EventRecordPtr, LERecHndl) inline(0x0D14,dispatcher);
extern pascal void LECopy(LERecHndl) inline(0x1314,dispatcher);
extern pascal void LECut(LERecHndl) inline(0x1214,dispatcher);
extern pascal void LEDeactivate(LERecHndl) inline(0x1014,dispatcher);
extern pascal void LEDelete(LERecHndl) inline(0x1514,dispatcher);
extern pascal void LEDispose(LERecHndl) inline(0x0A14,dispatcher);
extern pascal void LEFromScrap(void) inline(0x1914,dispatcher);
extern pascal Word LEGetScrapLen(void) inline(0x1C14,dispatcher);
extern pascal Handle LEGetTextHand(LERecHndl) inline(0x2214,dispatcher);
extern pascal Word LEGetTextLen(LERecHndl) inline(0x2314,dispatcher);
extern pascal void LEIdle(LERecHndl) inline(0x0C14,dispatcher);
extern pascal void LEInsert(Pointer, Word, LERecHndl) inline(0x1614,dispatcher);
extern pascal void LEKey(Word, Word, LERecHndl) inline(0x1114,dispatcher);
extern pascal LERecHndl LENew(Rect *, Rect *, Word) inline(0x0914,dispatcher);
extern pascal void LEPaste(LERecHndl) inline(0x1414,dispatcher);
extern pascal Handle LEScrapHandle(void) inline(0x1B14,dispatcher);
extern pascal void LESetCaret(VoidProcPtr, LERecHndl) inline(0x1F14,dispatcher);
extern pascal void LESetHilite(VoidProcPtr, LERecHndl) inline(0x1E14,dispatcher);
extern pascal void LESetJust(Word, LERecHndl) inline(0x2114,dispatcher);
extern pascal void LESetScrapLen(Word) inline(0x1D14,dispatcher);
extern pascal void LESetSelect(Word, Word, LERecHndl) inline(0x0E14,dispatcher);
extern pascal void LESetText(Pointer, Word, LERecHndl) inline(0x0B14,dispatcher);
extern pascal void LETextBox(Pointer, Word, Rect *, Word) inline(0x1814,dispatcher);
extern pascal void LETextBox2(Pointer, Word, Rect *, Word) inline(0x2014,dispatcher);
extern pascal void LEToScrap(void) inline(0x1A14,dispatcher);
extern pascal void LEUpdate(LERecHndl) inline(0x1714,dispatcher);

extern pascal Pointer GetLEDefProc(void) inline(0x2414,dispatcher);

extern pascal Word LEClassifyKey(EventRecord) inline(0x2514,dispatcher);
      
#endif
