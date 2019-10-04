/*-----------------------------------------------------------------
*	wedgednestedloop001.cpp
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
	for (i =0 ; i < 10 ; ++i)
	{
		for (j = i ; j < 10 ; ++j)
		{
			printf("%d ", rand() % 10) ;
		}
		putchar('\n') ;
	}
	

	return EXIT_SUCCESS ;
} // main ends
