/*-----------------------------------------------------------------
*	isprime.cpp	-	is a number prime?
tek
Sun Mar 29 18:53:26 PST 2009
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits.h>

using namespace std ;

bool isprime (int n) ;

int main()
{
	int i ; 
	for ( i = 0 ; i < 50000; i++)
		if (isprime(i))
			printf("%d is prime\n", i) ;
}


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
