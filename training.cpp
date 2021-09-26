#include <iostream>

using namespace std;

void MilesToDays(int[],int,int,int);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  int array [raceDistance];
  MilesToDays(array, 0, raceDistance, raceDistance);

  cout << "Program End\n";
}

void MilesToDays(int array[], int index, int miles, int milesLeft)
{
  int static numberOfDays = 0;

  if(milesLeft < 0)
    return;

  if (milesLeft == 0)
  {
    numberOfDays++;
    cout << numberOfDays;
    /*cout << "Day " << numberOfDays << ": ";
    for(int i = 0; i < index; i++)
    {
      if(i == index-1)  
        cout << array[i];
      else
        cout << array[i] << ", ";
    }
    cout << endl;*/
    return;
  }

  int prev = (index == 0)? 1 : array[index-1];

  for(int k = prev; k <= miles; k++)
  {
    array[index] = k;
    MilesToDays(array, index + 1, miles, milesLeft - k);
  }
}