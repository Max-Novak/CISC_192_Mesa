// recursion
#include <stdio.h>

int fact(int x) ; 
int main()
{
	
	for (int x = 1 ; x < 10 ; ++x)
	printf("fact of %d == %d\n", x, fact(x)) ;

}


int fact(int x)
{
	if (x == 1 ) 
		return x ;
	else
	return fact( x - 1) * x ;
}
