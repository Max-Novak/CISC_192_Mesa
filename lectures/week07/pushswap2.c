/*-----------------------------------------------------------------
*	pushswap2.c	-	demonstrate inline assembler code
*	Thu Jan 18 09:27:05 PST 2018
For simple inline assembler, variables need to be global.
The Assembler has to be in the AT&T format GAS understands,
so this is a little more advanced than HLA.
(The Stack is a FIFO data structure.)
Now, this is reaching, since Basic Inline Asm statements may
only mapulate GLOBAL VARIABLES.
Later I'll illustrate Advanced Inline Asm.
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

	int i, j , size ;
	int a = 99 ;
	int b = 0 ;
	int * array  ;
	int *ip1, *ip2 ;

void print_array(int * , int) ;
void swap(int * ip1 , int * ip2)
{
	int temp = *ip1 ; 
	*ip1 = *ip2 ;
	*ip2 = temp ;
} 

int main (int argc, char *argv[])
{
	size = atoi(argv[1]) ;  // size on command line
	array = malloc( sizeof(int) * size) ;
	for (j = 0 ; j < size ; ++j)
		array[j] = rand() % 100 ;   //reverse sort order
	print_array(array, size) ; puts("------------") ;

	for (j = 0 ; j < size ; ++j)
	{
		for (i = 0 ; i < size-1 ; i++)
		{
			ip1 = &array[i] ;
			ip2 = ip1 + 1 ;
			//if ( array[i] > array[i+1] )
			if ( array[i] > array[i+1] )
			{  // swap two numbers
				asm(" push (ip1)") ;
				asm(" push (ip2)") ;
				asm(" pop  (ip1)") ;
				asm(" pop  (ip2)") ;
				swap(ip1, ip2) ;
			}
		} //for i	 
	} // for j
	print_array(array, size) ;
} 

void print_array(int array[], int size)
{
	int i ;
	for (i = 0 ; i < size ; ++i)
		printf("array[%d] : %d\n", i, array[i]) ;
}
