/*-----------------------------------------------------------------
*	biggerbubble.cpp
*	Wed Sep 25 22:20:54 PDT 2019
*	g++ -std=c++0x
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>

using namespace std ;

// declare function in program:
void array_sort ( int * , int ) ;
void array_print( int *  , int ) ;
void iswap(int* , int* ) ;

int main (int argc, char *argv[], char **env)
{
	int i, j ;
	if (argc < 3 ) 
	{
		puts("error: no filename or size parm!\n") ;
		exit(-1);
	} 
	fprintf(stderr,"opening: %s\n", argv[1]) ;
	FILE * fp = fopen(argv[1], "w") ;
	if (!fp) { return fprintf(stderr,"no filename or size parm!\n") ; }

	int length = atoi(argv[2]) ;
	int array[length] ;

	for (int i = 0 ; i < length ; ++i) // create TEXTFILE of rand numbers
		fprintf(fp,"%u\n", rand() % 1000) ;
	fclose(fp) ;


	fopen(argv[1], "r") ;
	for (i = 0; i < length ; ++i)
		fscanf(fp,"%u\n", &array[i]) ;
	fclose(fp) ;
	array_print(array, length) ;

//sort it
	for ( j = 0 ; j < length ; ++j)
	{
		for ( i = 0 ; i < length ; ++i)
		{
			if (array[i] > array[i+1])
				iswap(&array[i], &array[i+1]) ;
		}
	}
	fp = fopen(strncat(argv[1],".bin", 4) , "w") ;
	fwrite (&array[0], sizeof(int) , length,  fp ) ;
	fclose (fp) ;  // now dump the binary file

	//print the sorted array
	array_print(array, length) ;
 
} // main ends


void iswap(int * x , int * y) 
{
	int temp = *x ;
	*x = *y ; 
	*y = temp ;
	return ;
} // iswap

void array_print( int array[] , int length) 
{
//print the unsorted array
	for (int i = 0 ; i < length ; ++i)
	{

		printf("array[% 3d]:   %12d\n", i, array[i]) ;
	}

} // end array_print() 


