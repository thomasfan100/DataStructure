/* Abstract dictionary class to inherit when implementing your BST MyMap class
 * Do not edit this file.
 * 
 * Instructions:
 * Use the TreeNode class to contain a MyPair object as its data element
 * Declare and define a MyMap class, which should include TreeNode and contain a BST of TreeNode objects
 *
 * To figure out what the functions should do, consult the following links.
 * http://en.cppreference.com/w/cpp/container/map
 * Many of the functions will be simplified single-parameter versions of the multiple std:: options
 * Where they differ, we have made a brief note.
 *
 * We give you a working pa06.cpp and its output (pa06_output.txt)
 * We also give you a similar file pa06_std.cpp with the std:: versions of the map functions
 *
 * Note: map/dictionary does NOT allow duplicates. 
 * If you insert an item already in the map, overwrite the old one.
 *
 * Files you should submit:
 * MyMap.hpp
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "MyPair.h"


template <typename K, typename V>
class Dictionary
{
    public:
        // Should only update, but not insert
        // Should throw std::out_of_range exception
        virtual V & at(const K &key) = 0;

        // Updates or inserts
        virtual V & operator[](const K &key) = 0;

        virtual bool empty() const = 0;

        virtual int size() const = 0;

        virtual void clear() = 0;

        virtual void insert(const MyPair<K, V> &init_pair) = 0;

        // The version that removes by key
        virtual void erase(const K &key) = 0;

        // Not exactly like the std:: version, but similar.
        virtual MyPair<K, V> * find(const K &key) const = 0; 

        // Not actually std:: 
        // Backwards in order traversal print, like in class code
        virtual void print() const = 0;

        virtual int count(const K &key) const = 0;
};

#endif

