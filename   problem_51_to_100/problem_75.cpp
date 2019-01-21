#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 1500000

using namespace std;

int array_temp[NUM + 1] = { 0 };

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

	int num = 0;

	for (int n = 1; n <= 612; n++)
	{
		for (int m = n + 1; m <= 866; m++)
		{
			if (m*m + m * n > NUM/2)
				break;
			if ((n + m) % 2 == 1 && gcd(n, m) == 1)
			{
				for (int k = 1;; k++)
				{
					if (k * 2 * m*(m + n) > NUM)
						break;
					array_temp[k * 2 * m*(m + n)]++;
				}
			}
		}
	}

	for (int i = 1; i <= NUM; i++)
	{
		if (array_temp[i] == 1)
			num++;
	}
	cout << num << endl;

	return 0;
}
