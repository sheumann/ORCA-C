/****************************************************************
*
*  orca.h - extra functions included in ORCA/C
*
*  March 1989
*  Mike Westerfield
*
*  Copyright 1989, 1993
*  Byte Works, Inc.
*
****************************************************************/

#ifndef __orca__
#define __orca__

char           *commandline(void);
void            enddesk(void);
void            endgraph(void);
char           *shellid(void);
void            startdesk(int);
void            startgraph(int);
pascal void     setfpeslot(int);
int             toolerror(void);
int             userid(void);

#endif
