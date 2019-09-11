/*-----------------------------------------------------------------
*	nonrandom.c	-	computers do NOT produce random numbers
Wed Sep 13 18:58:21 PDT 2017
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[], char **env)
{
	//srand(time(NULL)) ;    // if you cover this, you see: nonrandom!
	int i ; 
	for (i = 0 ; i < 10 ; ++i)
		printf("%d  ", rand() ) ;
	putchar('\n')  ;
} 
