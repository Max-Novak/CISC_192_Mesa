/*-----------------------------------------------------------------
*	compiler_defines.cpp
	the compiler creates several useful string constants.
Sun Dec 24 10:37:04 PST 2006
*
-----------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
using namespace std;

int main (int argc, char *argv[], char **env)
{
	puts(__FILE__) ;
	puts(__DATE__) ;
	puts(__TIME__) ;

}

