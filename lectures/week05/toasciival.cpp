/*-----------------------------------------------------------------
* text2pos.cpp - read in text, output the position of each char
* in the alphabet.
Fri Jun 18 12:49:23 PDT 2010
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
 int c  ;
 c = cin.get() ;
 while (! cin.eof())
 {
  printf("%3d, ", c) ;
  if (c == '\n')
  	cout.put('\n') ;
  c = cin.get() ;
 } // while
} // main

