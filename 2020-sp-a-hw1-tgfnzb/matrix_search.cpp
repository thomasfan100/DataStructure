/**
function definition file for matrix search
**/

#include "matrix_search.h"

void get_identity(string& my_id)
{
	my_id = "tgfnzb";
	return;
}

char** build_matrix(int rows, int cols)
{
	char** matrix = new char* [rows];
	for (int x = 0; x < rows; x++)
	{
		matrix[x] = new char[cols];
	}
	return matrix;
}

void fill_matrix(int rows, int cols, char** matrix)
{
	char data;
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			cin >> data;
			matrix[x][y] = data;
		}
	}
	return;
}


void print_matrix(int rows, int cols, char** matrix)
{
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
	return;
}


void delete_matrix(int rows, char** matrix)
{
	for (int x = 0; x < rows; x++)
	{
		delete[]matrix[x];
	}
	delete[]matrix;
	matrix = nullptr;
	return;
}


void matrix_search(int sol[], string word, int rows, int cols, char** matrix)
{
	//u(up) , d(down), l(left), r(right), dl(down left), dr(down right)
	//ul(up left), ur(up right)
	bool u = false, d = false, l = false, r = false, dl = false,
		dr = false, ul = false, ur = false;
	bool solution_found = false;
	int wordlen = word.length();

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (matrix[x][y] == word[0])
			{
				//find possible directions
				if (x - (wordlen - 1) >= 0)
					u = true;
				if (x + (wordlen - 1) < rows)
					d = true;
				if (y - (wordlen - 1) >= 0)
					l = true;
				if (y + (wordlen - 1) < cols)
					r = true;
				if (u == true && l == true)
					ul = true;
				if (u == true && r == true)
					ur = true;
				if (d == true && l == true)
					dl = true;
				if (d == true && r == true)
					dr = true;
				if (u == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x - z][y] != word[z])
						{
							z = word.length();
							u = false;
						}
						else if (z == wordlen - 1 && matrix[x - z][y] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x - (wordlen - 1);
							sol[3] = y;
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (ul == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x - z][y - z] != word[z])
						{
							z = wordlen;
							ul = false;
						}
						else if (z == wordlen - 1 && matrix[x - z][y - z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x - (wordlen - 1);
							sol[3] = y - (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (ur == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x - z][y + z] != word[z])
						{
							z = wordlen;
							ur = false;
						}
						else if (z == wordlen - 1 && matrix[x - z][y + z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x - (wordlen - 1);
							sol[3] = y + (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (l == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x][y - z] != word[z])
						{
							z = wordlen;
							l = false;
						}
						else if (z == wordlen - 1 && matrix[x][y - z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x;
							sol[3] = y - (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (r == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x][y + z] != word[z])
						{
							z = wordlen;
							r = false;
						}
						else if (z == wordlen - 1 && matrix[x][y + z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x;
							sol[3] = y + (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (d == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x + z][y] != word[z])
						{
							z = wordlen;
							d = false;
						}
						else if (z == wordlen - 1 && matrix[x + z][y] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x + (wordlen - 1);
							sol[3] = y;
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (dl == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x + z][y - z] != word[z])
						{
							z = wordlen;
							dl = false;
						}
						else if (z == wordlen - 1 && matrix[x + z][y - z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x + (wordlen - 1);
							sol[3] = y - (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				if (dr == true && solution_found == false)
				{
					for (int z = 1; z < wordlen; z++)
					{
						if (matrix[x + z][y + z] != word[z])
						{
							z = wordlen;
							dr = false;
						}
						else if (z == wordlen - 1 && matrix[x + z][y + z] == word[z])
						{
							sol[0] = x;
							sol[1] = y;
							sol[2] = x + (wordlen - 1);
							sol[3] = y + (wordlen - 1);
							x = rows;
							y = cols;
							solution_found = true;
						}
					}
				}
				u = d = l = r = dl = dr = ul = ur = false;
			}
		}
	}
	if (solution_found == false)
	{
		sol[0] = sol[1] = sol[2] = sol[3] = -1;
	}
	return;
}
