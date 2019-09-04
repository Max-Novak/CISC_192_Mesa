
/*-----------------------------------------------------------------
*
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
	int i, j ;
	for (i = 10 ; i >=0 ; --i)
	{
		for (j = i ; j < 10 ; j++)
			cout << j << "  " ;
	cout << "\n" ; }

} // main ends
