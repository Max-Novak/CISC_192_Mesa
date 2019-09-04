/*-----------------------------------------------------------------
*	array001.cpp	-	demonstrate arrays
	MOST business applications use several one-dimensional arrays
	Both because it's easier, and because different "fields" in
	a business report contain different TYPES of data.
Thu Jun  9 21:34:53 PDT 2016
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int i ;
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
	string month_name[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} ;

	for (i = 0 ; i < 12 ; ++i)
		cout << month_name[i] << " " << month_days[i] << endl ;


	return EXIT_SUCCESS ;
} // main ends
