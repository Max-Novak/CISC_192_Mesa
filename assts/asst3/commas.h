#ifndef COMMAS_H
#define COMMAS_H

/*-----------------------------------------------------------------
*	commas2.cpp	-	how to introduce commas into numeric fields.
*	Tue Jan 10 15:46:06 PST 2006 TEH
*  Sending the number as a string elminates a lot of compatability
*  issues, since arbitrary-sized numbers may be formatted to the 
*  users taste before calling my routine.
Sun Mar 17 22:14:59 PDT 2013 fixed bug: cannot use string::c_str()
as a reference, since it only exists on the return stack.  
Substituted an array of char.
-----------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

string commas( string , int ) ;

#define GROUPSIZE 3
#undef TRIAL
#ifdef TRIAL
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
#endif

string commas( string  stotal, int groupsize)
{
	int i, place = 0  ;
	char buf[1024] ;	
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
	//strncpy( buf, d.c_str(), sizeof(buf)-1)  ;
	//strncpy(stotal, buf, sizeof(stotal)) ;
	stotal = d ;
	return stotal.c_str() ;
} // commas ends

#endif
