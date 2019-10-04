/*-----------------------------------------------------------------
*	riddle_answer.cpp
*	Wed Sep 25 22:20:54 PDT 2019
*	g++ -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;
// declare function in program:

void array_print( int * ) ;
void iswap(int* , int* ) ;

int main (int argc, char *argv[], char **env)
{
	if (argc < 2 ) 
	{
		puts("error: sort size <CR>\n") ;
		exit(-1);
	} 

	int length = atoi(argv[1]) ;
	length = 6 ;
	length++ ;
	int array[length] ;
	array[0] = length ;
	//for (int i = 1 ; i <= length ; ++i) // load rand numbers
		//array[i] = rand()% 1000;
	array[0] = 6 ; array[1] = 5 ; array[7] = 8 ; array[2] = 4 ; array[3] = 2 ; array[4] = 1 ; array[5] = 0 ; array[6] = 7 ;
	array_print(array) ;

//sort it
	for ( int j = 1 ; j <= length ; ++j)
	for ( int i = 1 ; i <= length  ; ++i)
		if (array[i] > array[i+1])
			iswap(&array[i], &array[i+1]) ;

//print the sorted array
	array_print(array) ;
} // main ends

void iswap(int * x , int * y) 
{
	int temp = *x ;
	*x = *y ; 
	*y = temp ;
} // iswap

void array_print( int array[]) 
{
	//print the unsorted array
	int length = array[0] ;
	for (int i = 1 ; i < length ; ++i)
	{
		printf("array[% 3d]:   %12d\n", i, array[i]) ;
	}
	putchar('\n') ;
} // end array_print() 
