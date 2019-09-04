/*-----------------------------------------------------------------
*	possible_passwords.cpp	-	password length determines how many
*	unique passwords are possible, and thus how long a brute-force
*	attack will take.
*	Observe how sprintf() works.  This allows you to use
*	printf() formatting and cout << stream output.
*	C++ text formatting is idiotic.
*	You should have noticed that even though I use standard C 
*	output, the numbers have commas.
*	Look at commas.h.  You may take it with you.
*  Sun Feb 11 12:16:54 PST 2018
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "commas.h"

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	const double letters = 26 ;
	double length ;
	char buffer[400] ;
		printf("Length                Possible Passwords\n") ;
	for (length = 2 ; length <= 20 ; ++length)
	{
		sprintf(buffer,"%.0f", pow(letters,length)) ;
		//printf("%2.0f\t%40.0f\t%e\n", length, pow(letters,length), pow(letters,length)) ;
		printf("%2.0f\t%40s\t%e\n", length, commas(buffer,3), pow(letters,length)) ;


	}
}
