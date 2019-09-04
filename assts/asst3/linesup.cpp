/*-----------------------------------------------------------------
	linesup.cpp
	Extrapolate the values in min, sec, hours from the number of years
	Maximus Novak
	9/3/2019
-----------------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <stdlib.h>
#include <commas.h>

using namespace std ;

int main()
{
    //declarations
    long hours, minutes, days, seconds, years ;

    //take user input and calculate values
    printf("Enter your age in years: ") ;
    cin >> years ;
    days = .5 + (365.25 * years) ;
    hours = days * 24 ;
    minutes = hours * 60 ;
    seconds = minutes * 60 ;

    //output to user
    cout << "Age in years:   " << setw(15) << years << '\n' ; 
    cout << "Age in days:    " << setw(15) << days << '\n' ; 
    cout << "Age in hours:   " << setw(15) << hours << '\n' ; 
    cout << "Age in minutes: " << setw(15) << minutes << '\n' ;
    cout << "Age in seconds: " << setw(15) << seconds << '\n' ; 

    return 0;
}