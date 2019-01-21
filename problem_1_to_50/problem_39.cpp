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
	
	int num[1001] = { 0 };
	int c;

	for (int a=1; a<500; a++)
	{
		for (int b = 1; b < 500; b++)
		{
			c = sqrt(pow(a,2) + pow(b,2));
			if ((double)c == sqrt(pow(a, 2) + pow(b, 2)) && a + b + c <= 1000)
			{
				num[a + b + c]++;
			}
		}
	}

	int max = 0;
	int index = 3;
	for (int i = 3; i <= 1000; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			index = i;
		}
	}
	printf("%d\n", index);
	return 0;
}
