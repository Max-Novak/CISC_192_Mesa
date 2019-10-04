#ifndef ISPRIME_H
#define ISPRIME_H
/*-----------------------------------------------------------------
*	isprime.h	-	is a number prime?
Sun Mar 29 18:53:26 PST 2009 tek
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <cmath>

using namespace std ;

bool isprime (int n)
{
	int a, x, limit ;
	limit = sqrt(n) ;
	limit++ ;
	for ( a = 2 ; a <  limit ; a++)
	{
	#ifdef DEBUG
		printf("%d mod %d == %f\n", n, a, ((double) n)/a) ;
	#endif
		if (0 == (n % a) )
			return false ;
	}
	return true ;
}
#endif
