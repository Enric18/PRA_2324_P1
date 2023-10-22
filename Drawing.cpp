#include <iostream>
#include <typeinfo>
#include <typeindex>
#include "Drawing.h"
using namespace std;

Drawing::Drawing(){
  shapes = new ListLinked<Shape*>;
}

Drawing::~Drawing(){
  delete[] shapes;
}

void Drawing::add_front(Shape* shape){
   shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
   shapes->append(shape);
}

void Drawing::print_all(){
   for(int i=0; i<shapes->size(); i++){
	shapes->get(i)->print();
   }
}

double Drawing::get_area_all_circles(){
   double areaT;
   for(int i=0; i<shapes->size(); i++){
	Shape *s= shapes->get(i); 
	type_index ti(typeid(*s));
	if(ti == type_index(typeid(Circle))){
           areaT += s->area();
	}
   }
   return areaT;
}
void Drawing::move_squares(double incX, double incY){
   for(int i=0; i<shapes->size(); i++){
      Shape *s= shapes->get(i);  
      type_index ti(typeid(*s));
      if(ti == type_index(typeid(Square))){
         s->translate(incX, incY);
      }
   }
}



