#include <stdio.h>

int main(int argc, char **argv)
{
	int a=10,b=20,c;
	asm
	{
  	 movl $a,%eax
  	 movl $b,%ebx
  	 add %eax,%ebx
  	 movl %eax, $c
	}//asm
printf("Result %d",c);
return 0;
}
