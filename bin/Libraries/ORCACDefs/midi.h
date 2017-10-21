/********************************************** MIDI Tool Set** Copyright Apple Computer, Inc.1986-90* All Rights Reserved** Copyright 1992, Byte Works, Inc.*********************************************/#ifndef __TYPES__#include <TYPES.h>#endif#ifndef __MIDI__#define __MIDI__/* MIDI */#define miToolNum 0x0020                /* the tool number of the MIDI Tool Set */#define miDrvrFileType 0x00BB           /* filetype of MIDI device driver */#define miNSVer 0x0102                  /* minimum version of Note Synthesizer required by MIDI Tool Set */#define miSTVer 0x0203                  /* minimum version of Sound Tools needed by MIDI Tool Set */#define miDrvrAuxType 0x0300            /* aux type of MIDI device driver *//* Error Codes */#define miStartUpErr 0x2000             /* MIDI Tool Set is not started  */#define miPacketErr 0x2001              /* incorrect length for a received MIDI command */#define miArrayErr 0x2002               /* a designated array had an insufficient or illegal size */#define miFullBufErr 0x2003             /* input buffer overflow */#define miToolsErr 0x2004               /* the required tools were not started up or had insufficient versions */#define miOutOffErr 0x2005              /* MIDI output must first be enabled */#define miNoBufErr 0x2007               /* no buffer is currently allocated */#define miDriverErr 0x2008              /* the designated file is not a legal MIDI device driver */#define miBadFreqErr 0x2009             /* the MIDI clock cannot attain the requested frequency */#define miClockErr 0x200A               /* the MIDI clock value wrapped to zero */#define miConflictErr 0x200B            /* conflicting processes for MIDI input */#define miNoDevErr 0x200C               /* no MIDI device driver loaded */#define miDevNotAvail 0x2080            /* the requested device is not available */#define miDevSlotBusy 0x2081            /* requested slot is already in use */#define miDevBusy 0x2082                /* the requested device is already in use */#define miDevOverrun 0x2083             /* device overrun by incoming MIDI data */#define miDevNoConnect 0x2084           /* no connection to MIDI */#define miDevReadErr 0x2085             /* framing error in received MIDI data */#define miDevVersion 0x2086             /* ROM version is incompatible with device driver */#define miDevIntHndlr 0x2087            /* conflicting interrupt handler is installed *//* MidiClock */#define miSetClock 0x0000               /* set time stamp clock */#define miStartClock 0x0001             /* start time stamp clock */#define miStopClock 0x0002              /* stop time stamp clock */#define miSetFreq 0x0003                /* set clock frequency *//* MidiControl */#define miRawMode 0x00000000L           /* raw mode for MIDI input and output */#define miSetRTVec 0x0000               /* set real-time message vector */#define miPacketMode 0x00000001L        /* packet mode for MIDI input and output */#define miSetErrVec 0x0001              /* set real-time error vector */#define miStandardMode 0x00000002L      /* standard mode for MIDI input and output */#define miSetInBuf 0x0002               /* set input buffer information */#define miSetOutBuf 0x0003              /* set output buffer information */#define miStartInput 0x0004             /* start MIDI input */#define miStartOutput 0x0005            /* start MIDI output */#define miStopInput 0x0006              /* stop MIDI input */#define miStopOutput 0x0007             /* stop MIDI output */#define miFlushInput 0x0008             /* discard contents of input buffer */#define miFlushOutput 0x0009            /* discard contents of output buffer */#define miFlushPacket 0x000A            /* discard next input packet */#define miWaitOutput 0x000B             /* wait for output buffer to empty */#define miSetInMode 0x000C              /* set input mode */#define miSetOutMode 0x000D             /* set output mode */#define miClrNotePad 0x000E             /* clear all notes marked on in the note pad */#define miSetDelay 0x000F               /* set minimum delay between output packets */#define miOutputStat 0x0010             /* enable/disable output of running-status */#define miIgnoreSysEx 0x0011            /* ignore system exclusive input *//* MidiDevice */#define miSelectDrvr 0x0000             /* display device driver selection dialog */#define miLoadDrvr 0x0001               /* load and initialize device driver */#define miUnloadDrvr 0x0002             /* shutdown MIDI device, unload driver *//* MidiInfo */#define miNextPktLen 0x0000             /* return length of next packet */#define miInputChars 0x0001             /* return number of characters in input buffer */#define miOutputChars 0x0002            /* return number of characters in output buffer */#define miMaxInChars 0x0003             /* return maximum number of characters in input buffer */#define miMaxOutChars 0x0004            /* return maximum number of characters in output buffer */#define miRecordAddr 0x0005             /* return current MidiRecordSeq address */#define miPlayAddr 0x0006               /* return current MidiPlaySeq address */#define miClockValue 0x0007             /* return current time stamp clock value */#define miClockFreq 0x0008              /* return number of clock ticks per second */#define midiInputPoll 0x00E101B2L       /* MidiInputChannel - vector to poll MIDI input channel */struct MiBufInfo {   Word bufSize;                        /* size of buffer (0 for default) */   Pointer address;                     /* address of buffer (0 for auto-allocation) */   };typedef struct MiBufInfo MiBufInfo;struct MiDriverInfo {   Word slot;                           /* device slot */   Word external;                       /* slot internal (=0) / external (=1) */   Byte pathname[65];                   /* device driver pathname */   };typedef struct MiDriverInfo MiDriverInfo, *MiDriverInfoPtr;extern pascal void MidiBootInit(void) inline(0x0120,dispatcher);extern pascal void MidiStartUp(Word, Word) inline(0x0220,dispatcher);extern pascal void MidiShutDown(void) inline(0x0320,dispatcher);extern pascal Word MidiVersion(void) inline(0x0420,dispatcher);extern pascal void MidiReset(void) inline(0x0520,dispatcher);extern pascal Boolean MidiStatus(void) inline(0x0620,dispatcher);extern pascal void MidiClock(Word, Long) inline(0x0B20,dispatcher);extern pascal void MidiControl(Word, Long) inline(0x0920,dispatcher);extern pascal void MidiDevice(Word, Pointer) inline(0x0A20,dispatcher);extern pascal LongWord MidiInfo(Word) inline(0x0C20,dispatcher);#define MidiInputPoll() asm {jsl 0xE101B2} /* Not a true tool call. Made through its own vector */extern pascal Word MidiReadPacket(Pointer, Word) inline(0x0D20,dispatcher);extern pascal Word MidiWritePacket(Pointer) inline(0x0E20,dispatcher);#endif