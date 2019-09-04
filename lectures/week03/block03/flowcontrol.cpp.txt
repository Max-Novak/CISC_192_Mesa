/*-----------------------------------------------------------------
*	flowcontrol.cpp	-	how does a program choose the path
*	it will follow?
*	various flavors of control except switch()
Lots of important little stuff: how to read till the end?
How to keep reading and writing
how to execute a loop a certain number of times
-----------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std ;

int main ()
{
	int i, j,  one = 1 , twenty = 20 ;
	bool match = false ;
	// "conditional operator: test  ?  true  : false 
	printf( "One %s twenty\n",  (one == twenty) ? "matches" : "does not match") ;

	// for() loop
	for (i = 0 ; i < 3 ; ++i) 
		cout << setw(3) << i << endl ;

	// do .. while() loop
	do
	{
		cout << i-- << endl ;	// note the '--' post incrimentation
	} while (i) ;

	match = one == twenty ;  // arithmetic, relational, assignment order
	cout << "boolean match: " << match << endl ;
	cout << "boolean match: " << std::boolalpha << match << noboolalpha << endl ;

	i = 999 ;
	cout << "Enter a number, stop with 0:" ;
	// while() loop
	while(i != 0)
	{
		cin >> i ;
		cout << i << endl ;
	}
	cout << "all done\n" ;
} // main ends
