/*-----------------------------------------------------------------
*	stringNumInput.cpp	-	parse a string with digits, punctuation,
etc, into the integer value it contains.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	string s ; // a string is a way of handing multi-word text data
	size_t  st ;
	int total ;
	if (argc == 1)  // there's no command-line input, so prompt:
	{
		cout << "Enter areal number with commas and other non-numeric chars: " ;
		cin >> s ;
	}
	else
	{
		s = argv[1] ;
	}
	cout << "Total at first is: " << s << endl ;
	// clean the string so it's just a number.
	// (remove commas, etc)
	// so "23,123.45" becomes "23123.45" and so on.

	for (int i = 0 ; i < s.length() ; i++)
		if (!isdigit(s[i]) )
		{
			s.erase(i,1) ;
			i-- ; // this is here for a very good reason.  what if
			      // the user typed two or more bad chars together?? 
		}

	// now we use the library function atoi() to convert the
	// string into the int it represents
	total = atoi(s.c_str())  ;
	cout << "Total is now: " << total << endl ;
	// now you can start removing quarters, dimes, nickels, etc.
	// I held off showing you this until you'd all found out how
	// iffy computer "arithmetic" can be.  It's always easier to
	// control text
} // main ends
