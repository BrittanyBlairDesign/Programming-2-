/*
	GAP 225 : 10-1
	Brittany Blair
*/

#include<iostream>
#include <assert.h>
#include <type_traits>

// 1) Write a global variable template with this signature: unsigned int g_printCount<T> = 0;

template<typename CountType>
CountType g_printCount;

// 2) Write a new version of the Print<T> function template that you wrote for assignment 9.1: void Print<T>(const T& message);

template<typename Type>
void Print(const Type& message)
{
	// 4) Modify Print<T> using static_assert and type_traits; make it throw a compiler error if you try to print an unsigned integral value.
	static_assert(std::is_unsigned<message>(), " Type was an unsigned Integral Type.");

	++g_printCount;
	std::cout << message << std::endl;
}

// 3) Specialize g_printCount<bool> to begin at 100 instead of 0.

template<>
bool g_printCount<bool> = 100;

/*
	5) Write a class template with the following definition:

		template<typename T, int N>
		class Vector
		{
		private:
		    // a
		public:
		    // b
		    // c
		};			
*/

template<typename Type, int Number>
class Vector
{
private:
	// a) Declare an array of values.Type : T.Size : N(e.g., Vector<int, 2> will have an int array with a size of 2).
	Type m_array[Number];

public:
	//b) Declare a constructor.It should take in a const array matching the type and size of item A.Here's an example:
	//	float values[2]{ 0, 0 };
	//	Vector<float, 2> floatVector2{ values };
	Vector(const Type insertArray[Number]): m_array(insertArray) {};

	// c) Declare a getter function capable of returning any of the elements of the array in item A(e.g., myVector.Get(0); // should return the first element).
	Type GetElement(int Index)
	{
		return m_array[Index];
	}

};

// 6) Write out the instantiation of Vector<int, 2>.In other words, write out what the Vector<T, N> template will generate when it is called this way.
//    Wrap the instantiation in a comment, since it is not technically valid C++ code.

/*
	Vector<int, 2> intVector(int[2]);
*/

// 7) Write a new class, IntVector2, which inherits from Vector<int, 2>. Add the following public functions :
//	  int GetX(), which should return this->Get(0)
//	  int GetY(), which should return this->Get(1)

class intVector2 : public Vector<int, 2>
{
public:
	intVector2(const int newArray[2]) : Vector<int, 2>(newArray) {}

	int GetX()
	{
		return this->GetElement(0);
	}

	int GetY()
	{
		return this->GetElement(1);
	}
};