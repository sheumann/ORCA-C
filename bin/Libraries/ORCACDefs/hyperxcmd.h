/*********************************************************
*
* File: HyperXCMD.h
*
* Definition file for HyperCard XCMDs and XFCNs in C
* For use with HyperCard IIGS Version 1.1
*
* Copyright Apple Computer, Inc. 1990-91
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
*********************************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __HYPERXCMD__
#define __HYPERXCMD__

#define _CallBackVector  0x00E10220L

/* XCMDBlock constants for event.what... */
#define xOpenEvt 1000                   /* the first event after you are created */
#define xCloseEvt 1001                  /* your window is being forced close */
#define xHidePalettesEvt 1004           /* someone called HideHCPalettes */
#define xShowPalettesEvt 1005           /* someone called ShowHCPalettes */
#define xCursorWithin 1300              /* cursor is within the window */

/* XWindow styles */
#define xWindoidStyle 0
#define xRectStyle 1
#define xShadowStyle 2
#define xDialogStyle 3

typedef String(19) Str19, *String19Ptr, **String19Handle;
typedef String(31) Str31, *String31Ptr, **String31Handle;

struct XCMDBlock {
   int  paramCount;
   Handle params[16];
   Handle returnValue;
   Boolean passFlag;
   Word userID;
   Word returnStat;                     /* 0 if normal, 1 if error */
   };
typedef struct XCMDBlock XCMDBlock, *XCMDPtr;

struct XWEventInfo {
   WindowPtr eventWindow;
   EventRecord event;
   long eventParams[9];
   Handle eventResult;
   };
typedef struct XWEventInfo XWEventInfo, *XWEventInfoPtr; 

/**** HyperTalk Utilities ****/
extern pascal Handle EvalExpr(Str255) inline(0x0002,_CallBackVector);
extern pascal void SendCardMessage(Str255 msg) inline(0x0001,_CallBackVector);
extern pascal void SendHCMessage(Str255) inline(0x0005,_CallBackVector);

/**** Memory Utilities ****/
extern pascal Handle GetGlobal(Str255) inline(0x0012,_CallBackVector);
extern pascal void SetGlobal(Str255, Handle) inline(0x0013,_CallBackVector);
extern pascal void ZeroBytes(Ptr, long) inline(0x0006,_CallBackVector);

/**** String Utilities ****/
extern pascal Boolean GSStringEqual(GSString255Hndl, GSString255Hndl) inline(0x0022,_CallBackVector);
extern pascal void ScanToReturn(Ptr *) inline(0x001C,_CallBackVector);
extern pascal void ScanToZero(Ptr *) inline(0x001D,_CallBackVector);
extern pascal Boolean StringEqual(Str255, Str255) inline(0x001A,_CallBackVector);
extern pascal Longint StringLength(Ptr) inline(0x0003,_CallBackVector);
extern pascal Ptr StringMatch(Str255, Ptr) inline(0x0004,_CallBackVector);

/**** String Conversions ****/
extern pascal Str31 BoolToStr(Boolean) inline(0x0010,_CallBackVector);
extern pascal GSString255Hndl CopyGSString(GSString255Hndl) inline(0x0020,_CallBackVector);
extern pascal Str31 ExtToStr(Extended) inline(0x0011,_CallBackVector);
extern pascal GSString255Hndl GSConcat(GSString255Hndl, GSString255Hndl) inline(0x0021,_CallBackVector);
extern pascal Str255 GSToPString(GSString255Hndl) inline(0x001E,_CallBackVector);
extern pascal Handle GSToZero(GSString255Hndl) inline(0x0023,_CallBackVector);
extern pascal Str31 LongToStr(Longint) inline(0x000D,_CallBackVector);
extern pascal Str19 NumToHex(Longint, word) inline(0x000F,_CallBackVector);
extern pascal Str31 NumToStr(Longint) inline(0x000E,_CallBackVector);
extern pascal void PointToStr(Point, Str255) inline(0x002D,_CallBackVector); 
extern pascal Handle PasToZero(Str255) inline(0x0007,_CallBackVector);
extern pascal GSString255Hndl PToGSString(Str255) inline(0x001F,_CallBackVector);
extern pascal void RectToStr(Rect *, Str255) inline(0x002E,_CallBackVector); 
extern pascal void ReturnToPas(Ptr, Str255 *) inline(0x001B,_CallBackVector);
extern pascal Boolean StrToBool(Str31) inline(0x000B,_CallBackVector);
extern pascal extended StrToExt(Str31) inline(0x000C,_CallBackVector);
extern pascal Longint StrToLong(Str31) inline(0x0009,_CallBackVector);
extern pascal Longint StrToNum(Str31) inline(0x000A,_CallBackVector);
extern pascal void StrToPoint(Str255, Point) inline(0x002F,_CallBackVector); 
extern pascal void StrToRect(Str255, Rect *) inline(0x0030,_CallBackVector); 
extern pascal GSString255Hndl ZeroToGS(Handle) inline(0x0024,_CallBackVector);
extern pascal void ZeroToPas(Ptr, Str255 *) inline(0x0008,_CallBackVector);

/**** Field Utilities ****/
extern pascal Handle GetFieldByID(Boolean, word) inline(0x0016,_CallBackVector);
extern pascal Handle GetFieldByName(Boolean, Str255) inline(0x0014,_CallBackVector);
extern pascal Handle GetFieldByNum(Boolean, word) inline(0x0015,_CallBackVector);
extern pascal void SetFieldByID(Boolean, word, Handle) inline(0x0019,_CallBackVector);
extern pascal void SetFieldByName(Boolean, Str255, Handle) inline(0x0017,_CallBackVector);
extern pascal void SetFieldByNum(Boolean, word, Handle) inline(0x0018,_CallBackVector);

/**** Graphic Utilities ****/
extern pascal void ChangedMaskAndData(word) inline(0x002C,_CallBackVector);
extern pascal void GetMaskAndData(LocInfoPtr, LocInfoPtr) inline(0x002B,_CallBackVector);

/**** Miscellaneous Utilities ****/
extern pascal void BeginXSound(void) inline(0x0029,_CallBackVector);
extern pascal void EndXSound(void) inline(0x002A,_CallBackVector);

/**** Resource Names Utilities ****/
extern pascal Boolean FindNamedResource(word, Str255, word *, long *) inline(0x0026,_CallBackVector);
extern pascal Str255 GetResourceName(word, long) inline(0x0028,_CallBackVector);
extern pascal Handle LoadNamedResource(word, Str255) inline(0x0025,_CallBackVector);
extern pascal void SetResourceName(word, long, Str255) inline(0x0027,_CallBackVector);

/**** Creating and Disposing XWindoids ****/
extern pascal WindowPtr NewXWindow(Rect, Str31, Boolean, word) inline(0x0031,_CallBackVector);
extern pascal void CloseXWindow(WindowPtr) inline(0x0033,_CallBackVector);

/**** XWindoid Utilities ****/
extern pascal Longint GetXWindowValue(WindowPtr) inline(0x0037,_CallBackVector);
extern pascal void HideHCPalettes(void) inline(0x0034,_CallBackVector);
extern pascal void ShowHCPalettes(void) inline(0x0035,_CallBackVector);
extern pascal void SetXWIdleTime(WindowPtr, Longint) inline(0x0032,_CallBackVector);
extern pascal void SetXWindowValue(WindowPtr, Longint) inline(0x0036,_CallBackVector);
extern pascal void XWAllowReEntrancy(WindowPtr, Boolean, Boolean) inline(0x0038,_CallBackVector);

#endif
