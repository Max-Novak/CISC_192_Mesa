/*-----------------------------------------------------------------
*	colornames-cpp	-	identify the int values
*
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ncurses.h>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	unsigned int a, b ;
	//pair[64] ;
	printf("%u  \n","BLACK") ; 
	printf("%u  \n","WHITE") ;
	printf("%u  \n","GREEN") ;
	printf("%u  \n", "RED") ;
	printf("%u  \n","BLUE") ; 


	return EXIT_SUCCESS ;
} // main ends
