/*-----------------------------------------------------------------
*   pass_by_ref_ptr.c   -   demonstrate use of pointers 
*        to allow functions to affect vars in the calling 
*        routine, outside the main() "scope".
study this short program to understand function prototypes.
*   Wed jul 14 08:56:40 PDT 2004 TEK.
C only supports pass by value, so if you want a function to
change what's passed to it, you must use pointers.
C++ supports "references", which are a bad idea, lacking
immediate transparency when reading the code.
if pointers are handguns, refrences are concealed carry.
-----------------------------------------------------------------*/
#include <stdio.h>

void exchange( int  , int ) ;
void swap(int *, int* );

int main (int argc, char *argv[], char **env) {
   int i = 0 , j = 9999 ;

	puts("Pass by value (copies)") ;
	printf("i: %d  j:  %d\n", i, j) ;
	exchange (i, j) ;
	printf("i: %d  j:  %d\n", i, j) ;

	puts("\nPass by reference (pointers)") ;
	printf("i: %d  j:  %d\n", i, j) ;
   swap(&i, &j) ;  /* pass their ADDRESSES */
	printf("i: %d  j:  %d\n", i, j) ;
} /* main ends */

void exchange( int x , int y)
{
	int temp = x ;
	x = y ;
	y = temp ;
}

void swap (int *x, int *y) /* receive POINTERS (addresses) */
{ 
   int temp = *x ;
   if (*x == *y) return ;
   *x = *y ;
   *y = temp ;
} /* swap ends */
