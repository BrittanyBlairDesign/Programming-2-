// Pancake Glutton
// Brittany Blair 8/8/2020


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

const int Size = 10;

struct Person {
	int PersonNumber;
	int PancakesEaten;
};


bool SortByPancakesEaten(const Person &lhs, const Person &rhs) { return lhs.PancakesEaten > rhs.PancakesEaten; }
int main()
{
	std::vector<Person> People(Size);

	//Where im storing imput strings
	std::string input;

	//greet the user and introduce main topic.
	std::cout << "Good morning! I heard you ate pancakes for breakfast with some friends.\n";

	while (true)
	{
		//go through 10 cycles determing who ate how many pancakes, then assign the number to the array.
		for (std::vector<Person>::size_type i = 0; i != Size; ++i)
		{
			std::cout << "How many pancakes did person " << i + 1 << " eat this morning?" << '\n';
			getline(std::cin, input);

			std::stringstream temp(input);

			int Number;

			temp >> Number;
			People[i].PancakesEaten = Number;
			People[i].PersonNumber = i + 1;
		}

		//sort the pancake number array in order from low to high.
		std::sort(People.begin(), People.end(), SortByPancakesEaten);

		//print the list
		for (Person &n : People) {
			std::cout << "Person " << n.PersonNumber << " ate " << n.PancakesEaten << " pancakes. \n";
		}
		break;
	}
	system("PAUSE");
	return 0;
}