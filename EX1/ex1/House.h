//--------------- include section ---------------
#pragma once
#include "Vertex.h"
#include "Rectangle.h"
#include "Board.h"
#include "IsoscelesTriangle.h"
#include <iostream>
class House
{
public:
	// constructors:
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);

	// functions:
	bool extendRoof(double width);
	double getHeight() const;
	double getWidthDifference() const;

	// methods:
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Rectangle m_rectangle;
	IsoscelesTriangle m_triangle;
	//------------------------ check if triangle is valid -------------------
	bool set(const Rectangle & rectangle, const IsoscelesTriangle & triangle);
};

