/* An abstract class which will serve as an interface to the two bag implementations.
 * You must include the functions insert(), remove(), and size() here as pure virtual functions.
 * Write the preprocessor header guards (ifndef, etc) around the content of this file (use others as guidance).
 * The name of the templated abstract class should be Bag
 * Include a public variable like this -- std::string parent_variable = "this is from the abstract class";
 * It must be templated on T
 * This is the ONE h file you CAN edit.
 */
#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string>
#include "my_exception.h"
using std::string;

/*
Writes to a std::string passed by reference, containing:
    * the your (the student author's) Campus Username
Put the definition for this in bag_simple.hpp
*/
void get_identity(string &my_id);


// implement your abstract class here:
template <typename T>
class Bag
{
    public:
        std::string parent_variable = "this is from the abstract class";
        virtual bool insert(const T &myItem) = 0;
        virtual bool remove(const T &myItem) = 0;
        virtual int size() const = 0;

};
#endif
