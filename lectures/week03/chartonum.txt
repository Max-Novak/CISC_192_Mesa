/*-----------------------------------------------------------------
*	chartonum.cpp - 	print what you read
*	for as long as you CAN read.
*	Show how a char can be displayed as an int even in C++....	
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	char c ;
	int  d ;

	c = cin.get() ;
	while ( ! cin.eof())
	{
		d = c ;
		cout << d << " "   ;
		c = cin.get() ;
	}
	cout.put('\n') ; // just leave screen neat
} 


