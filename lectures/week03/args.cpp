/*-----------------------------------------------------------------
*	args.cpp0 	-	show arg processing
*
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	cout << "argc: " << argc << endl ;
	for (int i = 0 ; i < argc ; ++i)
	{
		printf("argv[%d]: %s\n", i, argv[i]) ;
	} // for

} // main ends
