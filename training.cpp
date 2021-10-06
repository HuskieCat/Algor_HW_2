/*
  Calculates how many combinations (without permutations) it would take to get the 
  sum of a specific number.
   
  Promps the user for a distance in miles and gives back how many days it would take 
  to do so.
   
  OUTPUTS w/ time
      Program Start
      Enter race distance in miles: 5
      Length of training schedule: 7
      Time: 0 ms
      Time: 0 s
      Program End

      Program Start
      Enter race distance in miles: 13
      Length of training schedule: 101
      Time: 0 ms
      Time: 0 s
      Program End

      Program Start
      Enter race distance in miles: 26
      Length of training schedule: 2436
      Time: 0 ms
      Time: 0 s
      Program End

      Program Start
      Enter race distance in miles: 100
      Length of training schedule: 190569292
      Time: 6464 ms
      Time: 6 s
      Program End 

Author: Bradley Henderson
 */ 

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

void MilesToDays(int, int, int, int&);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  int numberOfDays = 0;

  auto start = high_resolution_clock::now();

  MilesToDays(raceDistance, 1, raceDistance, numberOfDays);

  auto stop = high_resolution_clock::now();
  long duration_MS = duration_cast<milliseconds>(stop - start).count();
  long duration_S = duration_cast<seconds>(stop - start).count();

  cout << "Length of training schedule: " << numberOfDays << endl;
  cout << "Time: " << duration_MS << " ms" << endl;
  cout << "Time: " << duration_S << " s" << endl;

  cout << "Program End\n";
}

/*
A recursive algorithm that takes miles, the previous itteration, last known 
subtraction and the number of days
*/
void MilesToDays(int miles, int previousI, int reduction, int &numberOfDays)
{
  for(int i = previousI; i <= miles; i++)
  {
    int reduce = reduction - i;

    if(reduce < 0)
      return;

    if(reduce == 0)
    {
      numberOfDays++;
      return;
    }

    MilesToDays(miles, i, reduction - i, numberOfDays);
  }
}