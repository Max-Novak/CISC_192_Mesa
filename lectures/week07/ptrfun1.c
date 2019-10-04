/*---------------------------------------------------------
*	ptrfun1.c	-	pointers to functions as function args.
----------------------------------------------------------*/
#include <stdio.h>
#define PRDEST stdout
int main()
{
	int (* ptr_holder)(const char *, ...) ;
	ptr_holder = printf ;
	ptr_holder("Hello, %d World!\n", 9);
	//ptr_holder= puts ;
	//ptr_holder("Hello,  World!\n");
	//puts("Hello, %d World!\n", 9);

} /* main() ends  */

