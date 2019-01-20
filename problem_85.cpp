#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 2000000

using namespace std;

int my_min(int x, int y)
{
	if (x<y)
		return x;
	return y;
}

int num_rec(int n, int m)
{
	//(n+1)C2
	int C1 = (n + 1)*n / 2;

	//(m+1)C2
	int C2 = (m + 1)*m / 2;

	return C1 * C2;

}

int main(int argc, const char * argv[]) {

	int near = 0;
	int gap = NUM;
	int gap1, gap2;

	for (int n = 1; n <= 1500; n++)
	{
		int m = 1;
		while (1)
		{
			if (num_rec(n, m)>NUM)
			{
				break;
			}
			m++;
		}
		if (m == 1)
		{
			gap1 = NUM;
		}
		else
		{
			gap1 = NUM - num_rec(n, m - 1);
		}
		gap2 = num_rec(n, m) - NUM;
		if (my_min(gap1, gap2) < gap)
		{
			if (my_min(gap1, gap2) == gap1)
				near = (m - 1) * n;
			else
				near = m * n;
			gap = my_min(gap1, gap2);
		}
	}

	printf("%d\n",near);

	return 0;
}
