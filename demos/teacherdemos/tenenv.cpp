/*-----------------------------------------------------------------
*	sol.cpp - solution to 10 envelopes
*	chapter IV-6 "Configuring the IDE for boost,etc.
*	g++ vector0.cpp -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int total = 1000 ;           // a thousand bucks
	int envelopes[10] , i, j ;
	envelopes[0] = 1 ;
	cout << "Loading the envelopes: \n" ;
	j = 1 ;
	for ( i = 0 ; i < 9 ; ++i)
	{
		cout << "envelope: " << i + 1 << " contains: " << j << endl ;
		envelopes[i] =  j ;
		total -= j ;             // the bucks remaining
		j = j * 2 ;
	}
	envelopes[9] = total ;      // all remaining bucks in the last one
	for ( i = 0 ; i < 10 ; ++i)
		cout << "envelope: " << i << " =  " <<  envelopes[i] << endl ;
	return EXIT_SUCCESS ;       // it's a ZERO, OK?
} // main ends
