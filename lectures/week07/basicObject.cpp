/*-----------------------------------------------------------------
*	basicObject.cpp	-	how the book would like you to use objects
*	
-----------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "basicObject.h"

using namespace std ;


int main (int argc, char *argv[], char **env)
{
	prs J("James Bond", 7) ;                  // create an object at compile time
	prs * p = new prs("Modesty Blaise", 23) ; // create an object at runtime
	J.print_record() ;
	p->print_record() ;
	doit(p) ;

} // main ends


prs::prs() { useme = true ; } // constructor

prs::prs(char * s , int n) 
{
	this->useme = true ;
	strncpy(this->name, s, sizeof(this->name)) ;
	this->num = n ;
} // constructor

char * prs::get_name(void) { return this->name ; }

int prs::get_num(void) { return this->num ; }

void prs::set_name(char * const s) { strncpy(this->name, s, sizeof(this->name)) ; }

void prs::set_num(int n) { this->num = n ; }

void prs::set_useme(bool i) { this->useme = i ; }

void prs::print_record(void)
{
	cout << "Name: " << this->get_name()  << endl ;
	cout << "Num:  " << this->get_num()  << endl ;
}
/*
 * doit() IS DECLARED friend: IN basicObject.h
 */
void doit(prs * a) 
{
	cout << "I'm printing a PRIVATE field in " << a->name << " object!\n" ;
	cout << a->name << endl ; 
	cout << a->name << endl ; 
	cout << a->name << endl ; 
}


