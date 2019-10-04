/*-----------------------------------------------------------------
*	dowhile.cpp
*	chapter IV-6 "Configuring the IDE for boost,etc.
*	g++ vector0.cpp -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main ()
{
	int hr, day, mo, yr ;
	hr = day = mo = yr = 0 ;

	do
	{
		cout << "Enter hour, day, month, year: " ;
		cin >> hr >> day >> mo >> yr ;

	} while (hr == 0 || day == 0 || mo == 0 || yr == 0) ;

} // main ends
