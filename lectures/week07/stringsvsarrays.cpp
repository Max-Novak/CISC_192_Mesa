/*-----------------------------------------------------------------
*	stringsvsarrays.cpp	-	examples to illustrate
*	Theoni Harrisburg
*	Wed Oct 11 18:37:50 PDT 2017
*	g++ -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std ;

int main ()
{
	char ca [1024] = "These are the times" ;
	char cb [1024] = "Which try men\'s souls" ;
	int sl = strlen(ca) ;
	string s1 = "These are the times" ;
	string s2 = "Which try men\'s souls" ;
	system("clear") ;

	// to join two arrays of char:
	//strncat( cp , cb, 1024) ;
	strncat( ca , cb, 1024) ;
	printf("\n\nstrncat(cb, ca, 1024 produces: %s\n\n\n", ca) ;
	s1 += s2 ;
	printf("s1 += s2 produces: %s\n", s1.c_str()) ;
} 
