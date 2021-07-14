/* Here in the .cpp you should define and implement everything declared in the .h file.
 */

#include "maze.h"

void get_identity(string& my_id)
{
	my_id = "tgfnzb";
	return;
}

string * build_matrix(int rows)
{
    string* matrix = new string[rows];
    return matrix;
}

void fill_matrix(string *matrix, int rows)
{
    for(int x = 0; x < rows; x++)
    {
       getline(cin,matrix[x]);
    }
    return;
}

void print_matrix(string *matrix, int rows)
{
    for(int x = 0; x < rows; x++)
    {
      cout<<matrix[x]<<endl;
    }
    return;
}

void delete_matrix(string *&matrix)
{
    delete[] matrix;
    return;
}

void find_start(string *matrix, int rows, int &row, int &col)
{
    bool found = false;
    for(int x = 0 ; x< rows; x++)
    {
      for(unsigned int y =0; y < matrix[x].length();y++)
      {
        if(matrix[x][y] == 'N')
        {
           row = x;
           col = y;
           y = matrix[x].length();
           found = true;
        }
      }
      if(found)
        x = rows; //exit out of loop
    }
    return;
}

bool find_exit(string *matrix, int row, int col)
{
    bool solved = false;

    while(!solved)
    {
      if(valid_move(matrix,row,col,"NORTH"))
      {
        if(at_end(matrix,row-1,col))
            return true;
        else
        {
          matrix[row][col] = '@';
          matrix[row-1][col] = '@';
          if(find_exit(matrix,row-1,col) == false)
          {
              matrix[row][col] = ' ';
          }
          else
            return true;
        }
      }
      if(valid_move(matrix,row,col,"WEST"))
      {
        if(at_end(matrix,row,col-1))
            return true;
        else
        {
          matrix[row][col] = '@';
          matrix[row][col-1] = '@';
          if(find_exit(matrix,row,col-1) == false)
          {
              matrix[row][col] = ' ';
          }
          else
            return true;
        }
      }
      if(valid_move(matrix,row,col,"EAST"))
      {
        if(at_end(matrix,row,col+1))
            return true;
        else
        {
          matrix[row][col] = '@';
          matrix[row][col+1] = '@';
          if(find_exit(matrix,row,col+1) == false)
          {
              matrix[row][col] = ' ';
          }
          else
            return true;
        }
      }
      if(valid_move(matrix,row,col,"SOUTH"))
      {
        if(at_end(matrix,row+1,col))
            return true;
        else
        {
          matrix[row][col] = '@';
          matrix[row+1][col] = '@';
          if(find_exit(matrix,row+1,col) == false)
          {
             matrix[row][col] = ' ';
          }
          else
            return true;
        }
      }
      matrix[row][col] = ' ';
      return false;
    }
    return false;
}

bool at_end(string *matrix, int row, int col)
{
    matrix[row][col];
    if(matrix[row][col] == 'E')
        return true;

    return false;
}

bool valid_move(string *matrix, int row, int col, string direction)
{
    bool works = true;

    if(direction == "NORTH")
      row--;
    else if (direction == "SOUTH")
      row++;
    else if (direction == "EAST")
      col++;
    else if (direction == "WEST")
      col--;

    if(matrix[row][col] == '|' || matrix[row][col] == '@' || matrix[row][col] == 'N')
      works = false;

    return works;
}
