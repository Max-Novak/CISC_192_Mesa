/*-----------------------------------------------------------------
	THIS IS ADVANCED: don't bother with this until you are
	really comfortable with arrays and pointers.  It's like the
	last thing to consider in your study of pointers.
*	ptrarraysort.cpp	-	access array via sorted pointers
*	pointers provide the ability to have multiple simultaneous
*	sort orders without re-arranging the data.
*
*	:w
*	Mon Sep 21 17:47:57 PDT 2015
*	g++ vector0.cpp -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std ;

int print_array (int **h , int s ) 
{
	cout << "Printing array: \n") ;
	for (int i = 0 ; i < s  ; ++i)
		cout << "*h[" << setw(3) << i << "]: " << setw(4) << *h[i]<< endl ;
}

int sort_ptrs(int **h, int s)
{
	cout << "Printing array using pointer array: \n") ;
	for (int i = 0 ; i < s ; ++i)
		for (int j = 0 ; j < s - 1 ; ++j)
		{
			if (*h[j] > *h[j+1])
				swap(h[j], h[j+1]) ;
		}
}

int main (int argc, char *argv[], char **env)
{
	if (argc != 2) { cerr << "a.out  arraysize\n" ; return -1 ; }
	int size = atoi(argv[1]) ;
	int *a , **ap ;
	a = new int[size] ;
	ap = new int*[size] ; 
	srand(time(NULL)) ;

	for (int i = 0 ; i < size ; ++i)
	{
		a[i] = rand() % 1000 ;
	}
	for (int i = 0 ; i < size ; ++i)
	{
		ap[i] = &a[i] ;
	}

	print_array(ap, size) ;
	cout << "VIA SORTED POINTERS---------------------------\n" ;
	sort_ptrs(ap, size) ;
	print_array(ap, size) ;
	cout << "REAL ARRAY ORDER---------------------------\n" ;
	for (int i = 0 ; i < size  ; ++i)
		cout << "a[" << setw(3) << i << "]: " << setw(4) << a[i]<< endl ;
	
	return EXIT_SUCCESS ;
} // main ends
