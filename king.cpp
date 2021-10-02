#include <iostream>
#include <iomanip>

using namespace std;

void FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths, bool check);
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

    FindPaths(myArray, rows, columns, 0, 0, paths, true);

    cout << "Number of paths: " << paths << endl;;

    //Print(myArray, rows, columns);

    cout << "Program End\n";
}

void FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, unsigned long long &paths, bool check)
{
    //Goes back when currentRow is out of bounds
    if(cRow <= -1)
        return;

    //Goes back when currentRow is out of bounds
    if(cRow >= rows)
        return;

    //myArray[cRow][cColumn] = paths + 1;

    //Column gets to end, print
    if(cColumn == columns - 1)
    {
        //cout << "cRow:" << cRow << " cColumn:" << cColumn << endl;
        //Print(myArray, rows, columns);
        paths++;
        //cout << "Path Count:" << paths << endl;
        return;
    }

    //cout << "cRow:" << cRow << " cColumn:" << cColumn << endl;
    
    if(check)
    {
        FindPaths(myArray, rows, columns, 0, 1, paths, false);
        FindPaths(myArray, rows, columns, 1, 1, paths, false);
        for(int i = 1; i < rows; i++)
        {
            FindPaths(myArray, rows, columns, i, 0, paths, false);
        }
    }
    else
    {
        FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, paths, false); //Go up 1 and forward 1

        FindPaths(myArray, rows, columns, cRow, cColumn + 1, paths, false); //Go forward 1

        FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, paths, false); //Go down 1 and forward 1
    }
    
}

void Print(int **myArray, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << setw(7) << myArray[i][j];
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