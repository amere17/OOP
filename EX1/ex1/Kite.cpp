#include "Kite.h"

Kite::Kite(const IsoscelesTriangle& triangle0, const IsoscelesTriangle& triangle1)
	: m_triangle{ {{ 30,20},{ 25,25},{ 20,20 }}, {{ 30,20},{ 25,15 },{ 20,20 }} }
{
	set(triangle0, triangle1);
}

Kite::Kite(const IsoscelesTriangle triangle[2])
	: Kite{triangle[0], triangle[1]}
{
}

Kite::Kite(const Vertex & top, double width, double topHeight, double bottomHeight)
	: m_triangle{ {{ 30,20},{ 25,25},{ 20,20 }}, {{ 30,20},{ 25,15 },{ 20,20 }} }
{
	IsoscelesTriangle triangle0{ top,width,topHeight },
		triangle1{ Vertex{top.m_x,top.m_y-(topHeight+bottomHeight)},width,bottomHeight };
	set(triangle0,triangle1);
}

double Kite::getTotalHeight() const
{
	return (m_triangle[0].getVertex(1).m_y - m_triangle[1].getVertex(1).m_y);
}

void Kite::draw(Board & board) const
{
	m_triangle[0].draw(board);
	m_triangle[1].draw(board);
}

Rectangle Kite::getBoundingRectangle() const
{
	return Rectangle{ m_triangle[1].getBoundingRectangle().getBottomLeft(),
		m_triangle[0].getBoundingRectangle().getTopRight() };
}

double Kite::getArea() const
{
	return m_triangle[1].getArea() + m_triangle[0].getArea();
}

double Kite::getPerimeter() const
{
	return m_triangle[1].getPerimeter() + m_triangle[0].getPerimeter()- 2*m_triangle[0].getLength();
}

Vertex Kite::getCenter() const
{
	double center_x, center_y;
	center_x = (m_triangle[0].getLength() + m_triangle[0].getVertex(0).m_x) / 2;
	center_y = m_triangle[0].getVertex(0).m_y;
	return Vertex{ center_x, center_y };
}

bool Kite::scale(double factor)
{
	Vertex triangle1[3], triangle[3];
	triangle1[0] = { (m_triangle[0].getVertex(0).m_x - getCenter().m_x) * factor + getCenter().m_x ,
		(m_triangle[0].getVertex(0).m_y - getCenter().m_y) * factor + getCenter().m_y };
	triangle1[1] = { (m_triangle[0].getVertex(1).m_x - getCenter().m_x) * factor + getCenter().m_x ,
		m_triangle[0].getVertex(1).m_y };
	triangle1[2] = { (m_triangle[0].getVertex(2).m_x - getCenter().m_x) * factor + getCenter().m_x ,
	(m_triangle[0].getVertex(2).m_y - getCenter().m_y) * factor + getCenter().m_y };

	triangle[0] = { (m_triangle[1].getVertex(0).m_x - getCenter().m_x) * factor + getCenter().m_x ,
		(m_triangle[1].getVertex(0).m_y - getCenter().m_y) * factor + getCenter().m_y };
	triangle[1] = { (m_triangle[1].getVertex(1).m_x - getCenter().m_x) * factor + getCenter().m_x ,
		m_triangle[1].getVertex(1).m_y };
	triangle[2] = { (m_triangle[1].getVertex(2).m_x - getCenter().m_x) * factor + getCenter().m_x ,
	(m_triangle[1].getVertex(2).m_y - getCenter().m_y) * factor + getCenter().m_y };

	return set(IsoscelesTriangle{ triangle1 }, IsoscelesTriangle{ triangle });
}
bool Kite::set(const IsoscelesTriangle& triangle0, const IsoscelesTriangle& triangle1)
{
	if (sameX(triangle0.getVertex(1), triangle1.getVertex(1)) &&
		triangle0.getVertex(0).isEqual(triangle1.getVertex(0)) &&
		triangle0.getVertex(2).isEqual(triangle1.getVertex(2)))
	{
		m_triangle[0] = triangle0;
		m_triangle[1] = triangle1;
		return true;
	}
	return false;
}