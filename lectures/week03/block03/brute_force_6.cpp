/*-----------------------------------------------------------------
*	brute_force_8.cpp	-	breach password security
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
	int a, b ,c, d, e, f, g, h ;
	for (a = 'a' ; a <= 'z' ; ++a)
	for (b = 'a' ; b <= 'z' ; ++b)
	for (c = 'a' ; c <= 'z' ; ++c)
	for (d = 'a' ; d <= 'z' ; ++d)
	for (e = 'a' ; e <= 'z' ; ++e)
	for (f = 'a' ; f <= 'z' ; ++f)
		printf("%c%c%c%c%c%c\n", a,b,c,d,e,f) ;
}
