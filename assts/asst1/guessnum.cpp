/*-------------------------------------------------------------------
*  guessnum.cpp   -  guess the number

PROJECT:
  1. start CodeBlocks and type in this program.  Make some mistakes.
  2. get the program running
  3. figure out a winning stragegy and win several times to prove it.
-------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std ;
int main ()
{
   srand(time(NULL))           ;             
   int limit = 1001            ;    // 0 <= secret <= 1000 
   int secret = rand() % limit ;    // % is the "remainder" operator
   int max_tries = 10          ;    // max tries
   int guess                   ;    // input buffer
   int trial = 0               ;    // count the guesses here

   LOOPSTART:
      trial = trial + 1 ;           // count each try
      if (trial > max_tries )
      {
         cout << "Too many guesses: you lose.\n"
				<< "Secret number WAS: " << secret << endl ;;
         return -1 ;                // -1 is failure
      }
      cout << "Guess: "        ;
      cin  >> guess            ;

      if (guess < secret)           // give a hint:
         cout << "Low\n"       ;
      else
      if (guess > secret)
         cout << "High\n"      ;
      else
         cout << "RIGHT!!\n"   ;
   if (guess != secret)
      goto LOOPSTART           ;    // yes, we have goto

   cout << "Number of tries: " << trial << endl ;
   cin.get() ;
   return 0 ;  // (0 is success)
}
