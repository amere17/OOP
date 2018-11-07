#include "IsoscelesTriangle.h"

// constructors:
// IsoscelesTriangle constructor that gets 3 vertices	 
IsoscelesTriangle::IsoscelesTriangle(const Vertex& ver0, const Vertex& ver1, const Vertex& ver2)
	// Default
	:m_vertices{ {20,20},{25,25},{30,20} }
{
	set(ver0, ver1, ver2);
}

// IsoscelesTriangle constructor that gets an array of vertices 
IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
	:IsoscelesTriangle(vertices[0],vertices[1],vertices[2])
{
}

// IsoscelesTriangle constructor that gets center vertex, width & height 
IsoscelesTriangle::IsoscelesTriangle(const Vertex& center, double width, double height)
	: m_vertices{ {20,20},{25,25},{30,20} }
{
	Vertex vertices[3];

	vertices[0] = { center.m_x - width / 2,center.m_y + height };
	vertices[1] = center;
	vertices[2] = { center.m_x + width / 2,center.m_y + height };

	set(vertices[0], vertices[1], vertices[2]);
}

// functions:
// returns wanted vertex
Vertex IsoscelesTriangle::getVertex(int index) const {
	// check if in range
	if (index >= 0 && index <= 2) 
		return m_vertices[index];
	std::cerr << "Index out of range!\n";
	exit(1);
}

// returns base length
double IsoscelesTriangle::getLength() const {
	return distance(m_vertices[0], m_vertices[2]);
}

// returns sceles length
double IsoscelesTriangle::getScelesLength() const {
	return distance(m_vertices[0], m_vertices[1]);
}

// returns height
double IsoscelesTriangle::getHeight() const {
	Vertex baseCenter = { m_vertices[1].m_x, m_vertices[0].m_y };
	return distance(m_vertices[1], baseCenter);
}

// methods:
// draw rectangle in board
void IsoscelesTriangle::draw(Board& board) const {
	board.drawLine(m_vertices[0], m_vertices[1]);
	board.drawLine(m_vertices[1], m_vertices[2]);
	board.drawLine(m_vertices[2], m_vertices[0]);
}

// returns bounding
Rectangle IsoscelesTriangle::getBoundingRectangle() const {
	Vertex bottomLeft, topRight;
	// check if triangle is heading up
	if (m_vertices[1].isHigherThan(m_vertices[0])) {
		bottomLeft = m_vertices[0];
		topRight = { m_vertices[2].m_x,m_vertices[1].m_y };
	}
	else {
		// triangle heading down
		bottomLeft = { m_vertices[0].m_x,m_vertices[1].m_y };m_vertices[0];
		topRight = m_vertices[2];
	}
	return Rectangle(bottomLeft, topRight);
}

// returns area
double IsoscelesTriangle::getArea() const {
	return (getHeight() * getLength()) / 2;
}

// returns perimeter
double IsoscelesTriangle::getPerimeter() const {
	return (getLength() + 2 * getScelesLength());
}

// returns center
Vertex IsoscelesTriangle::getCenter() const {
	double center_x, center_y;
	center_x = center_y = 0;
	for (int i = 0; i < 3; i++) {
		center_x += m_vertices[i].m_x;
		center_y += m_vertices[i].m_y;
	}
	return Vertex{ center_x / 3, center_y / 3 };
}

// scale according to factor 
bool IsoscelesTriangle::scale(double factor) {
	Vertex vertices[3];
	vertices[0] = { (m_vertices[0].m_x - getCenter().m_x) * factor + getCenter().m_x ,
		(m_vertices[0].m_y - getCenter().m_y) * factor + getCenter().m_y };
	vertices[1] = { (m_vertices[1].m_x - getCenter().m_x) * factor + getCenter().m_x ,
		m_vertices[1].m_y };
	vertices[2] = { (m_vertices[2].m_x - getCenter().m_x) * factor + getCenter().m_x ,
		(m_vertices[2].m_y - getCenter().m_y) * factor + getCenter().m_y };
		
	return set(vertices[0],vertices[1],vertices[2] );
}

// check & set valid coordinates
bool IsoscelesTriangle::set(const Vertex & ver0, const Vertex & ver1, const Vertex ver2)
{
	Vertex baseCenter = { ver1.m_x, ver0.m_y };
	if (ver0.isValid() && ver1.isValid() && ver2.isValid() && 
		sameY(ver0,ver2) && sameX(ver1,baseCenter)
		&& !sameY(ver0, ver1)) {
		m_vertices[0] = ver0;
		m_vertices[1] = ver1;
		m_vertices[2] = ver2;
		return true;
	}
	return false;
}
