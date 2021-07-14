/* These are your declarations.
 * Do not edit this file at all.
 * If you change it and your program does not run as a result, you will receive a grade of %0.
 */

#include <iostream>

#ifndef MAZE
#define MAZE

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;


/*
The your (the student author’s) Campus Username
*/
void get_identity(string &my_id);


/**
Creates a dynamically allocated array of std::string elements.
Returns a pointer to that array.
**/
string * build_matrix(int rows);


/**
Fills the matrix with one line per string in the array.
Use the std::string getline method.
Why don't you need to send in cols?
Discard any extra newlines in main, not here.
**/
void fill_matrix(string *matrix, int rows);


/**
Print the matrix as in the sample_output.txt.
Note, any newlines between mazes should be handled in main.
**/
void print_matrix(string *matrix, int rows);


/**
Delete the dynamically allocated array of strings.
Why don't you need to send in rows or cols?
Don't leave a dangling pointer (handle this in the function).
**/
void delete_matrix(string *&matrix);


/**
Finds the starting position of Niobe.
Note: row and col are passed by reference; what does this do for you?
**/
void find_start(string *matrix, int rows, int &row, int &col);


/**
This is the recursive backtracking function you need to write.
It should return true if you found the solution,
and false if there is no solution.
It should leave a trail of @ signs along the path to the solution.
Make sure to build your solution with strong emphasis on the pseudocode;
do not try to code it first, first work out the solution on paper/markerboard.
**/
bool find_exit(string *matrix, int row, int col);


/**
Returns true if row and col are the final exit location,
and false otherwise.
**/
bool at_end(string *matrix, int row, int col);


/**
Returns true if the position indexed by row and col when incremented in direction is a valid move, and false otherwise.
What is a valid move?
This function checks whether the row and col, after being incremented in 'direction', produce a valid move, not the validity of the position indexed by row and col alone.
"NORTH" is row--, "SOUTH" is row++, "EAST" is col++, and "WEST" is col--
Make sure to use the above strings, exactly.
**/
bool valid_move(string *matrix, int row, int col, string direction);

#endif
