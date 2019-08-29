#ifndef SLOPRINT_H
#define SLOPRINT_H

/*-----------------------------------------------------------------
*	sloprint.h	-	what it sounds like
Wed Sep  5 18:45:48 PDT 2012
-----------------------------------------------------------------*/
#include <utime.h>

void sloprint(const char * x,int interval)
{
	int i ;
	for (i = 0 ; i < strlen(x) ; i++)
	{
		putchar(x[i]) ;
		fflush(stdout) ;
		usleep(interval) ;
		sched_yield() ; // "DO Events" in VB: cede rest of cpu slice
	}
}
#endif 
