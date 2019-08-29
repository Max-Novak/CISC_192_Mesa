/*-----------------------------------------------------------------
*	demo1.cpp	-	show uninitialized variables' contents
*  (prove you should initialize vars first or get weird results.)
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int d ;
	char c[20] , *cp ;
	cp = &c[0] ;
	puts("Why we really should initialize our variables: ") ;
	printf("uninitialized int d: %12u\n", d) ;
	for (int i = 0 ; i < 20 ; ++i)
		printf("c[%02d] : %12u\n", i, (int) c[i]) ; // cast

	return EXIT_SUCCESS ;
} // main ends
