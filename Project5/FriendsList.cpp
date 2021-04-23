/////////////////////////
//// Friend List	/////
//// Brittany Blair /////
/////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>



void CreateFriendsLists()
{
	//Open Bill Friends
	std::fstream BillFriends;
	BillFriends.open("Bill.dat", std::ios::out);


	//Write to Bill.dat if its open
	if (BillFriends.is_open())
	{
		//Add friends names
		BillFriends << "Alice Wu"<< std::endl;
		BillFriends << "Donald Hum" << std::endl;
		BillFriends << "Joe Tanner" << std::endl;
		BillFriends << "Rosie Chan" << std::endl;
		BillFriends << "Wayne chu" << std::endl;

		//close bill.dat
		BillFriends.close();
		std::cout << "Bill Friend List Created\n";
	}
	else
	{
		std::cout << "Couldnt open file Bill.dat\n";
	}

	//Open tom friends
	std::fstream TomFriends;
	TomFriends.open("Tom.dat", std::ios::out);

	//Write to file Tom.dat if its open
	if (TomFriends.is_open())
	{
		//Add friends names
		TomFriends << "Bill Smith" << std::endl;
		TomFriends << "Jane Rose" << std::endl;
		TomFriends << "John Wallace" << std::endl;
		TomFriends << "Tom Banks" << std::endl;

		// Close tom.dat
		TomFriends.close();
		std::cout << "Tom friends list created\n";
	}
	else
	{
		std::cout << "Couldnt open file Tom.dat\n";
	}
}

void ReadBill()
{
	//Open bill and loop through.
	std::ifstream BillFriends("Bill.dat");
	// tested to see why its not opening BillFriends.open("Bill.dat");
	if (BillFriends.is_open())
	{
		while (BillFriends.eof())
		{
			std::string name;
			std::getline(BillFriends, name);

			std::cout << name << std::endl;
			std::cout << "Bill names read \n";
		}

		BillFriends.close();
	}
	else
	{
		std::cout << "Isnt opening.";
	}
}

void ReadTom()
{
	//Open tom and loop thru
	std::ifstream TomFriends("Tom.dat", std::ios::in);
	if (TomFriends.is_open())
	{
		while (TomFriends.eof())
		{
			std::string name;
			std::getline(TomFriends, name);

			std::cout << name << std::endl;
		}

		TomFriends.close();
	}
}



void CombineFriends()
{
	std::string FirstFriendList[10]{};
	int count = 0;

	//Get bill friends
	std::ifstream BillFriends("Bill.dat");
	if (BillFriends.is_open())
	{
		while (BillFriends.eof())
		{
			std::string name;
			std::getline(BillFriends, name);

			FirstFriendList[count] = name;
			++count;
		}

		BillFriends.close();
	}

	//Get Tom Friends
	std::ifstream TomFriends("Tom.dat");
	if (TomFriends.is_open())
	{
		while (TomFriends.eof())
		{
			std::string name;
			std::getline(TomFriends, name);

			FirstFriendList[count] = name;
			++count;
		}

		TomFriends.close();
	}


	//Alphabetical order
	std::sort(FirstFriendList, FirstFriendList + 9);
	std::cout << FirstFriendList[0] << std:: endl << FirstFriendList[2];

	//Write the file

	//Open Bill Friends
	std::fstream BillandTom;
	BillFriends.open("BillandTom.dat", std::ios::out);

	if (BillandTom.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			BillandTom << FirstFriendList[i] << std::endl;
			std::cout << "friends Combined :" << i << '\n';
		}

		BillandTom.close();
	}

	std::cout << "FriendsCombined\n";
}


void ReadCombined()
{
	//Open tom and loop thru
	std::ifstream BillandTom("BillandTom.dat", std::ios::in);
	BillandTom.open("BillandTom.dat");
	if (BillandTom.is_open())
	{
		while (BillandTom.eof())
		{
			std::string name;
			std::getline(BillandTom, name);

			std::cout << "friend "<<name << std::endl;
		}

		BillandTom.close();
	}
	else
	{
		std::cout << "File BillandTom.dat could not be opened.\n";
	}
}

int main()
{

	CreateFriendsLists();

	ReadCombined();

	std::cout << "Please Select an option:\n";
	std::cout << "	1) Display Bill's Friends\n";
	std::cout << "	2) Display Tom's Friends\n";
	std::cout << "	3) Combine Friends\n";
	std::cout << "	4) Display Combined Friends\n";
	std::cout << "	5) Exit\n";

	bool StillPlaying = true;
	while (StillPlaying)
	{
		ReadBill();
		ReadTom();
		int Choice;
		std::cin >> Choice;
		switch(Choice)
		{
			case 1:
				ReadBill();
				break;
			case 2:
				ReadTom();
				break;
			case 3:
				CombineFriends();
				break;
			case 4:
				ReadCombined();
				break;
			case 5:
				StillPlaying = false;
				break;
			default:
				std::cout << "Please Select an option:\n";
				std::cout << "	1) Display Bill's Friends\n";
				std::cout << "	2) Display Tom's Friends\n";
				std::cout << "	3) Combine Friends\n";
				std::cout << "	4) Display Combined Friends\n";
				std::cout << "	5) Exit\n";
				break;
		}

	}

	return 0;
}



void Menu()
{

}