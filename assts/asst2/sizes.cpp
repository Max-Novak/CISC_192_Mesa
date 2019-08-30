/*-----------------------------------------------------------------
	sizes.cpp
	Outputs the size of sveral data type's size in bytes.
	Maximus Novak
	8/29/2019
-----------------------------------------------------------------*/

#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	cout << "The following are sizes in bytes of several data types" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Size of a char is: " << sizeof(char) << endl;
	cout << "Size of a boolean is: " << sizeof(bool) << endl;
	cout << "Size of an int is: " << sizeof(int) << endl;
	cout << "Size of a short is: " << sizeof(short) << endl;
	cout << "Size of a long is: " << sizeof(long) << endl;
	cout << "Size of a long long is: " << sizeof(long long) << endl;

	cout << "The following are sizes in bytes of several floating point data types" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Size of a float: " << sizeof(float) << endl;
	cout << "Size of a double: " << sizeof(double) << endl;
	cout << "Size of a long double: " << sizeof(long double) << endl;

	cout << "The following are sizes in bytes of several pointers to data types" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Size of char pointer: " << sizeof(char *) << endl;
	cout << "Size of boolean pointer: " << sizeof(bool *) << endl;
	cout << "Size of an int pointer is: " << sizeof(int *) << endl;
	cout << "Size of a short pointer is: " << sizeof(short *) << endl;
	cout << "Size of a long pointer is: " << sizeof(long *) << endl;
	cout << "Size of a long long pointer is: " << sizeof(long long *) << endl;

	return EXIT_SUCCESS ;
}