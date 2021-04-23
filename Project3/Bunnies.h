#pragma once

/*
	Bunnies.h
	Holds Bunnies class declarations of member variables, constructors, and accessor functions.
	Brittany Blair 8/2020
*/
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;

//Defining the bunnies class
/*
	the bunny Class holds all elements for each bunny spawned. it should be used to spawn bunnies
	Change a bunnies age, location or mutation status. 
*/
class Bunny {
private:
	//Member variables
	bool m_female;
	char m_marker;
	std::string m_name;
	int m_age;
	bool m_mutant;
	std::string m_color;
	int m_x;
	int m_y;

public:
	//Default Constructor
	Bunny();

	// Overload constructor
	Bunny(std::string color, bool m);

	//Accessor Functions
	int ageUP();
	void Mutation();
	bool getGender();
	bool getMutant();
	string getname() const;
	string getcolor() const;
	int getAge() const;
	int getX() const;
	int getY() const;
	void setPosition(int, int);

};
