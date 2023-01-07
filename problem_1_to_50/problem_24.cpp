#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {

	int Fac[10];
	int M[10] = { 0 };
	int i = 9;
	int tmp = 1000000;
	int V[10] = { 0 };

	Fac[0] = 1;
	Fac[1] = 1;
	for (int j = 2; j <= 9; j++)
	{
		Fac[j] = j * Fac[j - 1];
	}

	while (i > 0)
	{
		if (tmp > Fac[i])
		{
			tmp -= Fac[i];
			M[i]++;
		}
		else
		{
			i--;
		}
	}

	for (int j = 9; j >= 1; j--)
	{
		printf("M[%d] : %d\n", j, M[j]+1);
	}

	return 0;
}
