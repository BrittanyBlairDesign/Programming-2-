// Gullible User - Brittany blair 8/2020

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {

	int itteration = 0;
	int Guess;
	std::string input;

	
	while (true) 
	{
		if (itteration < 10)
		{
			std::cout << "Pick a number other than " << itteration << '\n'; // announce question

			getline(std::cin, input); // user enters number
			std::stringstream temp(input);

			temp >> Guess;
			std::cout << "You choose " << Guess << '\n';

			//if the guess is spot on 
			if (Guess == itteration) {
				std::cout << "Hey! You weren't supposed to do that!" << '\n';
				break;
			}
			else if (itteration < 10)// if the guess isnt spot on, but is also less than 10 still
			{
				std::cout << "Okay, lets go again. " << '\n';
				
			}
			itteration++; // add to itteration
			continue;
		}
		else
		{
			std::cout << "Wow, you're far more patient than i am. Okay fine, you win. " << '\n';
			break;
		}

	}
	return 0;
}