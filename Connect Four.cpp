/*
Name: Connect Four.cpp
Purpose: Connect Four game using 2D arrays and user defined functions

Author: Lin.I

Created: 20/12/2020
"""
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int BOARD_WIDTH = 7, BOARD_HEIGHT = 6;
const int EMPTY = 0, P1 = 1, P2 = 2;
const int MAX_ROUNDS = 21;

void add_coin(istream & in, int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{	
	bool coin_not_added = true;
	int player_location = 0;

	while (coin_not_added)
	{			
		if  (in == cin)
		{
			if (player == P1)
			{
				cout << "Player 1, Enter a location: ";			
			}
			if (player == P2)
			{
				cout << "Player 2, Enter a location: ";
			}
		}
		
		in >> player_location;
			
		if (player_location >= 1 && player_location <= 7)
		{
			for (int row = 0; row < BOARD_HEIGHT; row ++)
			{
				if (board[row][player_location-1] == EMPTY && coin_not_added)
				{
					board[row][player_location-1] = player;
					coin_not_added = false;
				}
			}
		}
	}
}
		
bool check_horizontal(int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{
	for (int row = 0; row < BOARD_HEIGHT; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == player &&
				board[row][col+1] == player &&
				board[row][col+2] == player &&
				board[row][col+3] == player)
				return true;
		}
	}
	return false;
}

bool check_vertical(int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < BOARD_WIDTH; col++)
		{
			if (board[row][col] == player &&
				board[row+1][col] == player &&
				board[row+2][col] == player &&
				board[row+3][col] == player)
				return true;
		}
	}
	return false;
}

bool check_upward_diagonal(int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == player &&
				board[row+1][col+1] == player &&
				board[row+2][col+2] == player &&
				board[row+3][col+3] == player)
				return true;
		}
	}
	return false;
}

bool check_downward_diagonal(int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{
	for (int row = 3; row < 6; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == player &&
				board[row-1][col+1] == player &&
				board[row-2][col+2] == player &&
				board[row-3][col+3] == player)
				return true;
		}
	}
	return false;
}

bool check_win(int board[BOARD_HEIGHT][BOARD_WIDTH], int player)
{
	return check_horizontal(board, player) ||
		   check_vertical(board, player) ||
		   check_upward_diagonal(board, player) ||
		   check_downward_diagonal(board, player);
}

void output_board(ostream & out, int board[BOARD_HEIGHT][BOARD_WIDTH])
{
	for (int row = 1; row <= BOARD_HEIGHT; row++)
	{
		for (int col = 0; col < BOARD_WIDTH; col++)
		{
			out << board[BOARD_HEIGHT-row][col] << " ";
		}
	out << endl;
	}
}


int main()
{
	int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
	
	output_board(cout, board);
	cout << endl;
	
	bool game_over = false;
	int round = 0;
	
	while (!game_over)
	{
		add_coin(cin, board, P1);
		output_board(cout, board);

		if (check_win(board, P1))
		{
			game_over = true;
			cout << "Player 1 Wins!";
		}
		
		cout << endl;
		
		if (!game_over)
		{
			add_coin(cin, board, P2);
			output_board(cout, board);
			
			if (check_win(board, P2))
			{
				game_over = true;
				cout << "Player 2 Wins!";
			}
		
			cout << endl;
		}
		
		round++;

		if (round == MAX_ROUNDS)
		{
			game_over = true;
			cout << "Tie Game!";
		}

	}

	return EXIT_SUCCESS;
}

