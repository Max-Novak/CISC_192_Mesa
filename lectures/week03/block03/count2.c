/*--------------------------------------------------------------------
*	count2.c	-	print a list of integers for use as 
*	numeric loop control in a shell script list-based "for" loop.
*			TEK, 1/16/98.
Bug fix: Wed Sep 21 13:31:05 PDT 2011 fixed < to <= on line 34,
prevented printing ONE line of output. TEK
--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char **env)
{
char *p = "Programmer: TEK" ; 
long long limit , i = 0L ;
int sign = 1, step = 1  ;
if (argc == 4) 
	step = atol(argv[3]) ;
if (argc == 3 || argc == 4) 
{
	limit = atol(argv[2]) ;
	i = atoi(argv[1]) ;
	if (limit < i) sign = -1 ;
}
else if (argc == 2) 
{
	limit = atol(argv[1]) ;
	i = 1 ;
}
else
{
	puts("\tcount2  [b] e [s] where b==begin e==end s==step") ;
	return -1 ;
}

step *= sign  ;
if (i <= limit)
{
	do
	{
		printf("%02d\n", i) ;
		i += step ;
	}					 
	while (i <= limit ) ;
} 
else
{
	do
	{
		printf("%02d\n", i) ;
		i += step ;
	}					 
	while (i >= limit ) ;
} 
return 0 ; 
}	
