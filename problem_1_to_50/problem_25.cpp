#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	
	int i = 2;
	vector <int> data[2];

	data[0].push_back(1);
	data[0].push_back(0);
	data[1].push_back(1);
	data[1].push_back(0);

	while (data[i % 2].size() < 1001)
	{
		i++;
		for (int j = 0; j < data[(i+1)%2].size();j++)
		{
			data[i % 2][j] += data[(i + 1) % 2][j];
			if (data[i % 2][j] >= 10)
			{
				data[i % 2][j] -= 10;
				data[i % 2][j + 1]++;
			}
		}

		if (data[i % 2][data[i % 2].size() - 1] != 0)
		{
			data[0].push_back(0);
			data[1].push_back(0);
		}
	}
	printf("%d\n", i);
	return 0;
}
