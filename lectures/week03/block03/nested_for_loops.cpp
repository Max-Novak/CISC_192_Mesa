/*-----------------------------------------------------------------
*	nested_for_loops.cpp	-	why we use one loop inside another.
Wed Jan 21 20:06:53 PST 2015
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	cout << "Let's print the times tables!\n    " ;
	for (int i = 0 ; i < 13 ; ++i)
		cout << setw(2) << i << "  " ;
	cout << endl ;
	for (int i = 0 ; i < 13 ; ++i)
	{
		cout << setw(2) << i << " " ;
		for (int j = 0 ; j < 13 ; ++j)
		{
			cout << setw(3) << i * j << " " ;
		}
		cout << endl ;
	}



	return EXIT_SUCCESS ;
} // main ends
