/*-----------------------------------------------------------------
*	perfect.cpp	-	produce all "proper factors" of a number,
then add them.  I had to write my own factorization logic,
unlike the Unix "factor(1)" command, which only gives
the smallest prime factors, and can't be used to find 
Perfect Numbers.

Students ask me, "Why Pointers?"  True, languages like Java lack pointer
variables, and people still program with them...but the computer itself
depends on Indirect Addressing, pointers.  In fact, the first real logic
appliance I programmed, the HP-67, had and (i) key which used indirect
(pointer) addressing.

This program needs them, its text output logic uses a pointer to
advance through an output buffer which is augmented with
more and more text using sprintf() calls, then, only at the
end of the calculation, is it decided whether to print or not.
Without pointers, some of the output line would be printed
before we could really know if we wanted it to be, and we'd
need some postprocessing kludge to eliminate the unwanted lines.
Pointers embody a controversy which is in a quirky way
technically similar to that surrounding guns.  If you don't 
aim them carefully, they give great trouble.  But all the
real programming cowboys and cowgirls use them, and there is
no real argument that you can program an operating system
without them.
T. E. Harrisburg
Sun Mar 29 18:53:26 PST 2009
-----------------------------------------------------------------*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits.h>

using namespace std ;

	unsigned long long i, perfs , defs, abuns, num ;

//__sighandler_t {aka void (*)(int)
void  die()  // terminate writing totals
{

	extern unsigned long long perfs , defs, abuns ;

	puts("+++++++++++++++++++++++++++++++++++++") ;
	printf("Perfect   numbers: %10Lu\n", perfs) ;
	printf("Abundant  numbers: %10Lu\n", abuns) ;
	printf("Deficient numbers: %10Lu\n", defs) ;
	printf("Current Candidate: %10Lu\n", i) ;

	sleep(2) ;
	signal (SIGINT, SIG_IGN) ;
	signal (SIGHUP, SIG_IGN) ;
	signal (SIGKILL, SIG_IGN) ;

	exit(0) ;
} /* die() */

int main (int argc, char *argv[], char **env)
{
/*-----------
        trap Control-C interrupt, so checkpoint file written.
-----------*/
        signal (SIGHUP, die) ;
        signal (SIGINT, die) ;
        signal (SIGKILL,die) ;

	bool PERFECT_ONLY ;
	bool LONG_FORM = false ;
	extern unsigned long long perfs , defs, abuns, i ;
	unsigned long charcount, sum ;
	unsigned long  divisor ;
	char buf[4096] , *op ;
	if ( argc > 1 && 0 == strncmp(argv[1], "-p", 2))
	{
		PERFECT_ONLY = true ;    // print only perfect numbers
	}
	else if(argc > 1 && 0 == strncmp(argv[1], "-P", 2))
		{
			PERFECT_ONLY = false ;// print all numbers, identify their categories
			LONG_FORM = true ;
		}
	else
		PERFECT_ONLY = false ;

	perfs = defs = abuns = 0ll ;
	for (i = 1 ; i < ULONG_LONG_MAX ; i++)
	{
		num = i ;
		op = buf ;
		sum = 0  ;
		charcount = sprintf(op, "%lu: ", i) ;
		op += charcount ;
		//for (divisor = 1 ; divisor <= 1 + (int) sqrt((double)i) ; divisor++)
		for (divisor = 1 ; divisor < i ; divisor++)
		{
			if (0 == ( i % divisor) )
			{
				sum += divisor ;
				charcount = sprintf(op, "%lu ", divisor) ;
				op += charcount ;
			}
		}
		if (sum == i)
		{
			perfs ++ ;
			charcount = sprintf(op, " %lu :perfect", sum) ;
			op += charcount ;
		}
		else if (sum > i)
			{
				abuns++ ;
				charcount = sprintf(op, "%lu :abundant", divisor) ;
				op += charcount ;
			}
		else
			{
				defs++ ;
				charcount = sprintf(op, "%lu :deficient", divisor) ;
				op += charcount ;
			}

		sprintf(op, "\n") ;
		if (sum == i || !PERFECT_ONLY) 
			printf("%s", buf) ;
	}
}

