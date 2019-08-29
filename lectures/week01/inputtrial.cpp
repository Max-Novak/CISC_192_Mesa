/*-------------------------------------------
	fieldinput.cpp	-	first example
	Sun Dec 30 22:00:59 PST 2012
	T. E. Harrisburg
-------------------------------------------*/

#include <iostream>
#include <string> 
using namespace std ;

int main()
{
	string ageString ;
	string nameString ;
	string firstnameString ;
	string midnameString ;
	string lastnameString ;
	string kidsString ;
	cout << "How old are you?" ;
	cin  >> ageString ;
	cout << "What is your name (first, middle, last?" ;
	cin  >> firstnameString >> midnameString >> lastnameString;
	cout << "Crikey! " 
		<< firstnameString << " " 
		<< midnameString << " " 
		<< lastnameString 
		<< " is " << ageString << "? Really?\n" ;

	cin.get() ; // eat the end of line character:try commenting this out

	cout << "Let's try again."
		<< "What is your name (first, middle, last?\n" ;
	getline( cin , nameString) ;
	cout << "This time I got: " << nameString << endl ;
	cout << "And, how many kids have you: " ;
	cin >> kidsString ;
	 cout << "I got: " << kidsString << "\n" ;
} // main() ends

/*
	So, what have you learned?  Write a page for your programmer's
	diary.
*/

