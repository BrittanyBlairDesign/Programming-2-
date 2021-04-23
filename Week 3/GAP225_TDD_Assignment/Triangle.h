#pragma once

#include "Vector2.h"
#include <math.h>

//this is my triangle class
class Triangle
{
private:
	Vector2 m_vector1;		// holds the first vector
	Vector2 m_vector2;		// holds the second vector
	Vector2 m_vector3;		// holds the third vector
	float m_a = 0;
	float m_b = 0;
	float m_c = 0;
	float m_perimeter = 0;
public:
	// Triangle constructor that takes in 3 vector objects
	Triangle(Vector2 vector1, Vector2 vector2, Vector2 vector3): m_vector1(vector1), m_vector2(vector2), m_vector3(vector3){}
	float GetSideLength(int side)			// returns Distance between two points
	{
		float x1 = 0, x2 = 0 , y1 = 0 , y2 = 0;
		float length = 0;

		switch (side)
		{
		case 0:			//between points 0 and 1
			x1 = m_vector1.GetX();
			x2 = m_vector2.GetX();
			y1 = m_vector1.GetY();
			y2 = m_vector2.GetY();
			break;
		case 1:			//between points 1 and 2
			x1 = m_vector2.GetX();
			x2 = m_vector3.GetX();
			y1 = m_vector2.GetY();
			y2 = m_vector3.GetY();
			break;
		case 2:			// between points 0 and 2
			x1 = m_vector1.GetX();
			x2 = m_vector3.GetX();
			y1 = m_vector1.GetY();
			y2 = m_vector3.GetY();
			break;
		default:
			break;
		}

		// distance = the square root of  (x2 - x1)^2 - (y1 - y2)^ 
		length = (pow((x2 - x1),2.0f)) + (pow((y2 - y1), 2.0f));

		switch (side)
		{
		case 0:
			m_a = sqrt(length);
			break;
		case 1:
			m_b = sqrt(length);
			break;
		case 2:
			m_c = sqrt(length);
			break;
		}
		
		return sqrt(length);
	}
	float GetPerimeter()					// returns the perimeter
	{
		float perimeter = m_a + m_b + m_c;
		m_perimeter = perimeter;
		return perimeter;
	}
	float GetArea()							// returns the area
	{
		float newp = m_perimeter / 2, area = 0;
		// area = the square root of  p/2*(p/2- a)*(p/2-b)*(p/2-c)
		area = newp * ((newp - m_a) * (newp - m_b) * (newp - m_c));

		return sqrt(area);
	}
};