/*
	Bunny Graduation Main.cpp
	Contains the int main() and all steps for the program to run.
	Brittany Blair 8/2020
*/

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "Bunnies.h"
#include "BunnyTask.h"

using namespace std;

//Main 
int main() 
{
	//Introduction to the Bunny farm prints at the start of the game.
	cout << "Welcome to the Bunny Farm!\n";
	cout << "Your job is to oversee this farm and its resident bunnies.\n";
	cout << "But your not exactly supposed to interfear often.\n";
	cout << "If the population of bunnies is too big for your liking \n";
	cout << "Hit the K - key on your keyboard to cut the population in half.\n";
	cout << "Otherwise, sit back and observe these bunnies living peacefully on the farm.\n";
	cout << '\n';
	cout << '\n';


	//Creating Main Vector for all bunnies residing on the farm.
	vector<Bunny> myBunnyFarm;

	//Spawning the first 5 bunnies on the farm randomly.
	BunnyFunctions m_task;
	m_task.Setup(myBunnyFarm);
	cout << '\n' << "Now that you have some bunnies on this farm, Lets just jump right into it shall we?\n";

	//program waits for user then clears the text and draws the 80x80 grid map.
	system("PAUSE");
	system("CLS");
	
	// TODO :: Map(MyBunnyFarm);

	/*
		While loop will go through each loop and update the bunnies positions,
		spawns, mutations, player input, and Purging of bunny population.
	*/
	while(true)
	{
		system("PAUSE");
		m_task.SpawnBunnies(myBunnyFarm);
		m_task.BunnyAi(myBunnyFarm);
		m_task.MutateBunnies(myBunnyFarm);
	}

	return 0;
}
