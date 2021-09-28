#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void MilesToDays(int[],int,int,int, long&);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  long static numberOfDays = 0;

  int myArray [raceDistance];
  auto start = high_resolution_clock::now();
  MilesToDays(myArray, 0, raceDistance, raceDistance, numberOfDays);
  auto stop = high_resolution_clock::now();
  long duration_MS = duration_cast<milliseconds>(stop - start).count();
  long duration_S = duration_cast<seconds>(stop - start).count();

  cout << "Length of training schedule: " << numberOfDays << endl;
  cout << "Time: " << duration_MS << " ms" << endl;
  cout << "Time: " << duration_S << " s" << endl;

  cout << "Program End\n";
}

void MilesToDays(int myArray[], int index, int miles, int milesLeft, long &numberOfDays)
{
  if(milesLeft < 0)
    return;

  if (milesLeft == 0)
  {
    numberOfDays++;
    return;
  }

  int prev = (index == 0)? 1 : myArray[index-1];

  for(int k = prev; k <= miles; k++)
  {
    myArray[index] = k;
    MilesToDays(myArray, index + 1, miles, milesLeft - k, numberOfDays);
  }
}