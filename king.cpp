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

    cout << "Program End\n";
}

void FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths)
{
    if(columns == cColumn)
    {
        paths++;
        Print(myArray, rows, columns);
        Fill(myArray, rows, columns);
        return;
    }

    myArray[cRow][cColumn] = 1;
    cout << "Row:" << cRow << " Column:" << cColumn << endl;
    FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths);
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