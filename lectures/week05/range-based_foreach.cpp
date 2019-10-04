/*-----------------------------------------------------------------
*	range-based_foreach.cpp	-	the range-based for() loop
*
Compile:  g++ simplefor.cpp  -std=c++0x.
(range-based for() loops are not yet part of the standard.)
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

int main (int argc, char *argv[], char **env)
{
	cout << "zero--------------------------" << endl ;
	int a[20] , *p  ;
	for (int i = 0 ; i < 20 ; ++i)
	{
		a[i] = rand() % 100 ;
		cout << a[i] << endl ;
	}
	cout << "one--------------------------" << endl ;

// range-based for() loop:
	for (int x : a)
		cout << x << endl ;
	cout << "two--------------------------" << endl ;

// list-based for() loop:

/*
	for( int i : 1,3,5,7,9)
		cout << i endl ; 
	cout << "thr--------------------------" << endl ;
	*/
} // main ends
