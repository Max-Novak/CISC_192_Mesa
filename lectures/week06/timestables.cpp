/*-----------------------------------------------------------------
*	timestables.cpp	-	nesting for() loops
*	nested loops are one of the commonest control structure.
*	since we use pages of text, it's logical that the for() 
*	structure to handle pages would be common
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
	unsigned int a, b , product ;
	for ( a = 0 ; a < 17 ; ++a) 
	{
		for ( b = 0 ; b < 17 ; ++b) 
		{
			printf("%3X ", a * b) ;
		}
		putchar('\n') ;
	}
	return EXIT_SUCCESS ;
} // main ends
