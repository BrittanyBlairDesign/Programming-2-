//Vending Machine - Brittany blair 8\2020

#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char ** argv)
{
	std::string input;
	char s;

	std::cout << "1 - Coka Cola" << '\n';
	std::cout << "2 - Sprite" << '\n';
	std::cout << "3 - Water" << '\n';
	std::cout << "4 - Fanta orange" << '\n';
	std::cout << "5 - Ginger ale " << '\n';
	std::cout << "What would you like to drink?" << '\n';

	while (true) {

		getline(std::cin, input); // get the number
		std::stringstream temp(input);

		if (input.length() == 1)
		{
			s = input[0];

			switch (s)
			{
			case '1':
				std::cout << " You Choose Coke!" << '\n';
				break;
			case '2':
				std::cout << " You Choose Sprite!" << '\n';
				break;
			case '3':
				std::cout << " You Choose Water!" << '\n';
				break;
			case '4':
				std::cout << " You Choose Fanta Orange!" << '\n';
				break;
			case '5':
				std::cout << " You Choose Ginger Ale" << '\n';
				break;
			default:
				std::cout << "Error. You did not enter in a valid option. Please make another selection:" << '\n';
				continue;
			}
			std::cout << "Please Enjoy your Drink!" << '\n';
			break;
		}
		else
		{
			std::cout << "Oops, something went wrong! Please try again : " << '\n';
			continue;
		}
	}

	system("PAUSE");
	return 0;
}