#include "Rectangle.h"

// Constructors
// Rectangle constructor that gets 2 coordinates 
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	// Default
	: m_bottomLeft{20, 10}, m_topRight{30, 20}
{
	set(bottomLeft, topRight);
}

// Rectangle constructor that gets an array of vertices
Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
}

// Rectangle constructor that gets 4 points
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: Rectangle(Vertex{ x0, y0 }, Vertex{ x1, y1 })
{
}

// Rectangle constructor that get bottom left coordinates, width and height
Rectangle::Rectangle(const Vertex& start, double width, double height)
	: Rectangle(20,10,30,20)
{
	Vertex bottomLeft, topRight;
	if (width > 0) {
		// positive width
		if (height > 0) {
			// Valid width and height
			// positive height
			bottomLeft = { start.m_x + width, start.m_y };
			topRight = { start.m_x, start.m_y + height };
		}
		else {
			// negative height
			bottomLeft = { start.m_x + width, start.m_y + height };
			topRight = start;
		}
	}
	else {
		// negative width
		if (height > 0) {
			bottomLeft = start;
			topRight = { start.m_x + width, start.m_y + height };
		}
		else {
			// negative height
			bottomLeft = { start.m_x, start.m_y + height };
			topRight = { start.m_x + width, start.m_y };
		}
	}
	set(bottomLeft, topRight);
}

// Functions:
// Returns bottom left coordinates 
Vertex Rectangle::getBottomLeft() const {
	return m_bottomLeft;
}

// Returns top right coordinates 
Vertex Rectangle::getTopRight() const {
	return m_topRight;
}

// calculates rectangle's width
double Rectangle::getWidth() const {
	return (m_topRight.m_x- m_bottomLeft.m_x);
}

// calculates rectangle's height
double Rectangle::getHeight() const {
	return (m_topRight.m_y - m_bottomLeft.m_y);
}

// Methods
// draw rectangle in board 
void Rectangle::draw(Board& board) const {
	Vertex topLeft, bottomRight;
	topLeft = { m_bottomLeft.m_x, m_topRight.m_y };
	bottomRight = { m_topRight.m_x, m_bottomLeft.m_y };
	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(bottomRight, m_topRight);
	board.drawLine(m_topRight, topLeft);
	board.drawLine(topLeft, m_bottomLeft);
}

// returns bounding
Rectangle Rectangle::getBoundingRectangle() const {
	// same rectangle
	return *this;
}

// returns area
double Rectangle::getArea() const {
	return (getWidth()*getHeight());
}

// returns perimeter
double Rectangle::getPerimeter() const {
	return (2 * (getWidth()+getHeight()));
}

// returns center 
Vertex Rectangle::getCenter() const{
	return { (m_bottomLeft.m_x + m_topRight.m_x) / 2,
		(m_bottomLeft.m_y + m_topRight.m_y) / 2 };
}

// scale according to factor 
bool Rectangle::scale(double factor) {
	Vertex bottomLeft, topRight;
	bottomLeft = { (m_bottomLeft.m_x - getCenter().m_x) * factor + getCenter().m_x,
		(m_bottomLeft.m_y -getCenter().m_y) * factor + getCenter().m_y };
	topRight = { (m_topRight.m_x - getCenter().m_x) * factor + getCenter().m_x,
		(m_topRight.m_y - getCenter().m_y) * factor + getCenter().m_y };
	return set(bottomLeft, topRight);
}

// check & set valid coordinates
bool Rectangle::set(const Vertex& bottomLeft, const Vertex& topRight){
	if (bottomLeft.isValid() && topRight.isValid() && 
		topRight.isHigherThan(bottomLeft) && topRight.isRighterThan(bottomLeft)) {
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;
		return true;
	}
	return false;
}