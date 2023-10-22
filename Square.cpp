#include "Square.h"
#include <iostream>
#include <cmath>
using namespace std;

bool Square::check(Point2D* vertices){  // Comprueba si es un cuadrilatero regular pero no si es un cuadrado, podría ser un rombo
   double d01 = Point2D::distance(vertices[0], vertices[1]);
   double d23 = Point2D::distance(vertices[2], vertices[3]);
   double d12 = Point2D::distance(vertices[1], vertices[2]);
   double d30 = Point2D::distance(vertices[3], vertices[0]);

   if(d01 == d23 && d01 == d12 && d01 == d30){
	   return true;
   }
   else{
	   return false;
   }
}

Square::Square(){
   vs = new Point2D[4];
   vs[0].x = -1;
   vs[0].y = 1;

   vs[1].x = 1;
   vs[1].y = 1;

   vs[2].x = 1;
   vs[2].y = -1;
   
   vs[3].x = -1;
   vs[3].y = -1;
}

Square::Square(string color, Point2D* vertices){
   vs = new Point2D[4];
   bool rect = check(vertices);
   if(rect == true){
      this->color = color;
      for(int i=0; i<4; i++){
        vs[i]=vertices[i];
      }
   }
   else{
      throw invalid_argument("No se forma un rectángulo");
   }
}

void Square::set_vertices(Point2D* vertices){
   bool rect = check(vertices);
   if(rect == true){
      for(int i=0; i<4; i++){
        vs[i]=vertices[i];
      }
   }
   else{
      throw invalid_argument("No se forma un rectángulo");
   }
}


ostream& operator<<(ostream &out, const Square &r){
   out << "Square: " << " Color = " << r.get_color() << "  || Vertices: [";
   for(int i=0; i<4; i++){
        out << "(" << r.get_vertex(i).x << ", " <<  r.get_vertex(i).y << "), ";
   }
   out << "]" << endl;
   return out;
}

void Square::print(){
   cout << *this;
}


