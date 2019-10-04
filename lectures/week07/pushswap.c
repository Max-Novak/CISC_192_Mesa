/*-----------------------------------------------------------------
*	pushswap.c	-	demonstrate inline assembler code
*	Thu Jan 18 09:27:05 PST 2018
For simple inline assembler, variables need to be global.
The Assembler has to be in the AT&T format GAS understands,
so this is a little more advanced than HLA.
(The Stack is a FIFO data structure.)
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

	int a = 99 ;
	int b = 0 ;

int main ()
{
	printf("a: %d\nb: %d\n", a,b) ;

	asm(" push a") ;
	asm(" push b") ;
	asm(" pop a") ;
	asm(" pop b") ;

	printf("a: %d\nb: %d\n", a,b) ;
} 
