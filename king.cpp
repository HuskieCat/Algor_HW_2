#include <iostream>
#include <iomanip>

using namespace std;

void FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths);
void Print(int **myArray, int rows, int columns);
void Fill(int **myArray, int rows, int columns);

int main() 
{
    cout << "Program Start\n";
 
    int rows, columns;
    cout << "Enter board size: ";
    cin >> rows >> columns;

    cout << "Rows: " << rows << " Columns: " << columns << endl;

    unsigned long long paths = 0;
    int **myArray;
    myArray = new int *[rows];
    for(int i = 0; i < rows; i++)
    {
        myArray[i] = new int [columns];
    }

    Fill(myArray, rows, columns);
    //Print(myArray, rows, columns);

    FindPaths(myArray, rows, columns, 0, 0, paths);

    cout << "Number of paths: " << paths << endl;;

    Print(myArray, rows, columns);

    cout << "Program End\n";
}

void FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths)
{
    if(cRow <= -1)
        return;

    if(cColumn >= columns)
        return;

    cout << "Row:" << cRow << " Column:" << cColumn << endl;
    myArray[cRow][cColumn] = paths;

    if(cColumn == columns - 1)
    {
        cout << "End Zone" << endl;
        paths++;
        Print(myArray, rows, columns);
        //Fill(myArray, rows, columns);
        return;
    }
        
    /*if(cRow == 0)
        FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);*/

    if(cRow >= 0 && cRow < rows - 1)
    {   
        FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, paths);
        FindPaths(myArray, rows, columns, cRow    , cColumn + 1, paths);
        FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, paths);
    }

    /*for(int i = -1; i < 2; i++)
    {
        if(cRow <= -1)
            continue;
        
        if(cRow == 0)
            FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);

        if(cRow > 0 && cRow <= rows - 1)
        {
            if(i == -1)
                FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, paths);
            if(i == 0)
                FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);
            if(i == 1)
                FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, paths);

            FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, paths);
            FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);
            FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, paths);
        }
    }*/

    /*if(cRow <= rows - 1)
    {
        Print(myArray, rows, columns);
        if(cRow == rows - 1)
            FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);
        if(cRow < rows - 1)
            FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, paths);
    }*/
}

void Print(int **myArray, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << setw(4) << myArray[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Fill(int **myArray, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            myArray[i][j] = 0;
        }
    }
}