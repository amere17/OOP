#pragma once
#include"Vertex.h"
#include"Rectangle.h"
#include"Board.h"
#include "Utilities.h"
#include <iostream>

class IsoscelesTriangle
{
public:
	// constructors:
	// constructor uses 3 vertices
	IsoscelesTriangle(const Vertex& ver0, const Vertex& ver1, const Vertex& ver2);
	// constructor uses vertices array
	IsoscelesTriangle(const Vertex vertices[3]);
	// constructor uses middle vertex, width and height
	IsoscelesTriangle(const Vertex& center, double width, double height);
	
	// functions:
	// returns wanted vertex
	Vertex getVertex(int index) const;
	// returns triangle's base length
	double getLength() const;
	// returns sceles length
	double getScelesLength() const;
	// returns triangle's height
	double getHeight() const;
	
	// methods:
	// draw triangle
	void draw(Board& board) const;
	// returns triangle's bounding 
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex m_vertices[3];
	bool set(const Vertex& ver0, const Vertex& ver1, const Vertex ver2);
};

