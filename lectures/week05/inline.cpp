/*-----------------------------------------------------------------
*	inline001.cpp	-	inline assembler in C++
Mon Feb 26 11:14:33 PST 2018
the "placeholders" (%0, %1, %2) allow the assembler to 
assign registers to the placeholder variables
-----------------------------------------------------------------*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
 int src = 1;
     int dst;
     
     asm ("movl %1, %0\n\t"
         "addl $1, %0"
         : "=r" (dst)
         : "r" (src));
     
     printf("%d\n", dst);
} // main ends
