//Tic Tac Toe

#include <iostream>
#include <stdlib.h>
using namespace std;


char board[3][3]{ {'1','2','3'}, { '4','5','6' }, { '7','8','9' } };

int Move;
int row, column;
char turn = 'X';
bool draw = false;

std::string Mode;

void setup()
{
	cout << " Tic Tac Toe!\n";
	cout << "1 - single player\n";
	cout << "2 - two player\n";

	cin >> Move;

	if (Move == 1)
	{
		Mode = "Single Player";

		cout << "Here are the rules!\n";
		cout << "on the game board there will be a series of numbers.\n";
		cout << "When its your turn, enter the number where you would like to place your X.\n";
		cout << "the first player to get 3 of their marks in a row wins!\n";
	}
	if (Move == 2) {

		Mode = "Multi Player";

		cout << "Here are the rules!\n";
		cout << "on the game board there will be a series of numbers.\n";
		cout << "When its your turn, enter the number where you would like to place your X.\n";
		cout << "the first player to get 3 of their marks in a row wins!\n";
	}


}

void GameBoard()
{
	//Rander Game Board LAYOUT

	cout << "TIC TAC Toe \n";
	cout << "     |     |     \n";
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
	cout << "     |     |     \n";
}

void PlayerTurn()
{
	if (turn == 'X') {
		cout << "Player - 1 [X] turn :\n";
	}
	else if (turn == 'O') {
		cout << "Player - 2 [O] turn :\n";
	}

	cin >> Move;

	switch (Move) {
	case 1:
		row = 0; column = 0; break;
	case 2:
		row = 0; column = 1; break;
	case 3:
		row = 0; column = 2; break;
	case 4:
		row = 1; column = 0; break;
	case 5:
		row = 1; column = 1; break;
	case 6:
		row = 1; column = 2; break;
	case 7:
		row = 2; column = 0; break;
	case 8:
		row = 2; column = 1; break;
	case 9:
		row = 2; column = 2; break;
	default:
		cout << "Sorry, thats not an option. Can you make another selection?\n";
	}

	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = turn;
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = turn;
		turn = 'X';
	}
	else {
		cout << "This box is already filled in Pick another one.\n\n";
		PlayerTurn();
	}
	GameBoard();

}

void Logic()
{
	if (turn = 'O') {
		cout << "Computer [O] turn \n";
	}

	Move = rand() % 9 + 1;

	switch (Move) {
	case 1:
		row = 0; column = 0; break;
	case 2:
		row = 0; column = 1; break;
	case 3:
		row = 0; column = 2; break;
	case 4:
		row = 1; column = 0; break;
	case 5:
		row = 1; column = 1; break;
	case 6:
		row = 1; column = 2; break;
	case 7:
		row = 2; column = 0; break;
	case 8:
		row = 2; column = 1; break;
	case 9:
		row = 2; column = 2; break;
	default:
		cout << "Sorry, thats not an option. Can you make another selection?\n";
	}

	if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = turn;
		turn = 'X';
	}
	else {
		Logic();
	}
	GameBoard();
}

bool GameOver() {

	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return false;
		else if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;
	}

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return false;
	else if (board[0][2] == board[1][1] && board[2][0] == board[0][2])
		return false;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;

	draw = true;
	return false;
}

int main()
{

	setup();
	GameBoard();

	while (GameOver())
	{

		PlayerTurn();
		GameOver();
		if (Mode == "Single Player") {
			Logic();
		}
		GameOver();
	}

	if (turn == 'X' && draw == false) {
		cout << "Congratulations! Player 1 [X] Has won!!\n";
	}
	else if (turn == 'O' && draw == false) {
		if (Mode == "Single Player") {
			cout << "Better luck next time, Computer Wins!!\n";
		}
		else {
			cout << "Condratulations! Player 2 [O] has Won!!\n";
		}
	}
	else {
		cout << "GAME DRAW!";
	}

	return 0;
}