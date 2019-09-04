/*-----------------------------------------------------------------
*	simpleIf.cpp	-	pretty simple "if" example
We're doing a little numerology, too.
Numerology is bunk, by the way.
Tue Sep  2 23:17:00 PDT 2014 T.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	int age, total ;
	string name ;
	cout << "How old are you? :" ;
	cin >> age ;
	cout << "And what's your full name? : " ;
	cin.ignore() ;
	getline(cin, name) ;
	//cin >> name ; BAD, BAD DOG!
	cout << "OK, " << name 
		<< " let's do your numbers: " << endl  
		<< "Your age is: " 
		<< age 
		<< " and the length of your name is: "
		<< name.length() << endl ;
	total = name.length() + age ;
	cout << "Total: " << total << endl ;
	if (total % 2)
		cout << "You are ODD\n" ;
	else
		cout << "You are EVEN\n" ;
} // main ends
