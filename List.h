#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
   public:
      void insert(int pos, T e);
      void append(T e);
      void prepend(T e);
      T remove(int pos);
      T get(int pos);
      int search(T e);
      bool empty();
      int size();
};

#endif
