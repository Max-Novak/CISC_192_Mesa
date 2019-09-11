/*-----------------------------------------------------------------
*	singlespace.cpp	-	remove duplicate linefeeds
*	Tue Jun 14 20:43:48 PDT 2016
This is an example of how C can be used to do tiresome, time-wasting
tasks (text editing in this case) so the user user doesn't 
become a mindless drudge.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int c, lastc = 0  ;
	c = cin.get() ;
	while (!cin.eof())
	{
		if (c == '\n' && lastc == '\n')
		{
			while (c == '\n') 
				c = cin.get() ;
		}
		cout.put(c) ;
		lastc = c ;
		c = cin.get() ;
	}
} // main ends
