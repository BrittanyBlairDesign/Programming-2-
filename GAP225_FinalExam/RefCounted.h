#pragma once

// RefrenceCountedData is a Template class, that wraps a value and counts the number of pointers accessing the data.
template<typename Data>
class RefrenceCountedData
{
private:
	Data m_data;
	unsigned int m_refrenceCount;

public:
	// Default constructor takes in a Type and assigns it to m_data. and sets the refrence count to 0 on initialization.
	RefrenceCountedData(Data data)
		: m_data(value)
		, m_refrenceCount(0)
	{}

	// Increments the refrence count and returns a pointer to the data.
	Data* GetPointer()
	{
		++m_refrenceCount;
		Data* pNewptr = &m_data;
		return pNewptr;
	}

	// Decrements the refrence count.
	void ReleasePointer()
	{
		--m_refrenceCount;
	}

	// Returns the current refrence count.
	unsigned int GetRefrenceCount()
	{
		return m_refrenceCount;
	}
};
