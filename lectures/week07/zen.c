/*----------------------------------------------------------
* 	zen.c	-	"sort" with task time buried in IO.
* 	Written by TEK, in Turbo C 2.0.
* 	Release 1.0  February 17th, 1990
* 	Release 1.1  June 17th, 1999 dynalloc'd array.
*
* 	SUMMARY OF PROGRAM: Sort numbers without sorting.
*       Use a bitfield to accomplish the sort.
*       Open input file.
*       Set tally array bits to 0.
*       Begin Main Loop:
*    	   Read input file.
*             Use number to index into bitfield.
*             Set corresponding bit to '1'B.
*          End Main Loop.
*       For Every '1'B bit in bitfield:
*    	   Print its position.
*       End Program.
* 	MODIFICATION HISTORY
*       March 18th, 1993: Cleaned up format, changed sortarray
*	from array of ints to array of chars (doubled space
*	utilization, raising magnitude of input range to
*	0 -- 4,292,095,104.
----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
/*-------------
* 	bitmasks
-------------*/
/*
 * testsetarray contains the powers of 2 used to test or
 * set the corresponding bit in a byte.
 */
unsigned char testsetarray [] = { 128,64,32,16,8,4,2,1};
/*
 * cleararray contains the numbers which can be used as 
 * a "sieve" to permit all but the chosen bit to come
 * through when using a bitwise and (&).
 */
unsigned char cleararray [] = \
	{127,191,223,239,247,251,253,254};
unsigned char * sortarray ;      /* the bit field */
int nums ;

main(int argc, char **argv)
{
	int errorprt(void) ;
	int markit(int) ;
	int printarray(void) ;
	int c = 0, i = 0 ;
	FILE *fp;

	/*-----------------------------------------------------
	*	attempt to open file to sort
	-----------------------------------------------------*/
	if((fp = fopen(argv[1], "r"))==NULL)
	{ printf("Bad input file %s", argv[1]); return errorprt(); }
	/*-----------------------------------------------------
	*	if more than one filename on command line
	-----------------------------------------------------*/
	if(argc > 2) { printf("Only one input file at a time, please!");
		errorprt(); exit(-1); }

	/*-----------------------------------------------------
	*	initialize sort working array to zeroes
	-----------------------------------------------------*/
	while ( 0 < fscanf(fp,"%d", &c))
		if (c > nums)
			nums = c ;
	fseek(fp, 0L, SEEK_SET) ;
	/*printf("Allocating %d items\n", nums) ; */
	sortarray = (unsigned char *) malloc ( nums * sizeof(unsigned char)) ;
	if( (unsigned char *) NULL == sortarray)
	{ printf("Can't allocate %d items\n", nums) ; exit(-1) ; }
	for ( i = 0; i < nums; i++)
		sortarray[i] = 0;

	/*-----------------------------------------------------
	*	read file, setting bits in the positions
	*	corresponding to the values of the integers read
	-----------------------------------------------------*/
	while (fscanf(fp,"%d",&c) != EOF)
		markit(c);

	/*-----------------------------------------------------
	*	print out the positions of the 1 bits
	-----------------------------------------------------*/
	printarray();
	free(sortarray) ;
	return 0 ;
} /* main */

/*----------------------------------------------------------
*	printarray()-	run through the array, print the
*			positions of the set bits, ignore cleared bits.
*			Use a nested loop to process each byte and each
*			bit within each byte.
----------------------------------------------------------*/
int printarray(void)
{
	int tbyte, tbit, x;
	for ( tbyte = 0; tbyte < nums; tbyte++)
		for ( tbit = 0; tbit < 8; tbit++)
		{
			x = tbyte * 8 + tbit;
       		if ((sortarray[tbyte] & testsetarray[tbit]))
				printf("%d\n",x);
		}
	return 0;
}

/*----------------------------------------------------------
*	markit()-	receive a number, and set the bit in the
*			bit array at the position denoted by
*			that number.  Use an array of 8 "mask"
*			values to set the bit desired.
----------------------------------------------------------*/
int markit(int c)
{
	int mbyte, mbit;
	mbyte = c / 8;	  /* find the byte containing the bit */
	mbit = c % 8;     /* find bit's position in byte */
	/*-----------------------------------------------------
	*	by | (OR-ing) the "mask" with byte containing the
	*	desired bit, we preserve all other bits which may
	*	already be set, and set (or reset) the desired bit.
	-----------------------------------------------------*/
	sortarray[mbyte] = sortarray[mbyte] | testsetarray[mbit];
	return 0 ;
}

/*----------------------------------------------------------
*	errorprt()-	if program was started incorrectly,
*			print an error message and quit
----------------------------------------------------------*/
int errorprt(void)
{
	puts("\n\nZEN inputfilename [ > outputfile where ]");
	printf("inputfile == ASCII file of unsorted nums of magnitude < %lu.\n", nums * 8 * sizeof(int));
	puts("The numbers act as indices into a bitfield,");
	puts("File is read, and corresponding bits set, the bitfield is");
	puts("scanned, and any 'on' bits in the bitfield printed, providing");
	puts("a 'sort'  without sorting.  Truly a 'ZEN' algorithm.");
	puts("Note: This method discards duplicate numbers. It is useful for");
	puts("ticket sales, or other non-repetitive use.\n");
	puts("zen.c written by TEK,");
	puts("Original Algorithm from 'Programming Pearls'");
	puts(" by Jon Bentley, (c) 1986, Addison-Wesley pub.");
	return 1;
} /* errorprt */
