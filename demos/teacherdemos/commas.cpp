/*-----------------------------------------------------------------
*	commas2.cpp	-	how to introduce commas into numeric fields.
*	Tue Jan 10 15:46:06 PST 2006 TEH
*  Sending the number as a string elminates a lot of compatability
*  issues, since arbitrary-sized numbers may be formatted to the 
*  users taste before calling my routine.
-----------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char * commas( char * , int ) ;

#define GROUPSIZE 3

int main (int argc, char *argv[], char **env)
{
	int x ; char b[15] ;
	printf("%30s\n",commas("", GROUPSIZE)) ;
	printf("%30s\n",commas("1", GROUPSIZE)) ;
	printf("%30s\n",commas("12", GROUPSIZE)) ;
	printf("%30s\n",commas("123", GROUPSIZE)) ;
	printf("%30s\n",commas("1234", GROUPSIZE)) ;
	printf("%30s\n",commas("12345", GROUPSIZE)) ;
	printf("%30s\n",commas("123456", GROUPSIZE)) ;
	printf("%30s\n",commas("1234567", GROUPSIZE)) ;
	printf("%30s\n",commas("12345678", GROUPSIZE)) ;
	printf("%30s\n",commas("123456789", GROUPSIZE)) ;
	printf("%30s\n",commas("1234567890", GROUPSIZE)) ;
	printf("%30s\n",commas("12345678901", GROUPSIZE)) ;
	printf("%30s\n",commas("123456789012", GROUPSIZE)) ;
	printf("%30s\n",commas("1234567890123", GROUPSIZE)) ;
	printf("%30s\n",commas("12345678901234", GROUPSIZE)) ;
	printf("%30s\n",commas("123456789012345", GROUPSIZE)) ;
	printf("%30s\n",commas("1234567890123456", GROUPSIZE)) ;
}

char * commas( char *  stotal, int groupsize)
{
	int i, place = 0  ;
	string d, s = stotal ;

	reverse(s.begin(), s.end()) ;

	for ( i = 0 ; i < s.length() ; i++)
	{
		d.append(s.substr(i,1)) ;   // copy 1 char from source to dest
		place++ ;
		if (place % groupsize == 0 && i < s.length() -1)  // no leading commas
		{
			d.append(",") ;          // insert a comma
		}
	}
	reverse(d.begin() , d.end() ) ;
	return (char * ) d.c_str() ;
} // commas ends

