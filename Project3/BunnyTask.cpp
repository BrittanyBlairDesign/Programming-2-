/*
	BunnyTask defines all Methods and functions involved in progressing the bunny farm forward.
	BrittanyBlair
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Bunnies.h"
#include "BunnyTask.h"

//Population counting maximum bunnies, adult males adult females, and mutations.
int g_count = 0, g_maxBun = 1000, g_males = 0, g_females = 0, g_MutantRabbits = 0;

//Map size and characters
int height = 80, with = 80;

//Set up the game with the first Bunnies
void BunnyFunctions::Setup(vector<Bunny>& newBunnyList)
{
	int start = 5;

	// creat the 5 starter bunnnies using default constructor.
	for (int i = 0; i < start; ++i) {
		//create new bunny
		Bunny newBunny;
		++g_count;

		//determine if the random new bunny is an adult male or female.
		int newage = newBunny.getAge();
		if (newage > 2)
		{
			if (newBunny.getGender() && !newBunny.getMutant())
			{
				++g_females;
			}
			else if (!newBunny.getGender() && !newBunny.getMutant())
			{
				++g_males;
			}
		}

		//if bunny is radioactive mutant add them to the mutant count.
		if (newBunny.getMutant())
		{
			++g_MutantRabbits;
		}
		//Add them to the vector.
		newBunnyList.push_back(newBunny);
	}
}

//Spawn new born bunnies
void BunnyFunctions::SpawnBunnies(vector<Bunny>& newBunnyList)
{

	unsigned int size = newBunnyList.size();

	if (g_males >= 1 && g_count < g_maxBun)
	{
		// if there is at least one male rabbit , reproduce with adult female rabbits.
		for (unsigned int i = 0; i < size; ++i)
		{
			if (newBunnyList[i].getGender() && !newBunnyList[i].getMutant())
			{
				if (newBunnyList[i].getAge() >= 2)
				{
					//Mothers color and non mutant status is given to the new bunny.
					bool M = newBunnyList[i].getMutant();
					string C = newBunnyList[i].getcolor();

					Bunny newBunny(C, M);

					//if bunny is radioactive mutant add them to the mutant count.
					if (newBunny.getMutant())
					{
						++g_MutantRabbits;
					}
					//add new bunny to population count.
					++g_count;
				}

			}
		}
	}
}

//For moving bunnies, Aging bunnies, and announcing thier passing.
void BunnyFunctions::BunnyAi(vector<Bunny>& newBunnyList)
{

	unsigned int size = newBunnyList.size();

	for (unsigned int i = 0; i < size;)
	{

		//increase every bunnies age.
		int newAge;
		newAge = newBunnyList[i].ageUP();

		//if a regular bunny is 10 and older, or if a mutant bunny is 50 or older they die.
		if (newAge >= 10 && !newBunnyList[i].getMutant() || newAge > 50 && newBunnyList[i].getMutant())
		{
			//announce the loss of the bunny.
			if (newBunnyList[i].getMutant())
			{
				cout << "Radioactive Mutant Vampire Bunny " << newBunnyList[i].getname() << " Has died of old age.\n";
			}
			else
			{
				cout << "Bunny " << newBunnyList[i].getname() << " Has died of old age.\n";
			}

			//remove the bunny from the counters
			if (newBunnyList[i].getGender() && !newBunnyList[i].getMutant())
			{
				--g_females;
			}
			else if (!newBunnyList[i].getGender() && !newBunnyList[i].getMutant())
			{
				--g_males;
			}
			else
			{
				--g_MutantRabbits;
			}
			--g_count;

			//Erase Bunny
			newBunnyList.erase(newBunnyList.begin() + i);
			size = newBunnyList.size();
		}
		else
		{
			++i;
		}

		//TODO::
		// this section is all about moving the bunny for the map.
		//int xPos, yPos, rN;
		//xPos = newBunnyList[i].getX();
		//yPos = newBunnyList[i].getY();
		//
		//// replace bunny char with '.' here 
		//rN = rand() % 4 + 1;
		//
		//if (rN == 1) {
		//	if (xPos + 1 <= 80) { xPos++; }
		//}
		//else if (rN == 2) {
		//	if (xPos - 1 >= 0) { xPos--; }
		//}
		//else if (rN == 3) {
		//	if (yPos + 1 <= 80) { yPos++; }
		//}
		//else if (rN == 4) {
		//	if (yPos - 1 >= 0) { yPos--; }
		//}
		//
		//Here Check to make sure that if the bunny moves it wont be ontop
		//of another bunny or off the map. if it is either of those things
		//The bunny will stay still.

	}
}

void BunnyFunctions::MutateBunnies(vector<Bunny>& newBunnyList)
{
	unsigned int size = newBunnyList.size();

	for (unsigned int i = 0; i < size; )
	{
		if (newBunnyList[i].getMutant())
		{
			int randBunny = rand() % size;

			if (!newBunnyList[randBunny].getMutant())
			{
				newBunnyList[randBunny].Mutation();
				std::cout << newBunnyList[i].getname() << " Has turned " << newBunnyList[randBunny].getname() << "Into a Mutant!\n";

				if (newBunnyList[randBunny].getGender())
				{
					--g_females;
				}
				else
				{
					--g_males;
				}

				++i;
			}
		}
		else
			++i;
	}
}
