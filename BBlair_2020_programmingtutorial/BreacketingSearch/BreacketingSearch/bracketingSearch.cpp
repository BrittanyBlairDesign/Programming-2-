//Guessing Game

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

int main()
{

	// variables for the computers guess, the number of attempts, and the minimum & maximum range.
	int Guess, Attempts = 0, rangemMax = 100, rangeMin = 1, answer;

	std::string input;

	enum Guessing {
		High = 1,
		Low = 2,
		Correct = 3
	};

	//Game instructions
	std::cout << "Lets play a game!\n" << "You pick a number between 1 and 100, and I'll guess what it is.\n";
	std::cout << "After I guess a number you can respond with either \n";
	std::cout << "1 : if I guess too high\n";
	std::cout << "2 : if I guess too Low\n";
	std::cout << "3 : if I guess Correctly.\n";
	std::cout << std::endl;
	std::cout << "Do you want to play?/n";
	std::cout << " Y / N \n";
	std::getline(std::cin, input);


	if (input[0] == 'Y' || input[0] == 'y')
	{
		while (true)
		{
			Guess = rangeMin + (rand() % (rangemMax - rangeMin + 1));

			++Attempts;
			std::cout << "is this your number? - " << Guess << '\n';
			std::getline(std::cin, input);

			std::stringstream temp(input);
			temp >> answer;

			switch (answer)
			{
			case High:
				rangemMax = Guess;
				std::cout << "Too high that time huh...\n";
				continue;
			case Low:
				rangeMin = Guess;
				std::cout << "Too low this time....\n";
				continue;
			case Correct:
				std::cout << "Yay! I got it right. and it only took me " << Attempts << " attempts to get it right \n";
				break;
			default:
				std::cout << "I dont quite understand your answer. Lets try this again.\n";
				std::cout << "After I guess a number you can respond with either \n";
				std::cout << "1 : if I guess too high\n";
				std::cout << "2 : if I guess too Low\n";
				std::cout << "3 : if I guess Correctly.\n";
				continue;
			}
			break;
		}
	}
	else if (input[0] == 'N' || input[0] == 'n') {
		std::cout << "Awh no fun!\n" << "Well I guess I'll see you next time.\n";

	}
	else {
		std::cout << "I guess ill just have to take that as a no\n";
	}
	return 0;
}