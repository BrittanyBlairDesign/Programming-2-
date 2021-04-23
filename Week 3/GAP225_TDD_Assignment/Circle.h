#pragma once
#include <math.h>
//Circle class
class Circle
{
private:
	double m_radius = 0;						// radius value
	double m_diameter = 0;						// Diameter value
	double m_circumfrence = 0;					// Circumfrence value
	double m_area = 0;							// area value
	const double m_pi = 3.14159265358979323846;	// constant value for PI
public:	
	//Circle constructor that takes in one double value for the radius.
	Circle(double radius) : m_radius(radius) {}
	double GetRadius() { return m_radius; }		//returns the radius
	double GetPI() { return m_pi; }				// returns PI
	double GetDiameter()						// Returns the diameter
	{
		double diameter;
		diameter = m_radius * 2;				// radius times 2

		m_diameter = diameter;					
		return diameter;
	}
	double GetCircumfrence()					// returns the circumfrence
	{
		double circumfrence;
		circumfrence = 2 * (m_pi * m_radius);	// c = 2 pi r
		m_circumfrence = circumfrence;

		return circumfrence;
	}
	double GetArea()							// returns the area
	{
		double area;
		area = m_pi * (pow(m_radius, 2));		// pi r^2
		m_area = area;

		return area;
	}
};