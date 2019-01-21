#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 1000000

using namespace std;

int factorial[10];

int digit_factorial(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += factorial[n % 10];
		n /= 10;
	}
	return sum;
}

int main(int argc, const char * argv[]) {

	factorial[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}
	
	int num = 0;

	for (int i = 1; i < NUM; i++)
	{
		vector <int> v;
		int tmp = i;
		int repeat = 0;
		while (find(v.begin(), v.end(), tmp)==v.end())
		{
			v.push_back(tmp);
			repeat++;
			tmp = digit_factorial(tmp);
		}
		if (repeat == 60)
			num++;
	}

	cout << num << endl;

	return 0;
}
