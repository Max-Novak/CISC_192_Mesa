/*-----------------------------------------------------------------
*	2ndptr.cpp	-	illustration of pointer arithmetic
*	used with C++ for Dummies, 7th Edition
*	Theoni Harrisburg
*	Wed Oct 11 18:29:53 PDT 2017
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
	const int SIZE = 10 ;
	int a[SIZE] , i , *ip1, *ip2 ;
	for (i = 0 ; i < SIZE ; ++i)
	{
		printf("address of a[%d] ( or a + i)  == %p\n",  i, a+i) ;
	}

	return EXIT_SUCCESS ;
} // main ends
