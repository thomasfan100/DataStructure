// Mimic the std:: version
#ifndef MY_SORT_H
#define MY_SORT_H

#include "MyHeap.h"
#include <iostream>
using namespace std;

//The array that is passed should then be sorted by the function. The array should be sorted max-first (non-ascending order).

template <typename T>
void my_sort(T array[], int size)
{
    MyHeap<int> to_sort(array,size);
    for(int x = 0; x< size; x++)
    {
        array[x] = to_sort.top();
        to_sort.pop();
    }
    return;
}
#endif
