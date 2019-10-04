/*-----------------------------------------------------------------
*	ansicolors.cpp	-	colored text on vt-100
*
-----------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
using namespace std;

int colorprintf(int back, int fore, char * text)
{
		printf("\033[%2d;%2dm%s\033[0m",  back, fore, text) ;
}

int main (int argc, char *argv[], char **env)
{
for (int i = 30 ; i < 40 ; i++)
	for (int j = 40 ; j < 50 ; j++)
	{
		if (i == j) continue ;
		char buf[1024] ;
		sprintf(buf,"%s\n", argv[1]) ;
		colorprintf(i, j, buf) ;
		//printf("\033[%2d;%02dm%s\033[0m",  i, j, "COLOR TEXT\n") ;
		//printf("%c[%2d;%02dm%s\033[0m\n", 033, i, j, "COLOR TEXT") ;
	}

  // echo -e $i $j "\033[${i};${j}mCOLOR\033[0m"
}
/*
 This small script prints all available ANSI-colors on the terminal.

#!/bin/bash
 
for i in 30 31 32 33 34 35 36 37 39
do
 for j in 40 41 42 43 44 45 46 47 49
 do
   # skip if same fore- and backgroundcolor
   if [ $j -eq $[ i + 10 ] ]; then
     continue
   fi
   echo -e $i $j "\033[${i};${j}mCOLOR\033[0m"
 done
done
*/
