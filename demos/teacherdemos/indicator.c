/*-----------------------------------------------------------------
*	indicator.c	-	use escaped characters for dynamic effects
*	Theoni Harrisburg, Wed Aug 14 14:04:17 PDT 2019
*	GNU cc, SuSE Linux 
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main ()
{
	long unsigned total = 0L, limit = 100000 ;
	long unsigned index ;
	int yndex ;
	printf(
	"Grace L. Furguson Airline, Storm Door, and Gigawatt Reactor co.\n") ;
	printf("Mind Your Neutrons, Now!\n") ;
	while (1)
	{
		for (index = 0L ; index < 6555L ; ++index)
		{
			total += ( rand() % 1000 ) ;
			printf("%014u", total) ;
			if (total > limit)
			{
				limit *= 2 ; 
				fflush(stdout) ;
				printf("  DANGER: REACTOR OVERPRESSURE! EVACUATE AREA!\n") ;
				continue ;
			}
			for( yndex = 0 ; yndex < 14 ; ++yndex)
			{
				printf("%c", '\b') ;
				usleep(500) ;
			}
			usleep(1000) ;
		}
	} // while(1)

} // main ends
