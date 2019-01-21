#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	int day = 365;
	int sol = 0;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 1901; i <= 2000; i++)
	{
		for (int j = 1;j<=12;j++)
		{
			if ((day + 1) % 7 == 0)
			{
				sol++;
			}
			day += month[j];
			if (i % 4 == 0 && i % 400 != 0 && j == 2)
			{
				day++;
			}
		}
	}

	printf("%d\n", sol);

	return 0;
}
