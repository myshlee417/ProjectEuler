#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	vector <int> value;
	//int value[201] = { 0 };
	int sol = 0;
	int tmp;

	value.push_back(0);
	value.push_back(1);

	for (int i = 2; i <= 100; i++)
	{
		tmp = value.size();
		for (int j = 1; j < tmp; j++)
		{
			value[j] *= i;
		}

		for (int j = 1; j < tmp-1; j++)
		{
			value[j + 1] += value[j] / 10;
			value[j] = value[j] % 10;
		}

		while (value[tmp-1]>=10)
		{
			value.push_back(value[tmp - 1] / 10);
			value[tmp - 1] = value[tmp - 1] % 10;
			tmp++;
		}
	}

	for (int i = 1; i < value.size(); i++)
	{
		sol += value[i];
	}
	printf("%d\n", sol);

	return 0;
}
