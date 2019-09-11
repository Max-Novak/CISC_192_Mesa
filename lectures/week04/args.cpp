/*-----------------------------------------------------------------
*	cmdlineargs.cpp	-	reading parameters from the starting cmd
*	line.

-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>

using namespace std ;

// argc is the number of command line args including the "a.out"
// argv is an array of CStrings containing all args, argv[0] is
// the command which initiated the run
// env is an array of CStrings containing the user's environment



int main (int argc, char *argv[], char **env)
{
	cout << "You ran this program thus: \n" ;
	//you've been given argc, so you can process it with a for()
	for (int i = 0 ; i < argc ; ++i)
		cout << argv[i] << endl ;
	cout << "argc is: " << argc << endl ;

	// but you don't have a corresponding count for *(env[] 's elements,
	// so you'll need to point at one string after another until you come
	// to the NULL string which ends the array of cstrings

	char ** e = env ;
	while (*env)       // while there is a non-empty string
	{
		cout << *env << endl ;   // display it
		env++ ;
	}
}
