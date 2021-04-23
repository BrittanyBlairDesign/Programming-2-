#pragma once

//This is my Vector2 class
class Vector2
{
private:
	float m_x;		// holds my x value
	float m_y;		// holds my y value
public:
	//Constructor takes and x and Y float input.
	Vector2(float X, float Y) : m_x(X), m_y(Y) {}
	float GetX()	//returns the x value
	{
		return m_x; 
	}		
	float GetY()	// returns the y value
	{
		return m_y; 
	}		
};