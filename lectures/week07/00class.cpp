/*-----------------------------------------------------------------
*	00class.cpp
*	first look at the structure of a class
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>

using namespace std ;

// spy agency Personel Record System
class prs
{
	private:        // (private: is the default)
	string name   ; // like: "James Bond"
	int num       ; // like: "007"
	string weapon ; // like: "Walther PPK/S"
	int missions  ; // how many times he's succeeded

	public:
	prs (string s, int n)        { this->name = s ; this->num = n; } // constructor 
	void set_name(string s)      { this->name = s; } 
	void set_mum (int n )        { this->num = n ; }
	int get_num(void) const      { return this->num ; }
	string get_name(void) const  { return this->name ; }
	// TODO: get_missions() get_weapon() 
} ;

int main (int argc, char *argv[], char **env)
{
	//create a class object variable:
	prs Seven("James Bond", 7) ;           // calling 's constructor
	// create a pointer to a class object,
	// and an object for it to point to:
	prs * cp = new prs("John Drake", 16) ; // calling constructor

	// call some object methods:
	cout << "Seven: " << Seven.get_name() << endl ;
	cout << "     : " << Seven.get_num()  << endl ;

	// call some methods via pointer to object:
	cout << "Unnamed:  " << cp->get_name() << endl ;
	cout << "       :  " << cp->get_num()  << endl ;

}
