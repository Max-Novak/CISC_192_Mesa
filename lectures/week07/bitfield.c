/*----------------------------------------------------------
*	bitfield.c	-	bitfields, unions, ? :, 2's compliment.
*			T. 3/90.
----------------------------------------------------------*/
#include <stdio.h>
void main (void)
{
	struct bfint 
	{
		unsigned int h : 1 ;
		unsigned int g : 1 ;
		unsigned int f : 1 ;
		unsigned int e : 1 ;
		unsigned int d : 1 ;
		unsigned int c : 1 ;
		unsigned int b : 1 ;
		unsigned int a : 1 ;
	}  ;

	union
	{
		signed char y ;	  /* define the same area of RAM as */
		struct bfint bf ;	 /* both a char and a field of bits */
	} x ;
	for ( x.y = -5; x.y < 5 + 1; x.y++)
		printf("x.y is:  %c%c%c%c%c%c%c%c   val %d\n",
		x.bf.a ? '1' : '0' , x.bf.b ? '1' : '0' ,
		x.bf.c ? '1' : '0' , x.bf.d ? '1' : '0' ,
		x.bf.e ? '1' : '0' , x.bf.f ? '1' : '0' ,
		x.bf.g ? '1' : '0' , x.bf.h ? '1' : '0' , x.y ) ;
} /* main */
/*
x.y is:  11111011   val -5
x.y is:  11111100   val -4
x.y is:  11111101   val -3
x.y is:  11111110   val -2
x.y is:  11111111   val -1
x.y is:  00000000   val 0
x.y is:  00000001   val 1
x.y is:  00000010   val 2
x.y is:  00000011   val 3
x.y is:  00000100   val 4
x.y is:  00000101   val 5
*/
