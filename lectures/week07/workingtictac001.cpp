/*-----------------------------------------------------------------
*	tictc001.cpp	-	ttt server for 2 human players
Sun Apr  6 19:05:10 PDT 2014
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std ;

bool check_won(char [3][3]) ;
void print_board(char[3][3]) ;
bool move(int, int) ;
struct coord_pair
{
	int x ;
	int y ;
} ;
int main (int argc, char *argv[], char **env)
{
	/*
		0,0  0,1  0,2
		1,0, 1,1, 1,2
		2,0, 2,1  2,2
	*/
	int moves = 0 ;
	bool won = false ;
	char board[3][3] ;

	int playerXmove, playerOmove ;
	int i, j ;
	int X = 1 ;
	int O = 0 ;
	coord_pair coords[9] ;
	coords[0].y = 0 ; coords[0].x = 0 ;
	coords[1].y = 0 ; coords[1].x = 1 ;
	coords[2].y = 0 ; coords[2].x = 2 ;
	coords[3].y = 1 ; coords[3].x = 0 ;
	coords[4].y = 1 ; coords[4].x = 1 ;
	coords[5].y = 1 ; coords[5].x = 2 ;
	coords[6].y = 2 ; coords[6].x = 0 ;
	coords[7].y = 2 ; coords[7].x = 1 ;
	coords[8].y = 2 ; coords[8].x = 2 ;

	cout << "DEBUG: \n" ;
	printf(" %d, %d | %d, %d | %d, %d\n", coords[0].x, coords[0].y, coords[1].x,coords[1].y, coords[2].x,coords[2].y) ;
	printf("------------\n") ;
	printf(" %d, %d | %d, %d | %d, %d\n", coords[3].x, coords[3].y, coords[4].x,coords[4].y, coords[5].x,coords[5].y) ;
	printf("------------\n") ;
	printf(" %d, %d | %d, %d | %d, %d\n", coords[6].x, coords[6].y, coords[7].x,coords[7].y, coords[8].x,coords[8].y) ;

puts("=======================") ;
	for (i = 0 ; i < 3 ; i++) for (j = 0 ; j < 3 ; j++) board[i][j] = ' ' ;
	// re-write to alternately service players, half as long.
	while (!won && moves < 9) 
	{
		printf(" 1 | 2 | 3\n") ;
		printf(" 4 | 5 | 6\n") ;
		printf(" 7 | 8 | 9\n\n\n") ;
		print_board(board) ;
		cout << "PlayerX: " ;
		cin >> playerXmove ;
		playerXmove-- ;
		if (isspace(board[coords[playerXmove].y][coords[playerXmove].x])) 
			board[coords[playerXmove].y][coords[playerXmove].x] = 'X' ;
		print_board(board) ;
		++moves ;
		won = check_won(board) ;
		if (won) goto bottom_loop ;
		cout << "PlayerO: " ;
		cin >> playerOmove ;
		playerOmove-- ;
		if (isspace(board[coords[playerOmove].y][coords[playerOmove].x]))
			board[coords[playerOmove].y][coords[playerOmove].x] = 'O' ;
		print_board(board) ;
		++moves ;
		won = check_won(board) ;
		if (won) goto bottom_loop ;
	bottom_loop: cout << "Bottom_loop\n" ;
	} // while

	return EXIT_SUCCESS ;
} // main ends
//====================================================================
void print_board(char board[3][3])
{
	int i, j ;
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]) ;
	printf("------------\n") ;
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]) ;
	printf("------------\n") ;
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]) ;


} // print_board

//====================================================================
bool check_won(char board [3][3])
{
	int i, j , result1, result2 ;
	char current = ' ' ;
	// check rows
	for (i = 0 ; i < 3 ; ++i)
		if (isspace(board[i][0]) 
		|| isspace(board[i][1]) 
		|| isspace(board[i][2]))
	{
		goto check_cols ; // no point in looking for a win
	}
	else // do the test
	{
		for (i = 0 ; i < 3 ; ++i)
		{
			if (  (board[i][0] == board[i][1]) 
				&& (board[i][1] == board[i][2])
				&& (!isspace(board[i][0])) 
				&& (!isspace(board[i][1]) )
				&& (!isspace(board[i][2] )) ) 
			{
				cout << "row " << i << " win!\n" ;
				goto won_now ;
			} //if
		} // for
	} // else rows
	// check cols
	check_cols: 
		for (i = 0 ; i < 3 ; ++i)
		{
			if (  (board[0][i] == board[1][i]) 
				&& (board[1][i] == board[2][i])
				&& (!isspace(board[0][i]))
				&& (!isspace(board[1][i]))
				&& (!isspace(board[2][i])) )
			{
				goto won_now ;
			}
		} // for

	// check diagonals
	i = j = 0 ;
	if ( (board[0][0] == board[1][1])
		&&( board[1][1] == board[2][2]) 
		&&( !isspace(board[0][0]))
		&&(!isspace(board[1][1]))
		&&(!isspace(board[2][2])) )
		goto won_now ;
	reverse_diag:

	if ( (board[2][0] == board[1][1] )
		&&(board[1][1] == board[0][2] )
		&&(!isspace(board[2][0]))
		&&(!isspace(board[1][1]))
		&&(!isspace(board[0][2])) )
		goto won_now ;

	bottom: 
	return false ;
	won_now: 
	cout << "Game WON! \n" ;
	return true ;
} // check_won()
