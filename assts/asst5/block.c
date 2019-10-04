/*-----------------------------------------------------------------
*	block.c	-	arrange text into blocks crypto util
Thu Nov 10 11:30:11 PST 2011
-----------------------------------------------------------------*/
#include <stdio.h>

int main (int argc, char *argv[], char **env)
{
	int c , count = 0 ,  blocksize ;
	if (argc != 2)
	{
		fprintf(stderr, "block n\n") ;
		return -1 ;
	}
	blocksize = atoi(argv[1]) ;
	c = getchar() ;
	while ( c != EOF)
	{
		if (!isspace(c))
			putchar(c) ;
		count++ ;
		if (count == blocksize)
		{
			count = 0 ; 
			putchar(' ' ) ;
		}
		c = getchar() ;
	}
}
