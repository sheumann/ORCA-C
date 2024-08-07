/********************************************
*
* List Manager
*
* Copyright Apple Computer, Inc. 1986-91
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __LIST__
#define __LIST__

/* error codes */
#define listRejectEvent 0x1C02

/* ListType Masks */
#define cString 0x0001                  /* null terminated string type */
#define LIST_STRG 0x0001                /* null terminated string type */
#define selectOnlyOne 0x0002            /* only one selection allowed */
#define LIST_SELECT 0x0002              /* single selection only */

/* memFlag Codes */
#define memNever 0x20                   /* Inactive */
#define memDisabled 0x40                /* Sets member flag to disabled */
#define memSelected 0x80                /* Sets member flag to selected */
struct LColorTable {
   Word listFrameClr;                   /* Frame color */
   Word listNorTextClr;                 /* Unhighlighted text color */
   Word listSelTextClr;                 /* Highlighted text color */
   Word listNorBackClr;                 /* Unhighlighted background color */
   Word listSelBackClr;                 /* Highlighted backgraound color */
   };
typedef struct LColorTable LColorTable, *LColorTablePtr, **LColorTableHndl;

struct MemRec {
   Pointer memPtr;                      /* Pointer to string, or custom */
   Byte memFlag;                        /* Bit Flag */
   };
typedef struct MemRec MemRec, *MemRecPtr, **MemRecHndl;

/* The MemRec is followed by n bytes determined by value of listMemSize field */
struct ListCtlRec {
   CtlRecHndl ctlNext;                  /* Handle of Next Control */
   WindowPtr ctlOwner;                  /* Window owner */
   Rect ctlRect;                        /* Enclosing Rect */
   Byte ctlFlag;                        /* Bit 7 visible; Bit 0 string type; Bit 1 multiple */
   Byte ctlHilite;                      /* (not used) */
   Word ctlValue;                       /* First member in display */
   LongProcPtr ctlProc;                 /* Address of list definition procedure */
   LongProcPtr ctlAction;               /* Address of list action procedure */
   LongWord ctlData;                    /* Low = view size; High = total members */
   LongWord ctlRefCon;                  /* Not used */
   Ptr ctlColor;                        /* Null for default colors */
   VoidProcPtr ctlMemDraw;              /* Address of routine to draw members */
   Word ctlMemHeight;                   /* Member's Height in Pixels */
   Word ctlMemSize;                     /* Bytes in member record */
   MemRecPtr ctlList;                   /* Adress of first member record in array */
   CtlRecHndl ctlListBar;               /* Handle of list contrlo's scroll bar control */
   };
typedef struct ListCtlRec ListCtlRec, *ListCtlRecPtr, **ListCtlRecHndl;

struct ListRec {
   Rect listRect;                       /* Enclosing Rectangle */
   Word listSize;                       /* Number of List Members */
   Word listView;                       /* Max Viewable members */
   Word listType;                       /* Bit Flag */
   Word listStart;                      /* First member in view */
   CtlRecHndl listCtl;                  /* List control's handle */
   VoidProcPtr listDraw;                /* Address of Custom drawing routine */
   Word listMemHeight;                  /* Height of list members */
   Word listMemSize;                    /* Size of Member Records */
   MemRecPtr listPointer;               /* Pointer to first element in MemRec array */
   LongWord listRefCon;                 /* becomes Control's refCon */
   BarColorsPtr listScrollClr;          /* Color table for list's scroll bar */
   };
typedef struct ListRec ListRec, *ListRecPtr, **ListRecHndl;

extern pascal void ListBootInit(void) inline(0x011C,dispatcher);
extern pascal void ListStartUp(void) inline(0x021C,dispatcher);
extern pascal void ListShutDown(void) inline(0x031C,dispatcher);
extern pascal Word ListVersion(void) inline(0x041C,dispatcher);
extern pascal void ListReset(void) inline(0x051C,dispatcher);
extern pascal Boolean ListStatus(void) inline(0x061C,dispatcher);
extern pascal ListCtlRecHndl CreateList(GrafPortPtr, ListRecPtr) inline(0x091C,dispatcher);
extern pascal void DrawMember(MemRecPtr, ListRecPtr) inline(0x0C1C,dispatcher);
extern pascal LongProcPtr GetListDefProc(void) inline(0x0E1C,dispatcher);
extern pascal void NewList(MemRecPtr, ListRecPtr) inline(0x101C,dispatcher);
extern pascal MemRecPtr NextMember(MemRecPtr, ListRecPtr) inline(0x0B1C,dispatcher);
extern pascal MemRecPtr ResetMember(ListRecPtr) inline(0x0F1C,dispatcher);
extern pascal void SelectMember(MemRecPtr, ListRecPtr) inline(0x0D1C,dispatcher);
extern pascal void SortList(VoidProcPtr, ListRecPtr) inline(0x0A1C,dispatcher);

extern pascal void DrawMember2(Word, Handle) inline(0x111C,dispatcher);
extern pascal void NewList2(Pointer, Word, Ref, Word, Word, Handle) inline(0x161C,dispatcher);
extern pascal Word NextMember2(Word, Handle) inline(0x121C,dispatcher);
extern pascal Word ResetMember2(Handle) inline(0x131C,dispatcher);
extern pascal void SelectMember2(Word, Handle) inline(0x141C,dispatcher);
extern pascal void SortList2(Pointer, Handle) inline(0x151C,dispatcher);

extern pascal Word CompareStrings(Word, Ptr, Ptr) inline(0x181C,dispatcher);
extern pascal void ListKey(Word, EventRecordPtr, CtlRecHndl) inline(0x171c, dispatcher);

#endif
