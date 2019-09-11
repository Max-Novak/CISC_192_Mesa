/*-----------------------------------------------------------------
*	calculate_total.cpp	-	illustrate functions.
*	we're pretending that we need to find "word totals" in order
*	to develop IDs for our Secret Agents.
*	To do it we're treating letter chars as the ints they are.
*	Thu Jan  2 09:31:33 PST 2014
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int calculate_total (string input) // calculate_total is a function
{
	int total = 0  ;
	for (int i = 0 ; i < input.length() ; ++i)
		total += input[i] ;         // add the ASCII values of the characters
	return total ;
} // calculate_total ends

int main ()
{
	int fn, mn, ln, bd ;
	string buffer ;
	cout << "Enter your first name: " ;
	cin >> buffer ;
	fn = calculate_total(buffer) ;
	cout << fn << endl ;
	cout << "Enter your middle name: " ;
	cin >> buffer ;
	mn = calculate_total(buffer) ;
	cout << mn << endl ;
	cout << "Enter your last name: " ;
	cin >> buffer ;
	ln = calculate_total(buffer) ;
	cout << ln << endl ;
	cout << "Enter your birthdate mm/dd/yyyy: " ;
	cin >> buffer ;
	bd = calculate_total(buffer) ;
	cout << bd << endl ;
	cout << "agent number: " // numerology just butts nums together
		<< fn 
		<< mn 
		<< ln 
		<< bd 
		<< endl ;
} // main ends
