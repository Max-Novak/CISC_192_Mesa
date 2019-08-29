/*-----------------------------------------------------------------
*	waterpump.cpp	-	pump data through
*	you'll use this a LOT, so run it and type
*	into it.  Really, it's time well spent.
NOTICE: we use c = cin.get() instead of cin >> c, because
we want "raw" input, we want to read and store ALL chars,
including end of line ('\n') and space in general.
cin >> uses whitespace as DELIMITERS or word boundaries,
so they don't get stored and printed out.
This illustrates the "high level language" issues, and
why we prefer to work down low in C country.  Real programmers
don't want the tools to do their thinkng for them.
-----------------------------------------------------------------*/
#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
	char c , total = 0 ;
	c = cin.get() ;
	do 
	{
		cout << c  ;
		c = cin.get() ;
	} while (! cin.eof()) ;
	return 0 ;
}
