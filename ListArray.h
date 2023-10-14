#include <ostream>
#include "List.h"
using namespace std;

template <typename T>
class ListArray : public List<T> {

   private:
      T* arr;
      int max;
      int n;
      static const int MINSIZE = 2;
      void resize(int new_size){
        T* new_arr = new T[new_size];
	for(int i=0; i< max; i++){
	   new_arr[i] = arr[i]; 
	}
	delete [] arr;
        arr = new_arr;
	max = new_size;
      }
   public:
      ListArray(){
	 arr = new T[MINSIZE];
	 max = MINSIZE;
	 n = 0;	 
      }
      ~ListArray(){
         delete[] arr;      
      }
      T operator[](int pos){
	 if(pos >= size()){
	    throw out_of_range("Fuera de rango la posicion");
	 }
         return arr[pos];
      }
      /*
      friend std::ostream&operator<<(std::ostream &out, const ListArray<T &list){
   	 T* current = list.arr; // Supongo que arr es un puntero al primer nodo
         while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
         }
         return out;  
      }
      */

      void insert(int pos, T e) override{
         T* prev = nullptr; 
         if(pos < 0 || pos > size){
           throw out_of_range("La posición no es válida");
     	 }
         else {
           if(pos == 0){ //insertar pos == 0 -> primera posició
             T* n  = new T(e);
             n -> next = arr;
             arr = n;
           }
           else { // insertar en altres posicions
             int i = 0;
             T* aux = arr;
             while(aux != nullptr && i < pos-1){
               aux = aux -> next;
               i++;
               T* n = new T(e);
               n -> next = aux -> next;
               aux -> next = n;
             }      
           }
           size++;
         }
      }
      void append(T e) override{
	T* aux = arr;
        T* prevAux = nullptr;
        T* node = new T(e);
        int i = 0;
        while(i < size){
          if(i == size-1){
            aux->next = node;
            node->next = nullptr;
            size++;
          }
          prevAux = aux;
          aux = aux ->next;  
        }
      }	
      void prepend(T e) override{
	T* aux = arr;
	T* node = new T(e);
	node->next = aux;
	arr = node;
	size++;
      }
      T remove(int pos) override{
	 if(pos < 0 || pos > size){
            throw out_of_range("La posición no es válida");
      	 }
         T* aux = arr;
         T* prevAux = nullptr;
      
         for(int i= 0; i < size; i++){
            if(i == pos){
               if(i == 0){
                  aux = aux -> next;
                  T temp = aux->data;
                  delete arr;
                  arr = aux;
                  return temp;
	       }
               else if(i == size-1){
                  T temp = aux->data;
                  delete aux;
                  aux = prevAux;
                  aux-> next = nullptr;
                  return temp;
               }
               else{
                  T* temp = aux;
                  T temp2 = aux->data;
                  aux = aux->next;
                  delete temp; 
                  prevAux ->next = aux;
                  return temp2;
               }
            }
            else{
              prevAux= aux;
              aux = aux ->next;
            }
         }
         return -1;
      }
      T get(int pos) override{
	if(pos < 0 || pos > size){
            throw out_of_range("La posición no es válida");
         }
         T* aux = arr;
         T* prevAux = nullptr;

         for(int i= 0; i < size; i++){
            if(i == pos){
               if(i == 0){
                  T temp = aux->data;
                  return temp;
               }
               else if(i == size-1){
                  T temp = aux->data;
                  return temp;
               }
               else{
                  T temp2 = aux->data;
                  return temp2;
               }
            }
            else{
              prevAux= aux;
              aux = aux ->next;
            }
         }
         return -1;

      }
      int search(T e) override{
	T* aux = arr;
        for(int i= 0; i < size; i++){
           if(aux->data == e){
              return i;
           }
           else{
             aux = aux->next;
           }
        }
        return -1;	
      }

      bool empty() override{
        return (n == 0);
        
      }
      
      int size() override {
     
	      return n;
      }
};





