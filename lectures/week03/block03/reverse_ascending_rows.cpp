/*-----------------------------------------------------------------
*	reverse_ascending_numbers.cpp	-	simple for()
*
-----------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std ;

int main ()
{

	int a, b ;
	for (a = 0 ; a < 10 ; ++a)
	{
		for (b = 0 ; b < a ; ++b)
			cout << " \t" ;      // print leading whitespace
		for (b = a ; b < 10 ; ++b)
			cout << b << '\t' ; // print numbers in row
		cout.put('\n') ;
	}
}
