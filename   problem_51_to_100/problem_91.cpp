#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 50

using namespace std;

int gcd(int n, int m)
{
	while (true)
	{
		if (n > m)
			n -= m;
		else if (m > n)
			m -= n;
		else
			return n;
	}
}

int main(int argc, const char * argv[]) {

	int sum = 3 * NUM*NUM;
	for (int x = 1; x <= NUM; x++)
	{
		for (int y = 1; y <= NUM; y++)
		{
			int x_temp = x / (gcd(x, y));
			int y_temp = y / (gcd(x, y));
			for (int k = 1;; k++)
			{
				if ((x - k * y_temp) >= 0 && k*x_temp + y <= NUM)
					sum++;
				else
					break;
			}

			for (int k = 1;; k++)
			{
				if ((x + k * y_temp) <= NUM && y - k*x_temp >= 0)
					sum++;
				else
					break;
			}
		}
	}
	cout << sum << endl;

	return 0;
}
