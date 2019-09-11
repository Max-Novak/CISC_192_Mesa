/*-----------------------------------------------------------------
*	string_everyother.cpp	-	print every-other character in a string
-----------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	string s = "abcdefghijklmnopqrstuvwxyz" ;
	for (int i = 0 ; i < s.length() ; i+=2)
		cout << s[i] ;
	cout << endl ;
	
} // main ends
