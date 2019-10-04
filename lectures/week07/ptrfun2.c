/*---------------------------------------------------------
*	ptrfun2.c	-	pointers to functions as function args.
----------------------------------------------------------*/
#include <stdio.h>
#define PRDEST stdout
int main()
{
	int	x = 1,   y = 999;
	/*-----------------------------------------------------
	*	handoff: a void-function which takes a
	*	(pointer-to-a-void-function-which-takes-two-ints),
	*	a (pointer-to-an-int), and a (pointer-to-an-int)
	-----------------------------------------------------*/
	void handoff(void (*)(int*, int* ), int *, int * );

	/*-----------------------------------------------------
	*	swap: a void-function which takes two (pointers-to-ints)
	-----------------------------------------------------*/
	void swap(int *, int * );

	fprintf(PRDEST,"At main x = %d vs y = %d\n\r", x, y);
	handoff(swap,&x,&y);     /* pass swap()'s addr to handoff() */
	fprintf(PRDEST,"At main x = %d vs y = %d\n\r", x, y);

} /* main() ends  */

/*----------------------------------------------------------
*	handoff() is a "go between" function: it calls a "hit man"
*	function to do "something" (handoff() doesn't know what) on
* 	"somebody" (handoff() doesn't know who)
----------------------------------------------------------*/
void handoff (void (*pf)(int*, int*), int *a, int *b)
{
	fprintf(PRDEST,"    at one *a = %d vs *b = %d\n\r",*a,*b);
	(*pf)(a,b);              /* call function by pointer */
	fprintf(PRDEST,"    at one *a = %d vs *b = %d\n\r",*a,*b);
}

void swap(int *q, int *r)
{
	int temp;
	fprintf(PRDEST,"    at swap *q = %d, *r =  %d \n\r",
		*q, *r);

	temp = *q;
	*q = *r;
	*r = temp;

	fprintf(PRDEST,"    at swap *q = %d, *r =  %d \n\r",
		*q, *r);
}
