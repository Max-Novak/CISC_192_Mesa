/*-----------------------------------------------------------------
*	overloadfcn001.cpp	-	functions with same name	
*	when two functions have the same name and different
return or parm types, they are OVERLOADED.  This is a case
of "polymorphism".
These two "quotient" functions look at the argument lists
of the calling code, and make their own determination as to
which to run.
-----------------------------------------------------------------*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std ;
double quotient(double a, double b) ;  // first quotient() function
int quotient(int a , int b) ;          // second quotient() function

int main (int argc, char *argv[], char **env)
{
	cout << "double: " << quotient ( 22.0 , 7.0 ) << endl ; // calls first quotient()
	cout << "double: " << quotient ( 22 , 7 ) << endl ;     // calls second quotient()
	//cout << "error : " << quotient ( 10 , 22.5) << endl ; // (compiler error)
} // main ends

// same names, different arg lists:

double quotient(double a, double b)
{
	return a / b ;  
}

int quotient(int a , int b)
{
	return a / b ;
}
