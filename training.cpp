#include <iostream>

using namespace std;

void MilesToDays(int[],int,int,int, long&);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  long static numberOfDays = 0;

  int array [raceDistance];
  MilesToDays(array, 0, raceDistance, raceDistance, numberOfDays);

  cout << "Length of training schedule: " << numberOfDays << endl;

  cout << "Program End\n";
}

void MilesToDays(int array[], int index, int miles, int milesLeft, long &numberOfDays)
{
  if(milesLeft < 0)
    return;

  if (milesLeft == 0)
  {
    numberOfDays++;
    return;
  }

  int prev = (index == 0)? 1 : array[index-1];

  for(int k = prev; k <= miles; k++)
  {
    array[index] = k;
    MilesToDays(array, index + 1, miles, milesLeft - k, numberOfDays);
  }
}