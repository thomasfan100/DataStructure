/* Declare any non-required functions above main.
 * The duty of main here is to interact with the user, take in input, and manage wrapping output and runtime.
 * Remember, if you are considering putting something in main or a function, double check the specifications.
 * Each function should only do what it is specified to do, and no more.
 */

#include "maze.h"

int main()
{
    int row_start, col_start, counter = 0;
    bool maze_exit;
    int rows;

    cin>>rows;
    cin.ignore();
    while(rows != 0)
    {
        string* matrix = build_matrix(rows);
        fill_matrix(matrix,rows);
        find_start(matrix,rows,row_start,col_start);
        maze_exit = find_exit(matrix,row_start,col_start);
        matrix[row_start][col_start] = 'N';
        if(maze_exit)
            cout<<"Map "<<counter<<" -- Solution found:"<<endl;
        else
            cout<<"Map "<<counter<<" -- No solution found:"<<endl;
        print_matrix(matrix,rows);
        cout<<endl;
        delete_matrix(matrix);
        cin>>rows;
        cin.ignore();
        counter++;
    }


    return 0;
}

