#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

void MilesToDays(int[],int,int,int, unsigned long long&);
void MilesToDays(int, int, int, int, int&);
void Try2(int, int, int&);
void Try3(int, int, int, int &, int[]);
void Factors(int);
void Adds(int);
void PrintArray(int[], int);
int SumArray(int[], int);
void ResetArray(int[], int, int);

int main() 
{
  cout << "Program Start\n";
 
  int raceDistance;
  cout << "Enter race distance in miles: ";
  cin >> raceDistance;

  int numberOfDays = 0;

  int myArray [raceDistance];
  ResetArray(myArray, raceDistance, -1);

  auto start = high_resolution_clock::now();

  //MilesToDays(myArray, 0, raceDistance, raceDistance, numberOfDays);
  //MilesToDays(raceDistance, 0, 1, numberOfDays2);
  //Factors(48);
  //MilesToDays(0, 0, raceDistance, raceDistance, numberOfDays);
  //Try2(raceDistance, 0, numberOfDays);
  //Adds(raceDistance);
  Try3(raceDistance, 0, 0, numberOfDays, myArray);

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

  if(previousNum > num)
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

void Try2(int miles, int calculation, int &numberOfDays)
{
  //cout << "Calc:" << calculation << endl;
  if(calculation > miles)
  {
    return;
  }

  cout << calculation << ", ";
  if(calculation == miles)
  {
    numberOfDays++;
    cout << endl;
    return;
  }

  for(int i = 1; i <= miles; i++)
  {
    Try2(miles, calculation += i, numberOfDays);
  }
}

void Try3(int miles, int previousLoop, int numberOfLoops, int &numberOfDays, int myArray[])
{
  PrintArray(myArray, miles);

  if(numberOfLoops > miles)
    return;

  if(SumArray(myArray, miles) == miles)
  {
    PrintArray(myArray, miles);
    cout << SumArray(myArray, miles) << endl;
    numberOfDays++;
    ResetArray(myArray, miles, 0);
    return;
  }

  if(numberOfLoops == 0)
  {
    for(int i = 0; i <= miles; i++)
    {
      myArray[numberOfLoops] = i;
      Try3(miles, i, ++numberOfLoops, numberOfDays, myArray);
    }
  }

  if(numberOfLoops < miles)
  {
    for(int i = previousLoop; i <= miles; i++)
    {
      myArray[numberOfLoops] = i;
      if(SumArray(myArray, miles) == miles)
      {
        PrintArray(myArray, miles);
        cout << SumArray(myArray, miles) << endl;
        numberOfDays++;
        ResetArray(myArray, miles, 0);
        return;
      }
      else
        Try3(miles, i, ++numberOfLoops, numberOfDays, myArray);
    }
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

void Adds(int n)
{
  for (int i = 0; i <= n; i++)
	  for(int j = i; j <= n; j++)
		  for (int k = j; k <= n; k++)
        for (int a = k; a <= n; a++)
          for (int b = a; b <= n; b++)
            if(i + j + k + a + b == n)
              cout << i << " + " 
                  << j << " + " 
                  << k << " + "
                  << a << " + "
                  << b << " = "
                  << n << endl;
}

void PrintArray(int myArray[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if (i < size - 1)
      cout << setw(4) << myArray[i] << ", ";
    else
      cout << setw(4) << myArray[i] << " ";
  }
  cout << endl;
}

int SumArray(int myArray[], int size)
{
  int sum = 0;
  for(int i = 0; i < size; i++)
    sum += myArray[i];
  return sum;
}

void ResetArray(int myArray[], int size, int value)
{
  for(int i = 0; i < size; i++)
    myArray[i] = value;
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