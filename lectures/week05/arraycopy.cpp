/*-----------------------------------------------------------------
*	arraycopy001.cpp	-	how to copy array contents without loops
*	memcpy() is a C library version of the CPU's copy operator.
It's as fast as any C call can be, and requires no loop overhead.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std ;

void print_array(int* , int) ;

int main (int argc, char *argv[], char **env)
{
	const int SIZE = 5 ;
	int a[SIZE] , b[SIZE] ;
	for (int i = 0 ; i < SIZE ; ++i)
		a[i] = i ;
	print_array(b, SIZE) ;
	memcpy(b, a, sizeof(b)) ;
	print_array(b, SIZE) ;
} // main ends

void print_array(int * array , int size)
{
	for (int i = 0 ; i < size ; ++i)
		cout << setw(4) << array[i] << endl ;
	cout << "----------------------------------\n" ;
	return ;
} // print_array
