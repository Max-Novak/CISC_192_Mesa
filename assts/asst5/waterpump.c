#include <stdio.h>
int main(int argc, char * argv[])
{
	int c ;
	c = getchar();
	while (!feof(stdin))
	{
			putchar(c) ;
			c = getchar();
	}
}
