/********************************************
*
* Control Manager
*
* Copyright Apple Computer, Inc.1986-91
* All Rights Reserved
*
* Copyright 1992, 1993, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __CONTROL__
#define __CONTROL__

/* Axis Parameters */
#define noConstraint 0x0000             /* No constraint on movement. */
#define hAxisOnly 0x0001                /* Horizontal axis only. */
#define vAxisOnly 0x0002                /* Vertical axis only. */

/* CtlFlag */
#define simpRound 0x0000                /* Simple button flag */
#define upFlag 0x0001                   /* Scroll bar flag. */
#define boldButton 0x0001               /* Bold round cornered outlined button. */
#define simpBRound 0x0001               /* Simple button flag */
#define downFlag 0x0002                 /* Scroll bar flag. */
#define simpSquare 0x0002               /* Simple button flag */
#define simpDropSquare 0x0003           /* Simple button flag */
#define leftFlag 0x0004                 /* Scroll bar flag. */
#define rightFlag 0x0008                /* Scroll bar flag. */
#define dirScroll 0x0010                /* Scroll bar flag. */
#define horScroll 0x0010                /* Scroll bar flag. */
#define family 0x007F                   /* Mask for radio button family number */
#define ctlInVis 0x0080                 /* invisible mask for any type of control  */
#define fCallWindowMgr 0x0001           /* Control Template flag value */
#define fSubstituteText 0x0002
#define fSubTextType 0x0001
#define inListBox 0x88
#define fBlastText 0x0004               /* static text control */
#define fTextCanDim 0x0008	        /* static text control */
#define fSquishText 0x0010	        /* static text control */
#define fNoTrackIcon 0x0008             /* make Icon Button play dead */
#define testMemNever 0x0040             /* list control */

/* CtlProc Codes */
#define simpleProc 0x00000000L
#define checkProc 0x02000000L
#define radioProc 0x04000000L
#define scrollProc 0x06000000L
#define growProc 0x08000000L

/* DefProc Commands */
#define drawCtl 0x0000                  /* Draw control command. */
#define calcCRect 0x0001                /* Compute drag RECT command. */
#define testCtl 0x0002                  /* Hit test command. */
#define initCtl 0x0003                  /* Initialize command. */
#define dispCtl 0x0004                  /* Dispose command. */
#define posCtl 0x0005                   /* Move indicator command. */
#define thumbCtl 0x0006                 /* Compute drag parameters command. */
#define dragCtl 0x0007                  /* Drag command. */
#define autoTrack 0x0008                /* Action command. */
#define newValue 0x0009                 /* Set new value command. */
#define setParams 0x000A                /* Set new parameters command. */
#define moveCtl 0x000B                  /* Move command. */
#define recSize 0x000C                  /* Return record size command. */
#define ctlHandleEvent 0x000D           /* Handle a keystroke or menu selection */
#define ctlChangeTarget 0x000E          /* Issued when control's target status has changed */
#define ctlChangeBounds 0x000F          /* Issued when control's boundary rectangle has changed */
#define ctlWindChangeSize 0x0010        /* Window has been grown or zoomed */
#define ctlHandleTab 0x0011             /* Control has been tabbed to */
#define ctlNotifyMultiPart 0x0012       /* A multipart control has been hidden, drawn or shown */
#define ctlWinStateChange 0x0013        /* Window state has changed */

/* hiliteState Codes */
#define noHilite 0x0000                 /* Param to HiliteControl */
#define inactiveHilite 0x00FF           /* Param to HiliteControl */

/* PartCode Numbers */
#define noPart 0x0000
#define simpleButton 0x0002
#define checkBox 0x0003
#define radioButton 0x0004
#define upArrow 0x0005
#define downArrow 0x0006
#define pageUp 0x0007
#define pageDown 0x0008
#define growBox 0x000A
#define thumb 0x0081

/* moreFlags Codes */
#define fCtlTarget 0x8000               /* is current target of typing commands */
#define fCtlCanBeTarget 0x4000          /* can be made the target control */
#define fCtlWantEvent 0x2000            /* control can be called view SendEventToCtl */
#define fCtlWantsEvent 0x2000           /* control can be called view SendEventToCtl */
#define fCtlWantEvents 0x2000           /* control can be called view SendEventToCtl */
#define fCtlWantsEvents 0x2000          /* control can be called view SendEventToCtl */
#define fCtlProcRefNotPtr 0x1000        /* set = ID of defproc, clear = pointer to defproc */
#define fCtlTellAboutSize 0x0800        /* set if ctl needs notification when size of owning window changes */
#define fCtlIsMultiPart 0x0400          /* set if ctl needs notification to be hidden */
#define fMenuDefIsText 0x0004
#define fDrawIconInResult 0x0020
#define fDrawPopDownIcon 0x0080
#define colorDescriptor 0x000C          /* indicates type of reference in colorRef */
#define styleDescriptor 0x0003          /* indicates type of reference in styleRef */

/* Ctl Verbs */
#define titleIsPtr 0x00
#define titleIsHandle 0x01
#define titleIsResource 0x02
#define colorTableIsPtr 0x00
#define colorTableIsHandle 0x04
#define colorTableIsResource 0x08
#define ctlHideCtl 0x12

/* InputVerb Codes */
#define singlePtr 0x0000
#define singleHandle 0x0001
#define singleResource 0x0002
#define ptrToPtr 0x0003
#define ptrToHandle 0x0004
#define ptrToResource 0x0005
#define handleToPtr 0x0006
#define handleToHandle 0x0007
#define handleToResource 0x0008
#define resourceToResource 0x0009

/* ProcRefs */
#define simpleButtonControl 0x80000000L
#define checkControl 0x82000000L
#define radioControl 0x84000000L
#define scrollBarControl 0x86000000L
#define growControl 0x88000000L
#define statTextControl 0x81000000L
#define editLineControl 0x83000000L
#define editTextControl 0x85000000L
#define popUpControl 0x87000000L
#define listControl 0x89000000L
#define pictureControl 0x8D000000L
#define iconButtonControl 0x87FF0001L
#define thermometerControl 0x87FF0002L
#define rectangleControl 0x87FF0003L

/* Error Codes */
#define wmNotStartedUp 0x1001           /* Window manager was not initialized */
#define cmNotInitialized 0x1002         /* Control manager was not initialized */
#define noCtlInList 0x1003              /* Control not in window list */
#define noCtlError 0x1004               /* no controls in window */
#define noSuperCtlError 0x1005          /* no super controls in window */
#define noCtlTargetError 0x1006         /* no target super control */
#define notSuperCtlError 0x1007         /* action can only be done on super control */
#define canNotBeTargetError 0x1008      /* conrol cannot be made target */
#define noSuchIDError 0x1009            /* specified ID cannot be found */
#define tooFewParmsError 0x100A         /* not enough params specified */
#define noCtlToBeTargetError 0x100B     /* NextCtl call, no ctl could be target */
#define noFrontWindowError 0x100C       /* there is no front window */

/* displayMode flags */
#define selectedIcon 0x0001
#define openIcon 0x0002
#define offline 0x0004

/* listType values */
#define fListString 0x0001
#define fListSelect 0x0002
#define fListScrollBar 0x0004

/* PopUp control flag values */
#define fRightJustifyResult 0x0001
#define fRightJustifyTitle 0x0002
#define fInWindowOnly 0x0004
#define fDontDrawResult 0x0008
#define fDontDrawTitle 0x0010
#define fDontHiliteTitle 0x0020
#define fType2PopUp 0x0040

struct BoxColors {
   Word boxReserved;                    /* reserved */
   Word boxNor;                         /* color of box when not checked */
   Word boxSel;                         /* color of box when checked */
   Word boxTitle;                       /* color of check box's title */
   };
typedef struct BoxColors BoxColors, *BoxColorsPtr, **BoxColorsHndl;

struct BttnColors {
   Word bttnOutline;                    /* color of outline */
   Word bttnNorBack;                    /* color of background when not selected */
   Word bttnSelBack;                    /* color of background when selected */
   Word bttnNorText;                    /* color of title's text when not selected */
   Word bttnSelText;                    /* color of title's text when selected */
   };
typedef struct BttnColors BttnColors, *BttnColorsPtr, **BttnColorsHndl;

struct LimitBlk {
   Rect boundRect;                      /* Drag bounds. */
   Rect slopRect;                       /* Cursor bounds. */
   Word axisParam;                      /* Movement constrains. */
   Pointer dragPatt;                    /* Pointer to 32 byte Pattern for drag outline. */
   };
typedef struct LimitBlk LimitBlk, *LimitBlkPtr, **LimitBlkHndl;

struct RadioColors {
   Word radReserved;                    /* reserved */
   Word radNor;                         /* color of radio button when off */
   Word radSel;                         /* color of radio button when on */
   Word radTitle;                       /* color of radio button's title text */
   };
typedef struct RadioColors RadioColors, *RadioColorsPtr, **RadioColorsHndl;

struct KeystrokeRec {
   Byte key1;
   Byte key2;
   Word keyModifiers;
   Word keyCareBits;
   };
typedef struct KeystrokeRec KeystrokeRec;

struct ControlTemplate {
   Word pCount;
   LongWord ID;
   Rect rect;
   LongWord procRef;
   Word flag;
   Word moreFlags;
   LongWord refCon;
   };
typedef struct ControlTemplate ControlTemplate;

struct SimpleButtonTemplate {
   ControlTemplate ctlTemplate;
   Ref titleRef;
   Ref colorTableRef;
   KeystrokeRec keyEquivalent;
   };
typedef struct SimpleButtonTemplate SimpleButtonTemplate;

struct CheckBoxTemplate {
   ControlTemplate ctlTemplate;
   Ref titleRef;
   Word initalValue;
   Ref colorTableRef;
   KeystrokeRec keyEquivalent;
   };
typedef struct CheckBoxTemplate CheckBoxTemplate;

struct IconButtonTemplate {
   ControlTemplate ctlTemplate;
   Ref iconRef;
   Ref titleRef;
   Ref colorTableRef;
   Word displayMode;
   KeystrokeRec keyEquivalent;
   };
typedef struct IconButtonTemplate IconButtonTemplate;

struct LineEditTemplate {
   ControlTemplate ctlTemplate;
   Word maxSize;
   Ref defaultRef;
   Word passwordChar;
   };
typedef struct LineEditTemplate LineEditTemplate;

struct ListTemplate {
   ControlTemplate ctlTemplate;
   Word listSize;
   Word listView;
   Word listType;
   Word listStart;
   ProcPtr listDraw;
   Word listMemHeight;
   Word listMemSize;
   Ref listRef;
   Ref colorTableRef;
   };
typedef struct ListTemplate ListTemplate;

struct PictureTemplate {
   ControlTemplate ctlTemplate;
   Ref pictureRef;
   };
typedef struct PictureTemplate PictureTemplate;

struct PopupTemplate {
   ControlTemplate ctlTemplate;
   Word titleWidth;
   Ref menuRef;
   Word initialValue;
   Ref colorTableRef;
   };
typedef struct PopupTemplate PopupTemplate;

struct RadioButtonTemplate {
   ControlTemplate ctlTemplate;
   Ref titleRef;
   Word initalValue;
   Ref colorTableRef;
   KeystrokeRec keyEquivalent;
   };
typedef struct RadioButtonTemplate RadioButtonTemplate;

struct RectangleTemplate {
   ControlTemplate ctlTemplate;
   Word penHeight;
   Word penWidth;
   Mask penMask;
   Pattern penPattern;
   };
typedef struct RectangleTemplate RectangleTemplate;

struct ScrollBarTemplate {
   ControlTemplate ctlTemplate;
   Word maxSize;
   Word viewSize;
   Word initalValue;
   Ref colorTableRef;
   };
typedef struct ScrollBarTemplate ScrollBarTemplate;

struct SizeBoxTemplate {
   ControlTemplate ctlTemplate;
   Ref colorTableRef;
   };
typedef struct SizeBoxTemplate SizeBoxTemplate;

struct StaticTextTemplate {
   ControlTemplate ctlTemplate;
   Ref textRef;
   Word textSize;
   Word just;
   };
typedef struct StaticTextTemplate StaticTextTemplate;

struct TextEditTemplate {
   ControlTemplate ctlTemplate;
   LongWord textFlags;
   Rect indentRect;
   CtlRecHndl vertBar;
   Word vertAmount;
   CtlRecHndl horzBar;
   Word horzAmount;
   Ref styleRef;
   Word textDescriptor;
   Ref textRef;
   LongWord textLength;
   LongWord maxChars;
   LongWord maxLines;
   Word maxCharsPerLine;
   Word maxHeight;
   Ref colorRef;
   Word drawMode;
   ProcPtr filterProcPtr;
   };
typedef struct TextEditTemplate TextEditTemplate;

struct ThermometerTemplate {
   ControlTemplate ctlTemplate;
   Word value;
   Word data;
   Ref colorTableRef;
   };
typedef struct ThermometerTemplate ThermometerTemplate;

extern pascal void CtlBootInit(void) inline(0x0110,dispatcher);
extern pascal void CtlStartUp(Word, Word) inline(0x0210,dispatcher);
extern pascal void CtlShutDown(void) inline(0x0310,dispatcher);
extern pascal Word CtlVersion(void) inline(0x0410,dispatcher);
extern pascal void CtlReset(void) inline(0x0510,dispatcher);
extern pascal Boolean CtlStatus(void) inline(0x0610,dispatcher);
extern pascal void CtlNewRes(void) inline(0x1210,dispatcher);
extern pascal void DisposeControl(CtlRecHndl) inline(0x0A10,dispatcher);
extern pascal void DragControl(Integer, Integer, Rect *, Rect *, Word, CtlRecHndl) inline(0x1710,dispatcher);
extern pascal Point DragRect(VoidProcPtr, Pattern, Integer, Integer, Rect *, Rect *, Rect *, Word) inline(0x1D10,dispatcher);
extern pascal void DrawControls(GrafPortPtr) inline(0x1010,dispatcher);
extern pascal void DrawOneCtl(CtlRecHndl) inline(0x2510,dispatcher);
extern pascal void EraseControl(CtlRecHndl) inline(0x2410,dispatcher);
extern pascal Word FindControl(CtlRecHndl *, Integer, Integer, GrafPortPtr) inline(0x1310,dispatcher);
extern pascal LongProcPtr GetCtlAction(CtlRecHndl) inline(0x2110,dispatcher);
extern pascal Word GetCtlDPage(void) inline(0x1F10,dispatcher);
extern pascal LongWord GetCtlParams(CtlRecHndl) inline(0x1C10,dispatcher);
extern pascal LongWord GetCtlRefCon(CtlRecHndl) inline(0x2310,dispatcher);
extern pascal Pointer GetCtlTitle(CtlRecHndl) inline(0x0D10,dispatcher);
extern pascal Word GetCtlValue(CtlRecHndl) inline(0x1A10,dispatcher);
extern pascal LongWord GrowSize(void) inline(0x1E10,dispatcher);
extern pascal void HideControl(CtlRecHndl) inline(0x0E10,dispatcher);
extern pascal void HiliteControl(Word, CtlRecHndl) inline(0x1110,dispatcher);
extern pascal void KillControls(GrafPortPtr) inline(0x0B10,dispatcher);
extern pascal void MoveControl(Integer, Integer, CtlRecHndl) inline(0x1610,dispatcher);
extern pascal CtlRecHndl NewControl(GrafPortPtr, Rect *, Pointer, Word, Word, Word, Word, LongProcPtr, Longint, Pointer) inline(0x0910,dispatcher);
extern pascal void SetCtlAction(LongProcPtr, CtlRecHndl) inline(0x2010,dispatcher);
extern pascal FontHndl SetCtlIcons(FontHndl) inline(0x1810,dispatcher);
extern pascal void SetCtlParams(Word, Word, CtlRecHndl) inline(0x1B10,dispatcher);
extern pascal void SetCtlRefCon(Longint, CtlRecHndl) inline(0x2210,dispatcher);
extern pascal void SetCtlTitle(Pointer, Handle) inline(0x0C10,dispatcher);
extern pascal void SetCtlValue(Word, CtlRecHndl) inline(0x1910,dispatcher);
extern pascal void ShowControl(CtlRecHndl) inline(0x0F10,dispatcher);
extern pascal Word TestControl(Integer, Integer, CtlRecHndl) inline(0x1410,dispatcher);
extern pascal Word TrackControl(Integer, Integer, LongProcPtr, CtlRecHndl) inline(0x1510,dispatcher);

extern pascal LongWord CallCtlDefProc(CtlRecHndl, Word, Long) inline(0x2C10,dispatcher);
extern pascal Handle CMLoadResource(Word, Long) inline(0x3210,dispatcher);
extern pascal void CMReleaseResource(Word, Long) inline(0x3310,dispatcher);
extern pascal CtlRecHndl FindTargetCtl(void) inline(0x2610,dispatcher);
extern pascal CtlRecHndl GetCtlHandleFromID(WindowPtr, Long) inline(0x3010,dispatcher);
extern pascal LongWord GetCtlID(CtlRecHndl) inline(0x2A10,dispatcher);
extern pascal Word GetCtlMoreFlags(CtlRecHndl) inline(0x2E10,dispatcher);
extern pascal Pointer GetCtlParamPtr(void) inline(0x3510,dispatcher);
extern pascal void InvalCtls(WindowPtr) inline(0x3710,dispatcher);
extern pascal CtlRecHndl MakeNextCtlTarget(void) inline(0x2710,dispatcher);
extern pascal void MakeThisCtlTarget(CtlRecHndl) inline(0x2810,dispatcher);
extern pascal CtlRecHndl NewControl2(WindowPtr, Word, Ref) inline(0x3110,dispatcher);
extern pascal void NotifyControls(Word, Word, Long, WindowPtr) inline(0x2D10,dispatcher);
extern pascal void NotifyCtls(Word, Word, Long, WindowPtr) inline(0x2D10,dispatcher);
extern pascal Boolean SendEventToCtl(Boolean, WindowPtr, EventRecordPtr) inline(0x2910,dispatcher);
extern pascal void SetCtlID(Long, CtlRecHndl) inline(0x2B10,dispatcher);
extern pascal void SetCtlMoreFlags(Word, CtlRecHndl) inline(0x2F10,dispatcher);
extern pascal void SetCtlParamPtr(Pointer) inline(0x3410,dispatcher);

extern pascal Word FindRadioButton(WindowPtr, Word) inline(0x3910,dispatcher);
extern pascal void GetLETextByID(WindowPtr, Long, StringPtr) inline(0x3B10,dispatcher);
extern pascal void SetLETextByID(WindowPtr, Long, StringPtr) inline(0x3A10,dispatcher);

extern pascal void SetCtlValueByID(Word, GrafPortPtr, Long) inline(0x3C10,dispatcher);
extern pascal Word GetCtlValueByID(GrafPortPtr, Long) inline(0x3D10,dispatcher);
extern pascal void InvalOneCtlByID(GrafPortPtr, Long) inline(0x3E10,dispatcher);
extern pascal void HiliteCtlByID(Word, GrafPortPtr, Long) inline(0x3F10,dispatcher);

#endif             
