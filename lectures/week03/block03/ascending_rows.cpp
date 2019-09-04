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
		for (b = a ; b < 10 ; ++b)
			cout << b << '\t' ;
		cout.put('\n') ;
	}
}
