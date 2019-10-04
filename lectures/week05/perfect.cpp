/*-----------------------------------------------------------------
*	perfect.cpp	-	produce all "proper factors" of a number,
then add them.  I had to write my own factorization logic,
unlike the Unix "factor(1)" command, which only gives
the smallest prime factors, and can't be used to find 
Perfect Numbers.

Students ask me, "Why Pointers?"  True, languages like Java lack
pointer variables, and people still program with them...but the
computer itself depends on Indirect Addressing, pointers.  This
program needs them, its text output logic uses a pointer to
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
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits.h>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	bool PERFECT_ONLY ;
	unsigned long charcount, sum ;
	unsigned long i, divisor ;
	char buf[4096] , *op ;
	if ( argc > 1 && 0 == strncmp(argv[1], "-p", 2))
		PERFECT_ONLY = true ;
	else
		PERFECT_ONLY = false ;
	for (i = 1 ; i < ULONG_MAX ; i++)
	{
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
				//charcount = sprintf(op, "%lu ", divisor) ;
				op += sprintf(op, "%lu ", divisor) ;
				//op += charcount ;
			}
		}
		if (sum == i)
		{
			charcount = sprintf(op, "perfect: %lu", sum) ;
			op += charcount ;
		}
		sprintf(op, "\n") ;
		if (sum == i || !PERFECT_ONLY) 
			printf("%s", buf) ;
	}
}
