/*
	Bunnies.cpp 
	Holds all bunnies class accessor functions and constructors.
	Brittany Blair 8/2020
*/

//Functions for bunnies called on while reproducing
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Bunnies.h"


//Lists of names
std::string g_maleNames[5]{ "Aidan", "Dante", "Ethan", "Isaac", "Simon" };
std::string g_femaleNames[5]{ "Maria","Quinn", "Sadie", "Celia", "Elsie" };

//constant var Male and female count

extern int g_males, g_females;

//List of Colors
std::string g_colors[5]{ "White", "Black", "Brown", "Spotted" };

//Overload Constructor for Creating new bunnies who are born.
Bunny::Bunny(std::string c, bool m)
{
	//setting the color to the mothers color
	c = m_color;

	//age
	m_age = 0;

	//gender
	int randGen = rand() % 2;

	if (randGen == 0) 
	{
		m_female = true;
		m_marker = 'f';
	}
	else 
	{ 
		m_female = false; m_marker = 'm'; 
	}

	//Random name
	int nameN = rand() % 5;

	if (m_female) 
	{
		m_name = g_femaleNames[nameN];
	}
	else 
	{
		m_name = g_maleNames[nameN]; 
	}

	//Mutant or not
	if (m) 
	{
		m_mutant = true;
	}
	else 
	{
		int randMutant = rand() % 100;

		if (randMutant <= 1) 
		{
			m_mutant = true;
		}
		else 
		{ 
			m_mutant = false; 
		}
	}

	//Mutant birth announcement
	if (m_mutant) 
	{
		if (m_female) 
		{
			std::cout << m_name << " the Female Radioactive Mutant Vampire Bunny Was Born!" << '\n';
		}
		else 
		{
			std::cout << m_name << " the Male Radioactive Mutant Vampire Bunny Was Born!" << '\n';
		}
	}
	else 
	{
		// Non-Mutant birth announcemet.
		if (m_female) 
		{
			std::cout << m_name << " the Female Bunny Was Born!" << '\n';
		}
		else 
		{
			std::cout << m_name << " the Male Bunny Was Born!" << '\n';
		}
	}

}

//Default constructor for spawing initial bunnies.
Bunny::Bunny()
{
	//Random age
	m_age = rand() % 9;

	//Random color
	int RandCol = rand() % 4;
	m_color = g_colors[RandCol];

	// random gender
	int randGen = rand() % 2;

	if (randGen == 0) 
	{
		m_female = true;
	}
	else
	{ 
		m_female = false; 
	}

	//Random name
	int nameN = rand() % 5;

	if (m_female) 
	{
		m_name = g_femaleNames[nameN];
		if (m_age >= 2) 
		{
			m_marker = 'F';
		}
		else
		{ 
			m_marker = 'f'; 
		}
	}
	else 
	{ 
		m_name = g_maleNames[nameN]; 
		if (m_age >= 2)
		{
			m_marker = 'M';
		}
		else 
		{
			m_marker = 'm';
		}
	}

	//Mutant or not
	int randMutant = rand() % 100;

	if (randMutant <= 1) 
	{
		m_mutant = true;
	}
	else
	{
		m_mutant = false; 
	}


	if (m_mutant) 
	{
		if (m_female) 
		{
			std::cout << m_name << " the " << m_color << ", "<< m_age << " year old, Female Radioactive Mutant Vampire Bunny is on your farm!" << '\n';
		}
		else 
		{
			std::cout << m_name << " the " << m_color << ", " << m_age << " Male Radioactive Mutant Vampire Bunny is on your farm!" << '\n';
		}
	}
	else 
	{
		if (m_female) 
		{
			std::cout << m_name << " the " << m_color << ", " << m_age << " year old, Female Bunny is on your farm!" << '\n';
		}
		else 
		{
			std::cout << m_name << " the " << m_color << ", " << m_age << " year old, Male Bunny is on your farm!" << '\n';
		}
	}
}

// Function for Aging up the bunnies
int Bunny::ageUP()
{
	//add one to the age
	++m_age;

	//if they are age 2 or older they get the capital letter marker. and added to respective adult counts.
	if (m_age >= 2) {
		if (m_female && !m_mutant) 
		{
			m_marker = 'F';
			++g_females;
		}
		else if (!m_female && !m_mutant) 
		{
			m_marker = 'M';
			++g_males;
		}
		else
		{
			m_marker = 'X';
		}
	}
	return m_age;
}

//Function for Mutating bunnies
void Bunny::Mutation()
{
	m_mutant = true;
}

//Function to return a Bunnies Gender
bool Bunny::getGender() 
{
	if (m_female) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Function to Return a Bunnies Mutant Status
bool Bunny::getMutant()
{
	if (m_mutant)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function to Return a Bunny name
string Bunny::getname() const
{
	return m_name;
}

//Function to return the Bunny Color
string Bunny::getcolor() const
{
	return m_color;
}

// Function to return the bunny age
int Bunny::getAge() const
{
	return m_age;
}

//Function to retun the bunny X postion
int Bunny::getX() const 
{
	return m_x;
}

// function to return the bunny Y postion
int Bunny::getY() const 
{
	return m_y;
}

//Function to Set the new x and y Postion of the bunny
void Bunny:: setPosition(int xPos, int yPos)
{
	m_x = xPos;
	m_y = yPos;
}