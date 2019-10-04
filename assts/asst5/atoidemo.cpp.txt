/*-----------------------------------------------------------------
*	atoidemo.cpp
*	How to get integer values from the command line
*	Mon Jul  2 06:49:34 PDT 2018 Theoni Harrisburg
*	We'll add two numbers passed to the program on the command line.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

void barf(string msg)
{
	cerr << msg << endl ; 
	exit(-1) ;
}

int main (int argc, char *argv[], char **env)
{
	int first, second ;
	if (argc < 3) barf("atoidemo number1 number2") ;
	first = atoi(argv[1]) ;
	second = atoi(argv[2]) ;
	cout << "I got: " << first << " and " << second << " for: " ;
	cout << first + second << endl ;

} // main ends
