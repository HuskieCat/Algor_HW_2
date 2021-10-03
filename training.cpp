#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void MilesToDays(int[],int,int,int, unsigned long long&);
void MilesToDays(int, int, int, int, int&);
void Factors(int);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  int numberOfDays = 0;

  int myArray [raceDistance];
  auto start = high_resolution_clock::now();

  //MilesToDays(myArray, 0, raceDistance, raceDistance, numberOfDays);
  //MilesToDays(raceDistance, 0, 1, numberOfDays2);
  //Factors(48);
  MilesToDays(0, 0, raceDistance, raceDistance, numberOfDays);

  auto stop = high_resolution_clock::now();
  long duration_MS = duration_cast<milliseconds>(stop - start).count();
  long duration_S = duration_cast<seconds>(stop - start).count();

  cout << "Length of training schedule: " << numberOfDays << endl;
  cout << "Time: " << duration_MS << " ms" << endl;
  cout << "Time: " << duration_S << " s" << endl;

  cout << "Program End\n";
}

void MilesToDays(int previousNum, int index, int num, int reducedNum, int &numberOfDays)
{
  if(reducedNum < 0)
    return;

  if(reducedNum == 0)
  {
    numberOfDays++;
    return;
  }

  int prev = (index == 0)? 1 : previousNum;

  for(int k = prev; k <= num; k++)
  {
    MilesToDays(k, index + 1, num, reducedNum - k, numberOfDays);
  }
}

void Factors(int n)
{
  for (int i = 1; i <= n; i++)
	  for(int j = i; j <= n; j++)
		  for (int k = j; k <= n; k++)
			  if(i * j * k == n)
				  cout << i << " * " << j << " * " << k << " = " << n << endl;
}

/*void MilesToDays(int myArray[], int index, int miles, int milesLeft, unsigned long long &numberOfDays)
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
}*/