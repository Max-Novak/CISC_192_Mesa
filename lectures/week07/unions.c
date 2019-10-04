/*-----------------------------------------------------------------
*	union.c	-	demo a union.
*	Thu Jul 31 20:49:39 PDT 2003 TEK.
-----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

	union myuniontypename 
	{
	  int i ;
	  char c[4] ;
	} n ; 

void print_union(union myuniontypename * n) 
{
  printf("union fields: i: %d  c[0]:%d , c[1]:%d , c[2]:%d , c[3]:%d \n", 
  n->i, n->c[0], n->c[1], n->c[2], n->c[3]) ;
}

int main (int argc, char *argv[], char **env)
{
	n.i = atoi(argv[1]) ;
	print_union(&n) ;
}
