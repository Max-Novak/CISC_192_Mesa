/*-----------------------------------------------------------------
*	cmdline.cpp
	How to access the strings which follow the program's name
	on the command line.  Try: a.out one two 333 foul
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int i ;
	for (i = 0 ; i < argc ; ++i)
		cout << argv[i] << endl ;
} // main ends
