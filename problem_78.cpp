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

int main(int argc, const char * argv[]) {

	vector <int> data;
	data.push_back(1);
	data.push_back(1);

	int index = 2;

	while (1)
	{
		int k = 1;
		int index2 = 1;
		data.push_back(0);
		while (1)
		{
			int Pk = k * (3 * k - 1) / 2;
			if (Pk > index)
				break;
			if (index2 % 4 == 1 || index2 % 4 == 2)
			{
				data[index] = data[index] + data[index - Pk];
				data[index] %= NUM;
			}
			else
				data[index] = data[index] - data[index - Pk];
			k *= -1;
			if (k > 0)
				k++;
			index2++;
		}
		if (data[index] % NUM == 0)
		{
			cout << index << endl;
			return 0;
		}
		index++;
	}


	return 0;
}
