#include <iostream>
#include <iomanip>

using namespace std;

unsigned long long FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, bool check);
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

    cout << "Number of paths: " << FindPaths(myArray, rows, columns, 0, 0, true) << endl;;

    //Print(myArray, rows, columns);

    cout << "Program End\n";
}

unsigned long long FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, bool check)
{
    //Goes back when currentRow is out of bounds
    if(cRow <= -1)
        return 0;

    //Goes back when currentRow is out of bounds
    if(cRow >= rows)
        return 0;

    //When at end, fill with 1
    if(cColumn == columns - 1)
    {
        myArray[cRow][cColumn] = 1;
        return 1;
    }

    //When its not -1 return
    if(myArray[cRow][cColumn] != -1)
        return myArray[cRow][cColumn];


    //This entire section is for calculating the next one
    unsigned long long pathsFromPoint = 0;

    if(check)
    {
        //Kick starts the calculation and makes sure it goes through the rows
        pathsFromPoint += FindPaths(myArray, rows, columns, 0, 1, false);
        pathsFromPoint += FindPaths(myArray, rows, columns, 1, 1, false);
        for(int i = 1; i < rows; i++)
        {
            pathsFromPoint += FindPaths(myArray, rows, columns, i, 0, false);
        }
    }
    else
    {
        pathsFromPoint += FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, false); //Go up 1 and forward 1

        pathsFromPoint += FindPaths(myArray, rows, columns, cRow    , cColumn + 1, false); //Go forward 1

        pathsFromPoint += FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, false); //Go down 1 and forward 1
    }

    myArray[cRow][cColumn] = pathsFromPoint;
    return pathsFromPoint;
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
            myArray[i][j] = -1;
        }
    }
}