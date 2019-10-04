/*-----------------------------------------------------------------
*	nested.cpp
*	g++ -std=c++0x
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
	for (i = 0 ; i < 26 ; ++i)
	{
		for (j = 0 ; j < 26 ; ++j)
		{
			printf("%04X ", i*j) ;
			//cout << setfill('0') << setw(4) << i * j << " " ;
		} // for j
		cout << "\n" ;
	} // for i
} // main ends
