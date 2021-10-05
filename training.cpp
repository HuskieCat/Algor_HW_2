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