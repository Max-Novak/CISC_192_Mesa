/*-----------------------------------------------------------------
*	brute_force_2.cpp	-	breach password security
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
	int a, b ;
	for (a = 'a' ; a <= 'z' ; ++a)
	{
	for (b = 'a' ; b <= 'z' ; ++b)
		cout << (char) a << (char) b << ' ' ;
	cout << endl ;
	}
}
