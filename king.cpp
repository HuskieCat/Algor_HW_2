/*
    Returns the number of possible paths that the king would be able to take to traverse
    the board from the first file to the last

    OUTPUTS
        Program Start
        Enter board size: 4 7
        Number of paths: 1220
        Program End

        Program Start
        Enter board size: 8 8
        Number of paths: 11814
        Program End

        Program Start
        Enter board size: 10 15
        Number of paths: 28781908
        Program End

        Program Start
        Enter board size: 20 20
        Number of paths: 17698806798
        Program End

    Author: Bradley Henderson
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned long long FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, 
                            bool check);
void Print(int **myArray, int rows, int columns);
void Fill(int **myArray, int rows, int columns);

int main() 
{
    cout << "Program Start\n";
 
    int rows, columns;
    cout << "Enter board size: ";
    cin >> rows >> columns;

    unsigned long long paths = 0;

    int **myArray;
    myArray = new int *[rows];
    for(int i = 0; i < rows; i++)
        myArray[i] = new int [columns];

    Fill(myArray, rows, columns);

    cout << "Number of paths: " << FindPaths(myArray, rows, columns, 0, 0, true) << endl;

    //Print(myArray, rows, columns); //This is left in to see what is in the table

    cout << "Program End\n";
}

/*
    Dynamic programming function that travels the board in search of every function,
    returns the amount to travel.
*/
unsigned long long FindPaths(int **myArray, int rows, int columns, int cRow, int cColumn, 
                            bool check)
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

    if(check) //Purpose is so it wouldn't do this portion again
    {
        //Kick starts the calculation and makes sure it goes through the rows
        for(int i = 0; i < rows; i++)
        {
            pathsFromPoint += FindPaths(myArray, rows, columns, i, 0, false);
        }
    }
    else
    {
        //Go up 1 and forward 1
        pathsFromPoint += FindPaths(myArray, rows, columns, cRow - 1, cColumn + 1, false); 
        //Go forward 1
        pathsFromPoint += FindPaths(myArray, rows, columns, cRow    , cColumn + 1, false); 
        //Go down 1 and forward 1
        pathsFromPoint += FindPaths(myArray, rows, columns, cRow + 1, cColumn + 1, false); 
    }

    myArray[cRow][cColumn] = pathsFromPoint;
    return pathsFromPoint;
}

//Used to print the array
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

//Fills the array with -1
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