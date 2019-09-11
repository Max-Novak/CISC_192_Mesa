/*-----------------------------------------------------------------
*	fib_recurse.cpp	-	recursion demonstrates Fibonacci numbers,
*	printed in reverse
Wed Feb 18 17:05:19 PST 2015
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

unsigned long fib ( int a, int b, int count, int max)
{
	unsigned long int result ;
	if ( count <= max)
	{
		result =  a + b ;
		cout << setw(20) << result << endl ;
		return fib(b, result,  ++count , max) ;
	}
	else
	{
		return result ;
	}

}

int main (int argc, char *argv[], char **env)
{
	cout << setw(20) << 1 << endl << setw(20) << 2 << endl ;
	fib (1, 2, 1, 40) ;

} // main ends
