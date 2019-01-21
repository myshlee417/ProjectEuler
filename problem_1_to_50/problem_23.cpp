#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	
	int M[28124] = { 0 };
	vector <int> overnum;
	int tmp;

	for (int i = 1; i <= 28123; i++)
	{
		tmp = 0;
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				if (j == i / j)
					tmp -= j;
				tmp += j + i / j;
			}
		}
		tmp -= i;
		if (tmp > i)
		{
			overnum.push_back(i);
		}
	}
	for (int i = 0; i < (int)overnum.size(); i++)
	{
		for (int j = 0; j < (int)overnum.size(); j++)
		{
			if(overnum[i]+overnum[j]<=28123)
				M[overnum[i] + overnum[j]] = 1;
		}
	}
	int sol = 0;
	for (int i = 1; i <= 28123; i++)
	{
		if (M[i] == 0)
		{
			sol += i;
		}
	}

	printf("%d\n", sol);
	return 0;
}
