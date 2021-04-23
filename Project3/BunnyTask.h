#pragma once
#include "Bunnies.h"

// this struct contains all of the methods used in the program to change the bunnies inside of the bunny vector.
struct BunnyFunctions
{
	//Set up initial bunnies
	void Setup(vector<Bunny>&);
	//Param vector<Bunnies>& - bunnies on farm

	//Logic Moves, and mutates bunnies based off of the map
	void BunnyAi(vector<Bunny>&);
	//Param vector<Bunnies>& - Location of bunnies and mutation information

	//Spawn Produces new bunnies onto the map
	void SpawnBunnies(vector<Bunny>&);
	//param vector<Bunnies>& - Gets bunny location, age and gender to spawn new bunnies.

	//MutationNation, Mutates bunnies based off of the ammount of bunnies with mutations, or the location on the map.
	void MutateBunnies(vector<Bunny>&);
	//param vector<Bunnies>& - used to choose a random, non-infected bunny to turn into a mutant /
	//checks arund mutants for nearby non- mutant bunnies to turn into mutants.
};