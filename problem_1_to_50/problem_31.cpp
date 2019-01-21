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
	int data[201][9];
	int coin[9] = { 0,1,2,5,10,20,50,100,200 };

	for (int i = 1; i <= 8; i++)
	{
		data[0][i] = 1;
		data[1][i] = 1;
	}

	for (int i = 1; i <= 200; i++)
	{
		data[i][1] = 1;
	}

	for (int i = 2; i <= 8; i++)
	{
		for (int j = 2; j < coin[i]; j++)
		{
			data[j][i] = data[j][i - 1];
		}
		for (int j = coin[i]; j <= 200; j++)
		{
			data[j][i] = data[j - coin[i]][i] + data[j][i-1];
		}
	}

	printf("%d\n", data[200][8]);

	return 0;
}
