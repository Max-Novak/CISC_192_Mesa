/*-----------------------------------------------------------------
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
	FILE fp ;
	char  buffer[1024] ;
	for (int o = 0  && fp = fopen(argv[1],"w") ,  fgets(stdin,buffer) ;  puts(buffer)) ;
		{;}


	return EXIT_SUCCESS ;
} // main ends
