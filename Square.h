#ifndef SQUARE_H
#define SQUARE_H
	
#include <stdexcept>
#include <iostream>
#include "Rectangle.h"
#include "Shape.h"
#include "Point2D.h"
using namespace std;

class Square : public Rectangle{
  private:
	static bool check(Point2D* vertices);
  
  public:
	Square();
	Square(std::string color, Point2D* vertices);
	void set_vertices(Point2D* vertices);
	friend ostream& operator<<(ostream &out, const Square &square);
	void print() override;
};

#endif
