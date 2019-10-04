/*-----------------------------------------------------------------
*	countCase.cpp	-	impliment the methods of a countCase object
The simplest way to do an Object program: all in one *.cpp file.
First, let's understand the class' basics.
Take your time and go over this code, there is a lot of information
here, even though it's a simple program.
-----------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std ;

class countCase
{
	/*--------------------------
	keep track of how many chars are uppercase, lowercase,
	punctuation, space, and digits:
	---------------------------*/
	int uppercount ;
	int lowercount ;
	int spacecount ;
	int punctcount ;
	int digitcount ;
	int alphabet[26] ; // count of letters

public:
	countCase()  // constructor
	{
		// set all letter totals to 0 by zeroing whole array with memset()
		memset(alphabet, 0 , sizeof(int) * 26) ;
		// see how these lines are all one assignment statement?
		this->uppercount =
		this->lowercount =
		this->spacecount =
		this->punctcount =
		this->digitcount = 0 ;
		cout << "countCase Constructor running....\n" ;
	}  // what do you think?

	~countCase()  // destructor
	{
		cout.put('\n') ;
		for ( int i = 0 ; i < 26 ; ++i)
			cout << (char) (i + 'a') << "  " << setw(4) <<  alphabet[i] << endl ;
		cout << "lowercount: " << this->lowercount << endl ;
		cout << "uppercount: " << this->uppercount << endl ;
		cout << "spacecount: " << this->spacecount << endl ;
		cout << "punctcount: " << this->punctcount << endl ;
		cout << "digitcount: " << this->digitcount << endl ;
	}

	// when we have a char, we pass it to the count "method":
	char count(char c)
	{
		if (isalpha(c))
		{
			c = tolower(c) ;
			alphabet [c - 'a'] ++ ; // count it in the array
		}
		if (isupper(c))
		{
			this-> uppercount++ ;
			c = tolower(c) ;
		}
		if (islower(c))   // test both, (it may not be alpha at all)
		{
			this->lowercount++ ;
			c = toupper(c) ;
		}

		if (isspace(c))
		{
			this->spacecount++ ;
			c = toupper(c) ;
		}
		if (ispunct(c))
		{
			this->punctcount++ ;
			c = toupper(c) ;
		}
		if (isdigit(c))
		{
			this->digitcount++ ;
			c = toupper(c) ;
		}
		return c ;     // just in case later code wants char back...
	} // count
} ; // class countCase ends

int main()
{
	countCase f ;
	int c = cin.get() ;  // main does the input
	while (!cin.eof())
	{
		f.count(c)  ;    // the Object keeps track of the count
		if (isprint(c))
			cout.put(c) ;
		else
			cout.put('.') ;  // if it's invisible, print a dot...
		c = cin.get() ;
		if ( c == '\n') cout.put(c) ; // don't process line feeds
	}
	c = cin.get() ;
	// the destructor also prints the totals
	// usually we don't call destructors, they get called automatically
	// if we DID manually call it, we'd uncomment the next line:
	f.~countCase() ; // kill it kill it kill it
	// did you see it being called as the program ended?
}
