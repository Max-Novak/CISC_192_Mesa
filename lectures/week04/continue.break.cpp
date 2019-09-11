/*-----------------------------------------------------------------
*
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
	int i = 0 ; 

	for(i = 0 ; i < 100 ; ++i) 
	{
	 if ( i == 4 || i == 5 || i == 6)
	    continue ;
	if (i == 11 ) break ; 
	 cout << i << endl ;
	}
	return EXIT_SUCCESS ;
} // main ends
