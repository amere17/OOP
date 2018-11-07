#pragma once
#include"Vertex.h"
#include"Board.h"

class Rectangle
{
public:
	// constructors:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	// functions:
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;
	// methods:
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	// members:
	Vertex m_bottomLeft;
	Vertex m_topRight;
	
	// set members:
	bool set(const Vertex& bottomLeft, const Vertex& topRight);
};

