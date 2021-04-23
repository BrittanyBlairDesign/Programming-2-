// Dungeon crawler

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

char Map[7][10]
{ 
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'} 
};

int EX = 6, EY = 9;
int PlayerPosition[2]{ 0,0 };
int EnemiesPosition[3][2]{ {1,0}, {2,0}, {3,0} };
int T1x, T1y, T2x, T2y, T3x, T3y;
char Player = ' ', Exit = 'X', Trap = 'T', Enemy = 'C';
bool intro = false, hitTrap = false, hitEnemy = false, Win = false;
int EnemiesPlaced = 0;


void placementT(int x, int y) {
	bool working = true;

	while (working) {
		x = rand() % 7;
		y = rand() % 10;

		switch (Map[x][y])
		{
		case 'T':
			break;
		case'X':
			break;
		case '.':
			Map[x][y] = Trap; 
			working = false; break;
		default:
			break;
		}

	}

}

void placementE() {
	bool working = true;
	int x = rand() % 7;
	int y = rand() % 10;

	while (working) {


		switch (Map[x][y])
		{
		case 'T':
			break;
		case'X':
			break;
		case '.':
			Map[x][y] = Enemy;
			working = false; break;
		default:
			break;
		}

	}

	if (EnemiesPlaced == 0) {
		EnemiesPlaced++;
		EnemiesPosition[0][0] = x;
		EnemiesPosition[0][1] = y;
	}
	else if (EnemiesPlaced == 1) {
		EnemiesPlaced++;
		EnemiesPosition[1][0] = x;
		EnemiesPosition[1][1] = y;
	}
	else if (EnemiesPlaced == 2) {
		EnemiesPlaced++;
		EnemiesPosition[2][0] = x;
		EnemiesPosition[2][1] = y;
	}


}


void Setup()
{
	if (!intro) {
		cout << "Welcome to the Dungeon Crawler\n";
		cout << "Use the WASD keys to move around the map\n";
		cout << "Avoid the Traps and enemies on the map and reach the exit to win.\n";
		cout << " \n";
		cout << "T - Trap\n" << "C - Enemy\n" << "X - Exit\n";
		cout << " \n";
		cout << "Please Choose a unique letter that represents you on the game board.\n";

		intro = true;
	}

	char input;
	cin >> input;

	switch (input)
	{
	case 'X':
		cout << "That Letter represents the Exit. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	case 'x':
		cout << "That Letter represents the Exit. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	case 'T':
		cout << "That Letter represents the Traps. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	case 't':
		cout << "That Letter represents the Traps. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	case 'C':
		cout << "That Letter represents the Enemies. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	case 'c':
		cout << "That Letter represents the Enemies. Please choose a Letter that is not being used to represent an enemy exit or trap.\n"; break;
	default:
		Player = input;
		cout << "Perfect! You will be represented on the map by - " << Player << '\n'; break;
	}

	if (Player == ' ') {
		Setup();
	}
}



bool Continuing( ) {
	


	if (hitEnemy) {
		return false;
	}
	else if (hitTrap) {
		return false;
	}
	else if (Win) {
		return false;
	}
	else { return true; }

}

void DrawMap() {

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 10; j++) {
			cout << Map[i][j] << " ";
		}
		cout << '\n';
	}
}

void PlayerTurn()
{
	cout << "Make your move! Use W A S or D to move.\n";
	char input;
	cin >> input;

	Map[PlayerPosition[0]][PlayerPosition[1]] = '.';
	int x, y;


	x = PlayerPosition[0];
	y = PlayerPosition[1];


	if (input == 'w' || input == 'W') {
		if (x - 1 < 0) {
			cout << "You hit a wall.\n";
		}
		else {
			x = x - 1;
		}
	}
	else if (input == 's' || input == 'S') {
		if (x + 1 > 6) {
			cout << "You hit a wall\n";
		}
		else { x = x + 1; }
	}
	else if (input == 'a' || input == 'A') {
		if (y - 1 < 0) {
			cout << "You Hit a Wall\n";
		}
		else { y = y - 1; }
	}
	else if (input == 'd' || input == 'D') {
		if (y + 1 > 9) {
			cout << "You hit a wall\n";
		}
		else { y = y + 1; }
	}
	else { PlayerTurn(); }

	switch (Map[x][y]) {

	case 'X':
		Win = true; break;
	case 'T':
		hitTrap = true; break;
	case 'C':
		hitEnemy = true; break;
	default:
		break;
	}

	Continuing();
	PlayerPosition[0] = x;
	PlayerPosition[1] = y;

}

void Logic() {


	int x, y;



	for (int i = 0; i < 3; i++) {

		x = EnemiesPosition[i][0];
		y = EnemiesPosition[i][1];

		Map[x][y] = '.';
		int random = rand() % 4;

		bool searching = true;
		while (searching) {

			if (random == 0) {
				if (x + 1 >= 0 && x + 1 <= 7) {
					x = x + 1;
				}
			}
			if (random == 1) {
				if (y + 1 >= 0 && y + 1 <= 7) {
					y = y + 1;
				}
			}
			if (random == 2) {
				if (y - 1 >= 0 && y - 1 <= 7) {
					y = y - 1;
				}
			}
			if (random == 3) {
				if (x + 1 >= 0 && x + 1 <= 7) {
					x = x + 1;
				}
			}

			switch (Map[x][y]) {
			case '.':
				Map[x][y] = Enemy;
				EnemiesPosition[i][0] = x;
				EnemiesPosition[i][1] = y;
				searching = false; break;
			case 'T':
				searching = false;
				Map[EnemiesPosition[i][0]][EnemiesPosition[i][1]] = Enemy;
				break;
			case 'C':
				searching = false;
				Map[EnemiesPosition[i][0]][EnemiesPosition[i][1]] = Enemy;
				break;
			case 'X':
				searching = false;
				Map[EnemiesPosition[i][0]][EnemiesPosition[i][1]] = Enemy;
				break;
			default:
				searching = false;
				Map[EnemiesPosition[i][0]][EnemiesPosition[i][1]] = Enemy;
				break;
			}
		}

		if (Map[EnemiesPosition[i][0]][EnemiesPosition[i][1]] == Player) {
			hitEnemy = true;
		}
	}

}

int main() {

	Setup();
	Map[EX][EY] = Exit;
	Map[PlayerPosition[0]][PlayerPosition[1]] = Player;

	srand(time(0));

	placementT(T1x, T1y);
	placementT(T2x, T2y);
	placementT(T3x, T3y);
	placementE();
	placementE();
	placementE();

	while (Continuing()) {
		system("CLS");
		DrawMap();
		PlayerTurn();
		Map[PlayerPosition[0]][PlayerPosition[1]] = Player;
		cout << "The Enemies are moving!\n";
		srand(time(0));
		Logic();

		Continuing();
	}

	if (hitEnemy) {
		cout << "Too bad! you hit an enemy and died.";
	}
	else if (hitTrap) {
		cout << "Oh no! You fell into a trap and died.";
	}
	else {
		cout << "Congratulations! You won the Dungeon crawler!";
	}

	system("PAUSE");
	return 0;
}

