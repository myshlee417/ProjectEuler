#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_pentagon_num(int N)
{
	//inverse of pentagon number
	if ((int)((1 + sqrt(1 + 24 * N)) / 6) == (double)((1 + sqrt(1 + 24 * N)) / 6))
	{
		return true;
	}
	return false;
}

int main(int argc, const char * argv[]) {

	int i = 1;
	int tmp, tmp2;
	int D=INT32_MAX;
	
	while (1)
	{
		tmp = i * (3 * i - 1) / 2;
		//printf("%d\n", i);
		for (int j = i-1; j >= 1; j--)
		{
			tmp2 = j * (3 * j - 1) / 2;
			if (is_pentagon_num(tmp + tmp2) && is_pentagon_num(tmp - tmp2) && D>tmp - tmp2)
			{
				D = tmp - tmp2;
				printf("%d\n", D);
				return 0;
			}
		}
		i++;
	}
	

	return 0;
}
