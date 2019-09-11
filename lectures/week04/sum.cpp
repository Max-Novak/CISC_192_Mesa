/*-----------------------------------------------------------------
*	sum.cpp	-	handy addition for all the numbers on the command line.
BUFFY:hhaller:~/data/cisc192/.week04$ a.out  34 98 1 67 2 99
a.out
34
98
1
67
2
99
Total args is: 301

*	chapter IV-6 "Configuring the IDE for boost,etc.
*	g++ vector0.cpp -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int main(int argc , char * argv[], char **env)
{
        int total = 0 ;
        int i ;
        for (i = 0 ; i < argc ; ++i)
        {
          cout << argv[i] << endl ;
          total += atoi(argv[i]);
        }
        cout << "Total args is: " << total << endl ;
}

