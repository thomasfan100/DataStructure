// You don't need to have a MyHeap.hpp, but you could if you want
// Declare, and/or implement your heap class here.
// If you are having a hard time figuring out how to start, look at the past assignments.
#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
using namespace std;
void get_identity(std::string &my_id);

template <typename T>
class MyHeap
{
    private:
        T *heap;          // Pointer to the heap array
        int maxsize;      // Maximum size of the heap
        int num;            // Number of elements now in the heap
    public:
        MyHeap();
        MyHeap(const T array[],const int size);
        MyHeap(const MyHeap<T> &the_heap);
        ~MyHeap();
        MyHeap<T> & operator =(MyHeap<T> &the_heap);

        //accesses the top element
        T top() const;

        //removes the top element
        T pop();

        //inserts element and sorts the underlying container
        void push(const T elem);

        void reserve();

        //checks whether the underlying container is empty
        bool empty() const;

        //returns the number of elements
        int size() const;

        //any internal functions you like (reserve, shrink_to_fit, etc.)
        //You WILL need to have internal functions to dynamically reserve more space for your array if it fills up, and if
        //it becomes less than 1/4 full, to shrink the internal array size to fit.

        void shrink_to_fit();

        void siftdown(const int pos);

        int leftchild(const int pos) const;

        int rightchild(const int pos) const;

        int parent(const int pos) const;


};

#include "MyHeap.hpp"
#endif
