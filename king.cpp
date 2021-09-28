#include <iostream>
#include <iomanip>

using namespace std;

void findPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths);
void print(int **myArray, int rows, int columns);
void fill(int **myArray, int rows, int columns);

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

    fill(myArray, rows, columns);
    //print(myArray, rows, columns);

    findPaths(myArray, rows, columns, 0, 0, paths);

    cout << "Number of paths: " << paths << endl;;

    cout << "Program End\n";
}

void findPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths)
{
    if(columns == cColumn)
    {
        paths++;
        print(myArray, rows, columns);
        fill(myArray, rows, columns);
        return;
    }

    myArray[cRow][cColumn] = 1;
    cout << "Row:" << cRow << " Column:" << cColumn << endl;
    findPaths(myArray, rows, columns, cRow, cColumn + 1, paths);
}

void print(int **myArray, int rows, int columns)
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

void fill(int **myArray, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            myArray[i][j] = 0;
        }
    }
}