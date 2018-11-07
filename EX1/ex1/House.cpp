#include "House.h"
//constructor
House::House(const Rectangle & rectangle, const IsoscelesTriangle & triangle)
	: m_rectangle{ {20,10}, {20,30} }, m_triangle{ {20,20},{25,25},{30,20} }
{ 
	set(rectangle, triangle);
}

House::House(const Vertex & roofTop, double width, double roofHeight, double baseHeight)
	: m_rectangle{ {20,10}, {20,30} }, m_triangle{ {20,20},{25,25},{30,20} }
{
	IsoscelesTriangle triangle(roofTop, width, roofHeight);
	Vertex bottomLeft, topRight;
	topRight = triangle.getVertex(2);
	bottomLeft = {triangle.getVertex(0).m_x,triangle.getVertex(0).m_y - baseHeight};
	Rectangle rectangle(bottomLeft, topRight);
	House house(rectangle, triangle);
	set(rectangle, triangle);
}
//------------------ check if roof is extending -------------------------------
bool House::extendRoof(double width)
{
	if (m_triangle.getLength() <= width) {
		IsoscelesTriangle { m_triangle.getVertex(1), width, m_triangle.getHeight() };
		return true;
	}
	return false;
}
//---------------------------- get height of the house ------------------------
double House::getHeight() const
{
	return (m_triangle.getVertex(1).m_y - m_rectangle.getBottomLeft().m_y);
}

//------------ width difference between house base and roof base --------------
double House::getWidthDifference() const
{
	return (  m_triangle.getLength()-m_rectangle.getWidth());
}
//------------ draws the shape in the board -----------------------------------
void House::draw(Board & board) const 
{
	m_rectangle.draw(board);
	m_triangle.draw(board);
}
//---------- draw rectangle that's bounding the shapes ------------------------
Rectangle House::getBoundingRectangle() const
{
	Vertex bottomLeft, topRight;
	bottomLeft = { m_triangle.getVertex(0).m_x,
		m_rectangle.getBottomLeft().m_y };
	topRight = { m_triangle.getVertex(2).m_x,
		m_triangle.getVertex(1).m_y }; 
	return Rectangle{ bottomLeft,topRight };
}
//-------------------------- calc area of the shape ---------------------------
double House::getArea() const
{
	return m_rectangle.getArea() + m_triangle.getArea();
}
//-------------------------- calc perimeter of the shape ----------------------
double House::getPerimeter() const
{
	return (m_rectangle.getPerimeter() + m_triangle.getPerimeter())-2*m_rectangle.getWidth();
}
//-------------------------- find center point --------------------------------
Vertex House::getCenter() const
{
	double center_x, center_y;
	center_x = m_rectangle.getWidth() / 2;
	center_y = m_rectangle.getTopRight().m_y;
	return Vertex{ center_x, center_y };
}
//------------------------------ scale the shape with factor 2 ----------------
bool House::scale(double factor)
{   
	Vertex rectangle[2], triangle[3];
	
	rectangle[0] = { (m_rectangle.getBottomLeft().m_x - getCenter().m_x) * factor + getCenter().m_x,
		(m_rectangle.getBottomLeft().m_y - getCenter().m_y) * factor + getCenter().m_y };
	rectangle[1] = { (m_rectangle.getTopRight().m_x - getCenter().m_x) * factor + getCenter().m_x,
		(m_rectangle.getTopRight().m_y - getCenter().m_y) * factor + getCenter().m_y };
	triangle[0] = { (m_triangle.getVertex(0).m_x - getCenter().m_x) * factor + getCenter().m_x ,
	(m_triangle.getVertex(0).m_y - getCenter().m_y) * factor + getCenter().m_y };
	triangle[1] = { (m_triangle.getVertex(1).m_x - getCenter().m_x) * factor + getCenter().m_x ,
		m_triangle.getVertex(1).m_y };
	triangle[2] = { (m_triangle.getVertex(2).m_x - getCenter().m_x) * factor + getCenter().m_x ,
	(m_triangle.getVertex(2).m_y - getCenter().m_y) * factor + getCenter().m_y };

	return set(Rectangle{ rectangle }, IsoscelesTriangle{ triangle });
}
//-------------------------- check legal house to draw ------------------------
bool House::set(const Rectangle & rectangle, const IsoscelesTriangle & triangle)
{
	if (triangle.getVertex(1).isHigherThan(triangle.getVertex(0)) &&
		!triangle.getVertex(0).isRighterThan(rectangle.getBottomLeft()) &&
		!rectangle.getTopRight().isRighterThan(triangle.getVertex(2)) &&
		sameY(rectangle.getTopRight(), triangle.getVertex(2))) {
		m_rectangle = rectangle;
		m_triangle = triangle;
		return true;
	}
	return false;
}
