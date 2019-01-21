#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, const char * argv[]) {

	int factorial[10];
	factorial[0] = 1;
	int sum_tmp, tmp;
	int sum = 0;

	for (int i = 1; i <= 9; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}

	for (int i = 10; i < 999999; i++)
	{
		tmp = i;
		sum_tmp = 0;

		while (tmp != 0)
		{
			sum_tmp += factorial[tmp%10];
			tmp /= 10;
		}
		if (sum_tmp == i)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
}
