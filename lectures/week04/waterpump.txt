/*-----------------------------------------------------------------
*	waterpump.cpp - 	print what pgm reads
*	for as long as it has data to read.
*	Mon Feb 20 11:12:06 PST 2017
-----------------------------------------------------------------*/
#include <cctype>
#include <iostream>
using namespace std ;
int main (int argc, char *argv[], char **env)
{
	char c ;
	c = cin.get() ;
	while ( ! cin.eof())
	{
		cout.put(c )  ;
		c = cin.get() ;
	}
} 
//isalpha(c)
//c = tolower(c) 
