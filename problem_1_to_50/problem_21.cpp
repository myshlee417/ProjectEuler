#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	
	int M[10001] = { 0 };
	int sol = 0;

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				if (j != i / j)
				{
					M[i] += i / j;
				}
				M[i] += j;
			}
		}
		M[i] -= i;
		if (i > M[i] && M[i]<=10000 && i == M[M[i]])
		{
			sol += M[i] + i;
		}
	}
	printf("%d\n", sol);

	return 0;
}
