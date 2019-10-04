/*-----------------------------------------------------------------
*	varfield.cpp	-	variable-length printf field
Mon Dec 31 15:05:13 PST 2012
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	unsigned int i ;
	char buffer[1024] ;
	for (i = 123 ; i < 3333333333333333 ; i= i + 456)
	{
		sprintf(buffer,"%u", i) ;
		printf(".%*s.\n",strlen(buffer),buffer); 
		//printf("%0*u\n",i); 
	}
}
