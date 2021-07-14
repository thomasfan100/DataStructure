/**
main file for searching matrix
**/

#include "matrix_search.h"

int main()
{
	int rows = 0, cols = 0, data = 0;
	string word;
	int solution[4];

	cin >> data;
	for (int x = 0; x < data; x++)
	{
		char** matrix;
		cin >> rows >> cols;
		matrix = build_matrix(rows, cols);
		fill_matrix(rows, cols, matrix);
		cin >> word;
		matrix_search(solution, word, rows, cols, matrix);
		delete_matrix(rows, matrix);
		if (solution[0] == -1 && solution[1] == -1 && solution[2] == -1 && solution[3] == -1)
			cout << "The pattern was not found." << endl;
		else
			cout << "Searching for \"" << word << "\" in matrix " << x << " yields:\n"
			<< "Start Pos:(" << solution[0] << "," << solution[1] << ") to End Pos:(" << solution[2] << "," << solution[3] << ")" << endl;
	}
	return 0;
}

