/*-----------------------------------------------------------------
*	fib2.cpp	-	a number series (Fibonacci)
*	each number is the sum of the two before it.
This is how a lot of flowers arrange their petals.
(I'm thrilled that a plant is smarter than me.)
Mon Aug 27 16:37:43 PDT 2012
-----------------------------------------------------------------*/
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std ;
int main ()
{
	long long int a , b , c, i ;
	a = 1 ;
	b = 2 ;
	i = 2 ;
	cout << setw(50) << 1 << endl ;
	cout << setw(50) << 2 << endl ;
	while (i < 3001)
	{
		c = a + b ;
		a = b ;
		b = c ;
		cout << setw(50) << c << endl ;
		++i ;
	}
} 
