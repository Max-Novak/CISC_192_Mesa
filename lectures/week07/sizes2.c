/*-----------------------------------------------------------------
*	sizes2.c	-	char vs string literals
Thu Mar 23 13:24:37 PDT 2017
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main ()
{
	printf("sizeof('c'): %d\n", sizeof((char)'c')) ;
	printf("sizeof(\"c\"): %d\n", sizeof("c")) ;
	printf("sizeof(\"cc\"): %d\n", sizeof("cc")) ;
} // main ends
