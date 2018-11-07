#pragma once
#include "Board.h"
#include "Rectangle.h"
#include "IsoscelesTriangle.h"
class Kite
{
public:
	// Kite build:
	Kite(const IsoscelesTriangle& triangle0, const IsoscelesTriangle& triangle1);
	Kite(const IsoscelesTriangle triangle[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight() const;

	// methods:
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	IsoscelesTriangle m_triangle[2];
	bool set(const IsoscelesTriangle& triangle0, const IsoscelesTriangle& triangle1);


};