#include "Circle.h"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle(){
   center.x = 0;
   center.y = 0;
   radius = 1;
}
Circle::Circle(string color, Point2D center,double radius){
   this->color = color;
   this->center = center;
   this->radius = radius;
}
Point2D Circle::get_center() const{
   return center;
}
void Circle::set_center(Point2D p){
   center = p;
}

double Circle::get_radius() const{
   return radius;
}

void Circle::set_radius(double r){
   radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
   out << "Circle: " << " Color = " << c.get_color() << " || Centro = (" << c.get_center().x << ", " << c.get_center().y << ")" << " || Radio = "<< c.get_radius()<< "\n";
   return out;
}


double Circle::area() const{
   return 3.141592*radius*radius;
}


double Circle::perimeter() const{
   return 2*3.141592*radius;
}

void Circle::translate(double incX, double incY){
   center.x = center.x + incX;
   center.y = center.y + incY;

}

void Circle::print(){
  cout << *this;

}
 
