#include <array>
#include <iostream>
#include <vector>
#define LengthOfArray 7
using namespace std;
int maxSubVector(vector<int> i_VectorToCheck);

void main()
{
	vector<int> arrayOfNums(7);
	arrayOfNums = { 5,-6,10,-5,3,4,-6 };
	cout<<maxSubVector(arrayOfNums);
	
}

int maxSubVector(vector<int> i_VectorToCheck)
{
	int localMax = i_VectorToCheck[0];
	int localSum= i_VectorToCheck[0];
	for(int i = 1; i<7; i++)
	{
		localSum += i_VectorToCheck[i];
		if(i_VectorToCheck[i] < localSum)
		{
			continue;
		}
		else
		{
			localSum = i_VectorToCheck[i];
		}
	}
}