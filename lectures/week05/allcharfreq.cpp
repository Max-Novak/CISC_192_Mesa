/*-----------------------------------------------------------------
*	allcharfreq.cpp	-	frequency of all ASCII chars
*	chapter IV-6 "Configuring the IDE for boost,etc.
*	g++ vector0.cpp -std=c++0x
Sat Feb 25 19:22:11 PST 2017
I try to make all examples good for at least two things, this one is like that:
Look at what it's doing: counting chars and reporting on chars counted.
BUT: Compare lines  33-34 vs 35.  The printf() is a more compact and controllable
way of handling printed output, but if you prefer, you are certainly welcome to use
cout.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int count[256] = {0} ;  // initialize to 0 (null)
	int c ;
	c = cin.get() ;
	while (!cin.eof())
	{
		count[c]++ ;
		c = cin.get() ;
	}
	
	for ( int i = 0 ; i <= 255 ; ++i)
	{
		if (count[i]) 
		{
		//	cout << "[" << setw(3) << setfill('0') << i << "]  " << setw(3) << count[i]  << 
		//	" " << (isgraph(i) ? (char) i : '.')  << endl ;

			printf("[ %03d]  %03d %c\n", i, count[i], (isgraph(i) ? i : '.') ) ; 
//                           "conditional operator" or ?: here ^   ^
		}
	} 
} // main ends
