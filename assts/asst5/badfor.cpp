/*-----------------------------------------------------------------
*	badfor.cpp	
*	g++ -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int i, j ;
        for (i = 0 , j = 255 ; j != i ; --j, i++)
		  {
		  	printf("i %d \t %d\n", j, i) ;
			} 


	return EXIT_SUCCESS ;
} // main ends
