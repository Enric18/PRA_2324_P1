#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	Node<T>* first;
	int n;

    public:
	ListLinked(){
	  first = nullptr;
	  n = 0;
	}

	~ListLinked(){
	  Node<T>* aux = first;
	  for(int i=0; i< size(); i++){
	     Node<T>* temp = aux;
	     aux = aux->next;
	     delete[] temp;
	  }
	  first = nullptr;
	}

	T operator[](int pos){
          if(pos < 0 || pos > n){
            throw out_of_range("La posición no es válida");
          }
	  Node<T>* aux = first;
          int i=0;
          while(i<pos){
             aux = aux->next;
             i++;
          }
          return aux->data;
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            Node<T>* aux = list.first;
	    out << "List -> [";
	    for(int i=0; i<list.size(); i++){
                out << aux-> data << ", ";
                aux = aux-> next;
	    }
	    out << "]";
	    return out;
	}

	void insert(int pos, T e) override{
	  if(pos < 0 || pos > size()){
            throw out_of_range("La posición no es válida");
          }
            if(pos == 0){ //insertar pos == 0 -> primera posició
              Node<T>* ne = new Node(e);
              ne -> next = first;
              first = ne;
            }
            else { // insertar en altres posicions
	       Node<T>* aux= first->next;
	       Node<T>* prev = first;
	       int i= 1; 
               while(aux != nullptr && i<pos){
		  prev = aux;
                  aux = aux->next;
      		  i++;
               }
	       if(i=pos){
                  Node<T>* nou = new Node(e);
                  nou -> next = aux;
                  prev ->next = nou;
               }

	    }
            n++;
        }

      void append(T e) override{
        insert(n, e);
      }

      void prepend(T e) override{
      	insert(0, e);
      }

      T remove(int pos) override{
	     if(pos < 0 || pos >= size()){
           throw out_of_range("La posición no es válida");
         }
         Node<T>* aux = first;
         Node<T>* prevAux = nullptr;
      
         for(int i= 0; i < size(); i++){
	   
           if(i == pos){
             if(i == 0){
               aux = aux -> next;
               T temp = aux->data;
               delete first;
               first = aux;
	           n--;
               return temp;
             }
             else if(i == size()-1){  
               T temp = aux->data;
               delete aux;
               aux = prevAux;
               aux-> next = nullptr;
	           n--;
               return temp;
             }
             else{
                Node<T>* temp = aux;
                T temp2 = aux->data;
                aux = aux->next;
                delete temp; 
                prevAux -> next = aux;
		        n--;
                return temp2;
             }
           }
           else{
             prevAux = aux;
             aux = aux ->next;
           }
	    }
        return T(); // A esta línea no se llega nunca, pero da un warning. Retornamos un objeto de tipo T recién creado
      }

      T get(int pos) const override{
	if(pos < 0 || pos >= size()){
            throw out_of_range("La posición no es válida");
        }
	Node<T>* aux = first;
	int i=0;
	while(i<pos){
	   aux = aux->next;
	   i++;	   
	}
        return aux->data;
      }

      int search(T e) const override{
	Node<T>* aux = first;
        for(int i=0; i<size(); i++){
	   if(aux->data == e){
	      return i;
	   }
	   else{
	      aux = aux->next;
	   }
	}
	return -1;
      }

      bool empty() const override{
        return (n == 0);

      }

      int size() const override {

	      return n;
      }

};
