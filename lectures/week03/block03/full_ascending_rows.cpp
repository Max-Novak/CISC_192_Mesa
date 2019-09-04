/*-----------------------------------------------------------------
*	ascending_numbers.cpp	-	simple for()
*
-----------------------------------------------------------------*/
#include <iostream>
#include <iomanip>

using namespace std ;

int main ()
{

	int a, b ;
	for (a = 0 ; a < 10 ; ++a)
	{
		// start at outer loop value: a, and complete digits to 9
		for (b = a ; b < 10 ; ++b)  
			cout << b << '\t' ;
		// start where prior loop stopped and print digits to
		// where it began: a.
		for (b = 0 ; b < a ; ++b)   // complete numbers to o.l.v.
			cout << b << '\t' ;
		cout.put('\n') ;
	}
}
