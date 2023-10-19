#include "Rectangle.h"
#include <iostream>
#include <cmath>
using namespace std;

bool Rectangle::check(Point2D* vertices){
   double d01 = Point2D::distance(vertices[0], vertices[1]);
   double d23 = Point2D::distance(vertices[2], vertices[3]);
   double d12 = Point2D::distance(vertices[1], vertices[2]);
   double d30 = Point2D::distance(vertices[3], vertices[0]);

   if(d01 == d23 && d12 == d30){
	   return true;
   }
   else{
	   return false;
   }
}

Rectangle::Rectangle(){
   vs[0].x = -1;
   vs[0].y = 0.5;
   vs[1].x = 1;
   vs[1].y = 0.5;
   vs[2].x = 1;
   vs[2].y = -0.5;
   vs[3].x = -1;
   vs[3].y = -0.5;
}

Rectangle::Rectangle(string color, Point2D* vertices){
   bool rect = check(vertices);
   if(rect == true){
      this->color = color;
      vs = vertices;
   }
   else{
      throw invalid_argument("No se forma un rectángulo");
   }   
}

Rectangle::Rectangle(const Rectangle &r){
   
}

Rectangle::~Rectangle(){
   delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
   if(ind< N_VERTICES){
      return vs[ind];
   }
   else{   
      throw out_of_range("El índice no es válido");
   }
}

Point2D Rectangle::operator[](int ind) const{
   if(ind< N_VERTICES){
      return vs[ind];
   }
   else{   
      throw out_of_range("El índice no es válido");
   }

}

//void Rectangle::set_vertices(Point2D* vertices);
Rectangle& operator= (const Rectangle &r){
   return r;
}

ostream& operator<<(ostream &out, const Rectangle &r){
   out << "Rectangle: " << "\nColor: " << r.get_color() << "\nVertices: [";
   for(int i=0; i<4; i++){
        out << "( " << r.get_vertex(i).x << ", " <<  r.get_vertex(i).y << "), ";
   }
   return out;
}


double Rectangle::area() const{
   double d01 = Point2D::distance(vs[0], vs[1]);
   double d12 = Point2D::distance(vs[1], vs[2]);

   return (d01*d12);
}

double Rectangle::perimeter() const{
   double d01 = Point2D::distance(vs[0], vs[1]);
   double d12 = Point2D::distance(vs[1], vs[2]);

   return (d01*2)+(d12*2);

}

void Rectangle::translate(double incX, double incY){
   for(int i= 0; i< 4; i++){
	vs[i].x += incX;
	vs[i].y += incY;
   }
}

void Rectangle::print(){
   cout << "Rectangle: " << "\nColor: " << get_color() << "\nVertices: [";
   for(int i=0; i<4; i++){
	cout << "( " << vs[i].x << ", " <<  vs[i].y << "), ";
   }
}

