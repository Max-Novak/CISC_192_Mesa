/*-----------------------------------------------------------------
*	wedgednestedloop001.cpp
Example of programmer aptitude test: can you figure out
what this will print without running it?
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int i , j ;
	for (i = 0 ; i < 10 ; ++i)
	{
		for ( j = 0 ; j < i ; ++j)
		{
			printf("%d ", rand() % 10) ;
		}
		putchar('\n') ;
	}
	

	return EXIT_SUCCESS ;
} // main ends
