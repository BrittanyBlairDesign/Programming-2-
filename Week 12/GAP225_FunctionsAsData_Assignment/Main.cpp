#include "ModdableCalculator.h"
#include "AdditionOperation.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include "Vector3.h"


////////////////////////////////////////////////
///  Task 2 : RUNLOOP
////////////////////////////////////////////////
template< typename number, typename call, typename endCall>
void RunLoop(number, call, endCall)
{
	for (auto i = 0; i < number; ++i)
	{
		if (call())
		{
			endCall();
		}
	}
};

int main()
{
	ModdableCalculator calculator;

	// Create addition functor.
	AdditionOperation addition;

	// Pass the lambda along with the description of what it is.
	calculator.AddOperation(addition, addition.GetDescription());

	// NOTE: You don't have to use functors like I did!
	// Try different methods and see which one you like.

	//TODO: Add:
	////////////////////////////////////////////////
	///  Task 1 : MODDABLE CALCULATOR
	////////////////////////////////////////////////
	// subtraction
	// Create subtraction functor.
	SubtractionOperation subtraction;

	// Pass the lambda along with the description of what it is.
	calculator.AddOperation(subtraction, subtraction.GetDescription());
	
	// multiplication
	// Create multiplication functor.
	MultiplicationOperation multiplication;

	// Pass the lambda along with the description of what it is.
	calculator.AddOperation(multiplication, multiplication.GetDescription());

	// division
	// Create multiplication functor.
	DivisionOperation division;

	// Pass the lambda along with the description of what it is.
	calculator.AddOperation(division, division.GetDescription());

	/////////////////////////////////////////////////////////////
	/// Task 3 : SORTING VECTOR3S
	/////////////////////////////////////////////////////////////

	std::vector<Vector3> Vectors;

	// Populate Vectors
	Vectors.push_back(Vector3(5, 2, 9));
	Vectors.push_back(Vector3(9, 6, 7));
	Vectors.push_back(Vector3(5, 10, 1));
	Vectors.push_back(Vector3(8, 6, 11));
	Vectors.push_back(Vector3(9, 8, 13));
	Vectors.push_back(Vector3(6, 7, 2));

	// Print out each vector and each vectors length.
	for (auto i = 0 ; i < Vectors.size(); ++i)
	{
		std::cout << Vectors[i].GetX() << ", "<< Vectors[i].GetY() << ", " << Vectors[i].GetZ() <<  " \tLength = " << Vectors[i].GetLength() << std::endl;
	}

	std::cout << std::endl << std::endl;

	// Sort a vector containing a list of vector3's.
	std::stable_sort(Vectors.begin(), Vectors.end(), [](Vector3 a, Vector3 b)
		{
			return a.GetLength() < b.GetLength();
		});

	// Print out each vector and each vectors length.
	for (auto j = 0; j < Vectors.size(); ++j)
	{
		std::cout << Vectors[j].GetX() << ", " << Vectors[j].GetY() << ", " << Vectors[j].GetZ() << " \tLength = " << Vectors[j].GetLength() << std::endl;
	
	}

	// Pause so you can compare the printed vectors.
	system("PAUSE");

	// Run the calculatior
	calculator.Run();

	return 0;
}