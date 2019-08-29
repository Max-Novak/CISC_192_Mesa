/*-----------------------------------------------------------------------
*	bitwall.c	-	convert incoming stream of bytes into stream of 1's 
*		and 0's.  Suitable for encoding secret data onto wallpaper,
*		either virtual or physical:).
-----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// assume number is contained in one byte

char * bin(unsigned char n) 
{
	static char o[9]= {"        "} ;
	if(n & 128) o[0]='1'; else o[0]= '0' ;
	if(n &  64) o[1]='1'; else o[1]= '0' ;
	if(n &  32) o[2]='1'; else o[2]= '0' ;
	if(n &  16) o[3]='1'; else o[3]= '0' ;
	if(n &   8) o[4]='1'; else o[4]= '0' ;
	if(n &   4) o[5]='1'; else o[5]= '0' ;
	if(n &   2) o[6]='1'; else o[6]= '0' ;
	if(n &   1) o[7]='1'; else o[7]= '0' ;
   return o ;
}  

int main(int argc, char *argv[]) 
{
	if (argc < 2)
	{
		fprintf(stderr,"bitwall -{e|d}\n") ;
		return -1  ;
	}
	int ENCODE ;
	unsigned char c, count, uc ;
	if (!strncmp("-d", argv[1], 2))
		ENCODE = 0 ;
	else
		ENCODE = 1 ;
	FILE * fp ;
	fp = fopen(argv[2], "r") ;
	if (!fp) fp = stdin ;

	if (ENCODE)
	{
			while( !feof(fp))
			{
				c = fgetc(fp) ;      // send a byte to the decoder
				printf("%s",bin(c)); // get a cstring back
			}
	} // if ENCODE
	else
	{ // DECODE

		while( !feof(fp))
		{
			// get 8 chars at a time and assemble an unsigned byte  based on those 8 chars...
			// this reconstitutes the binary file encoded in the wall of 7-bit ASCII
			// "Improve it" asst: handle chars neither '1' nor '0'.
			uc ^= uc ;    // zero out buffer byte
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ? 128 : 0 ; // set pwrs of 2...
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?  64 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?  32 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?  16 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?   8 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?   4 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?   2 : 0 ;
			c = fgetc(fp) ; if (c == EOF) break ;  uc += (c == '1') ?   1 : 0 ;
			putchar(uc) ;
		} /* while ends */
		fclose(fp) ;
	}
	//putchar('\n') ;
} /* main ends */

/* 
The input is the output of the bitwalpaper.c program,
which I wrote to "hide" information in a seemingly-endless
stream of 1's and 0's, suitable for printing on wallpaper
and being ignored by all detectives save the brave,
untested amateur sleuth...the one who is gonna confound
the career detectives.

The stream length will be some number evenly divisible
by 8, since I encoded eight columns with the input to
bitwalpaper.c, so as long as there is no feof() message
ab initio, I just plough ahead and harvest 8 characters
at a time.

A 'todo' switch ought to be added to cope with
line-formatted text files to sense and discard '\n' and \r'
(you never can be sure what system you're on, right?)

For each char I read, I add its positional value in Base2
to the unsigned character which will end up containing
the original input text char.  Once it's complete, I print
it, xor-out the work buffer, and repeat until my hair is
squeaky clean.
*/
