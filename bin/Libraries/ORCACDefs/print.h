/********************************************
*
* Print Manager
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

#ifndef __PRINT__
#define __PRINT__

/* Error Codes */
#define pntrConFailed 0x1308            /* connection to the printer failed */
#define memFullErr 0xFF80
#define ioAbort 0xFFE5
#define prAbort 0x0080
#define missingDriver 0x1301            /* specified driver not in system/drivers */
#define portNotOn 0x1302                /* specified port not selected in ctl panel */
#define noPrintRecord 0x1303            /* no print record was given */
#define badLaserPrep 0x1304             /* laser prep in laser writer incompatible */
#define badLPFile 0x1305                /* laser prep in system/drivers incompatible */
#define papConnNotOpen 0x1306           /* cannot connect to laser writer */
#define papReadWriteErr 0x1307          /* apple talk PAPRead or PAPWrite error */
#define ptrConnFailed 0x1308            /* cannot establish connection with imagewriter */
#define badLoadParam 0x1309             /* parameter for load/unload is invalid */
#define callNotSupported 0x130A         /* toolcall made is not supported by this version */
#define startUpAlreadyMade 0x1321       /* low level startup already made */
#define invalidCtlVal 0x1322            /* invalid control value had been spec'd */

/* whichDriver Codes */
#define bothDrivers 0x0                 /* input to PMLoadDriver and PMUnloadDriver */
#define printerDriver 0x0001            /* input to PMLoadDriver and PMUnloadDriver */
#define portDriver 0x0002               /* input to PMLoadDriver and PMUnloadDriver */

/* Other Constants */
#define prPortrait 0x0000
#define prLandscape 0x0001
#define prImageWriter 0x0001
#define prImageWriterLQ 0x0002
#define prLaserWriter 0x0003
#define prEpson 0x0004
#define prBlackWhite 0x0001
#define prColor 0x0002
#define bDraftLoop 0x0000
#define bSpoolLoop 0x0080

struct PrPrinterSpecRec {
   Word prPrinterType;
   Word prCharacteristics;
   };
typedef struct PrPrinterSpecRec PrPrinterSpecRec;

struct PrInfoRec {
   Word iDev;                           /* reserved for internal use */
   Word iVRes;                          /* vertical resolution of printer */
   Word iHRes;                          /* horizontal resolution of printer */
   Rect rPage;                          /* defining page rectangle */
   };
typedef struct PrInfoRec PrInfoRec, *PrInfoRecPtr, **PrInfoRecHndl;

struct PrJobRec {
   Word iFstPage;                       /* first page to print */
   Word iLstPage;                       /* last page to print */
   Word iCopies;                        /* number of copies */
   Byte bJDocLoop;                      /* printing method */
   Byte fFromUser;                      /* used internally */
   WordProcPtr pIdleProc;               /* background procedure */
   Pointer pFileName;                   /* spool file name */
   Word iFileVol;                       /* spool file volume reference number */
   Byte bFileVers;                      /* spool file version number */
   Byte bJobX;                          /* used internally */
   };
typedef struct PrJobRec PrJobRec, *PrJobRecPtr;

struct PrStyleRec {
   Word wDev;                           /* output quality information */
   Word internA[3];                     /* for internal use */
   Word feed;                           /* paper feed type */
   Word paperType;                      /* paper type */
   Word crWidth;                        /* carriage Width for image writer or vertical sizing for lazer writer */
   Word reduction;                      /* % reduction, laser writer only */
   Word internB;                        /* for internal use */
   };
typedef struct PrStyleRec PrStyleRec, *PrStyleRecPtr, **PrStyleRecHndl;

#define vSizing crWidth                 /* PrStyleRec - alternate field name   */

struct PrRec {
   Word prVersion;                      /* print manager version */
   PrInfoRec prInfo;                    /* printer infomation subrecord */
   Rect rPaper;                         /* Defining paper rectangle */
   PrStyleRec prStl;                    /* style subrecord */
   Byte prInfoPT[14];                   /* reserved for internal use */
   Byte prXInfo[24];                    /* reserved for internal use */
   PrJobRec prJob;                      /* job subrecord */
   Byte printX[38];                     /* reserved for future use */
   Word iReserved;                      /* reserved for internal use */
   };
typedef struct PrRec PrRec, *PrRecPtr, **PrRecHndl;

struct PrStatusRec {
   Word iTotPages;                      /* number of pages in spool file */
   Word iCurPage;                       /* page being printed */
   Word iTotCopies;                     /* number of copies requested */
   Word iCurCopy;                       /* copy being printed */
   Word iTotBands;                      /* reserved for internal use */
   Word iCurBand;                       /* reserved for internal use */
   Boolean fPgDirty;                    /* TRUE if started printing page */
   Word fImaging;                       /* reserved for internal use */
   PrRecHndl hPrint;                    /* handle of print record */
   GrafPortPtr pPrPort;                 /* pointer to grafport being use for printing */
   LongWord hPic;                       /* reserved for internal use */
   };
typedef struct PrStatusRec PrStatusRec, *PrStatusRecPtr, **PrStatusRecHndl;

extern pascal void PMBootInit(void) inline(0x0113,dispatcher);
extern pascal void PMStartUp(Word, Word) inline(0x0213,dispatcher);
extern pascal void PMShutDown(void) inline(0x0313,dispatcher);
extern pascal Word PMVersion(void) inline(0x0413,dispatcher);
extern pascal void PMReset(void) inline(0x0513,dispatcher);
extern pascal Boolean PMStatus(void) inline(0x0613,dispatcher);
extern pascal Boolean PrChoosePrinter(void) inline(0x1613,dispatcher);
extern pascal Boolean PrChooser(void) inline(0x1613,dispatcher);
extern pascal void PrCloseDoc(GrafPortPtr) inline(0x0F13,dispatcher);
extern pascal void PrClosePage(GrafPortPtr) inline(0x1113,dispatcher);
extern pascal void PrDefault(PrRecHndl) inline(0x0913,dispatcher);
extern pascal Word PrDriverVer(void) inline(0x2313,dispatcher);
extern pascal Word PrError(void) inline(0x1413,dispatcher);
extern pascal Boolean PrJobDialog(PrRecHndl) inline(0x0C13,dispatcher);
extern pascal GrafPortPtr PrOpenDoc(PrRecHndl, GrafPortPtr) inline(0x0E13,dispatcher);
extern pascal void PrOpenPage(GrafPortPtr, Rect *) inline(0x1013,dispatcher);
extern pascal void PrPicFile(PrRecHndl, GrafPortPtr, PrStatusRecPtr) inline(0x1213,dispatcher);
extern pascal void PrPixelMap(LocInfoPtr, RectPtr, Boolean) inline(0x0D13,dispatcher);
extern pascal Word PrPortVer(void) inline(0x2413,dispatcher);
extern pascal void PrSetError(Word) inline(0x1513,dispatcher);
extern pascal Boolean PrStlDialog(PrRecHndl) inline(0x0B13,dispatcher);
extern pascal Boolean PrValidate(PrRecHndl) inline(0x0A13,dispatcher);

extern pascal void PMLoadDriver(Word) inline(0x3513,dispatcher);
extern pascal void PMUnloadDriver(Word) inline(0x3413,dispatcher);
extern pascal StringPtr PrGetDocName(void) inline(0x3613,dispatcher);
extern pascal Word PrGetPgOrientation(PrRecHndl) inline(0x3813,dispatcher);
extern pascal long PrGetPrinterSpecs(void) inline(0x1813,dispatcher);
extern pascal void PrSetDocName(Pointer) inline(0x3713,dispatcher);

extern pascal StringPtr PrGetNetworkName(void) inline(0x2B13,dispatcher);
extern pascal StringPtr PrGetPortDvrName(void) inline(0x2913,dispatcher);
extern pascal StringPtr PrGetPrinterDvrName(void) inline(0x2813,dispatcher);
extern pascal StringPtr PrGetUserName(void) inline(0x2A13,dispatcher);
extern pascal StringPtr PrGetZoneName(void) inline(0x2513,dispatcher);

#endif
