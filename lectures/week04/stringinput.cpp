/*-----------------------------------------------------------------
*	stringinput.cpp	-
Convert std::string's contents to CString so we can use atoi(), 
plus demo std::stoi which will become available in C++0X.
Wed Jan 19 14:17:40 PST 2011

This example shows how to delay "conversion to numbers" 
and process the characters in string input for greater accuracy.
It also shows how to write a program your user can use with
command-line arguments OR interactively.  (Most users
don't like "interactive" (prompting) programs because they
contaminate the output stream and waste the user's time.)
COMPLILE WITH:        g++ --std=c++0x stringinput.cpp
-----------------------------------------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	string s ; // a string is a way of handing multi-word text data
	unsigned int total ;
	if (argc == 1)  // there's no command-line input, so prompt:
	{
		cout << "Enter an amount in US currency: " ;
		/*---------
		Don't use doubles, since there is a tendency to 
		lose pennies in rounding.  Treat all money as
		a total of integral pennies when calculating,
		and input them as strings to allow for user idiocy.
		---------*/
		cin >> s ;
	}
	else
	{
		s = argv[1] ;
	}
	cout << "Total at first is: " << s << endl ;
	// clean the string so it's just a number of pennies:
	// (remove decimal point/period)
	// so "123.45" becomes "12345" and so on.

	for (int i = 0 ; i < s.length() ; i++)
		if (!isdigit(s[i]) )
		{
			s.erase(i,1) ;
			i-- ; // this is here for a very good reason.  what if
			      // the user typed two or more periods??  
					// A-HAH! (It's Just a Jump to the Left).
		}

	// we pull out the string's Array of Char, and then
	// we use the library function atoi() to convert the
	// CString into the int it represents
	total = atoi(s.c_str()) ;

	// alternatively, we have the Std Library function for string objects:
	total = std::stoi(s) ;
	cout << "Total is now: " << total << endl ;

	// now you can start removing quarters, dimes, nickels, etc.
	// I held off showing you this until you'd all found out how
	// iffy computer "arithmetic" can be.  It's always easier to
	// control text than numbers.
} // main ends
