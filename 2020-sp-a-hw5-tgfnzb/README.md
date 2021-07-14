Programming assignment 5 (PA05)
==============================

# Linked list /// std::list

---

## What is this repository?
The files listed here are the starting point for your assignment.
Only add source files (not compiled files) to the Git repository.

## Note (actuall do this)!!
Thoroughly read the Canvas page **How to: Homework Submissions** for good tips, tricks, hints, and instructions on programming assignments, including how to submit via Git.

## Assignment description
Mimic the std::list behavior with your MyList.
You must use a doubly linked list.
You must use exactly one sentinel node (or a dummy node, to which the m_sentinel pointer points), which is linked to the last and first elements of the list at all times.
This sentinel node means you should NOT have special cases for a list that contains zero data elements (see the slides for list initialization).

General container library information
* https://en.cppreference.com/w/cpp/container
* http://www.cplusplus.com/reference/stl/

List
* https://en.cppreference.com/w/cpp/container/list (This wiki the most "official", but still unofficial, source of C++ knowledge for end-programmers)
* http://www.cplusplus.com/reference/list/list/ (This may also help, but if these links differ, go with en.cppreference.com instead)

Overloading operator syntax
* https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

## Input/Output
Given only indirectly this time.
Use the std::list to check.

## Grading
100% of this assignment will be graded based on the successful implementation of the functions in the header file using unit testing.
Each function's performance on its own unit test will be worth a certain subset of those points, and the output of main will as well.

## Due date
Please see the schedule on the website for all due dates.
