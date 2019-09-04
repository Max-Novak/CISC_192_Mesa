/*-----------------------------------------------------------------
*	factorsl.c	- 'little factor finder'
*	Theoni Harrisburg
Fri Aug 30 20:44:30 PDT 2019
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int num ;
	int i ;
	for ( num = 1 ; num < 65534 ; ++num)
	{
		printf("\n%3d: ", num) ;
		for (i = 2 ; i < num/2 ; ++i)
		{
			if ( (num % i) == 0 )
			{
				printf(" %3d ", i) ;
			}
		}
	}
	return 0 ; 
} // main ends
