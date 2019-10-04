/*-----------------------------------------------------------------
*	p70example.cpp
*	chapter IV-6 "Configuring the IDE for boost,etc.
*	g++ vector0.cpp -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int sum (int , int , int ) ;

int main (int nNumberofArgs, char* pszArgs[])
{
// input the first argument....
	cout << sum (3, 55, 666) << endl ;
	int nArg1 ;
	cout << "enter arg1: " ;
	cin >> nArg1 ;
	// and the second
	int nArg2 ;
	cout << "Enter arg2: " ;
	cin >> nArg2 ;

	// now decide what to do
	if (nArg1 > nArg2) 
	{
		cout << "Arg 1 is grater than arg 2" << endl ;
	}
	else if (nArg1 < nArg2)
	{
		cout << "Argument 1 is less than arg2" << endl ;
	}
	else
		cout << "Wull, then they must be equal, fellows!" << endl ;

} // main ends

int sum (int a , int b , int c )
{
	return (a + b + c) / 3 ;
}
