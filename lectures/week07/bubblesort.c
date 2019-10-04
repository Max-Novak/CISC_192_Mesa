/*-----------------------------------------------------------------
*	bubblesort.c
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void print_array( int a[] , int size)
{
	int i ;
	for ( i = 0 ; i < size ; ++i)
		printf("%5d\n", a[i]) ;
	puts("===============================================") ;
	return ;
}

int SIZE = 10000 ;
int main (int argc, char *argv[], char **env)
{

	int i, j, array[SIZE] ;
	for (i = 0 ; i < SIZE ; ++i) array[i] = rand() % 1000 ; // fill array w/rand
	print_array(array, SIZE) ;

// SORT BEGINS HERE
	for (i=0 ; i < SIZE ; ++i)
	{
		for (j = 0 ; j < SIZE-1 ; ++j)
		{
			if (array[j] > array[j+1])
			{
				swap(array[i], array[i+1]) ;
			}
		}
	}
// SORT ENDS HERE
	print_array(array, SIZE) ;
	return EXIT_SUCCESS ;
} // main ends
