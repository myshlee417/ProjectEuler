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
	int sum = 0;
	int tmp,tmp2;

	for (int i = 10; i < 1000000; i++)
	{
		tmp = i;
		tmp2 = 0;
		while (tmp > 0)
		{
			tmp2 += pow(tmp % 10,5);
			tmp /= 10;
		}
		if (tmp2 == i)
			sum += i;
	}

	printf("%d\n", sum);

	return 0;
}
