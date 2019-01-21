#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_pentagon_num(unsigned long long N)
{
	//inverse of pentagon number
	if ((unsigned long long)((1 + sqrt(1 + 24 * N)) / 6) == (double)((1 + sqrt(1 + 24 * N)) / 6))
	{
		return true;
	}
	return false;
}

int main(int argc, const char * argv[]) {

	int i = 144;
	unsigned long long tmp;

	while (1)
	{
		tmp = i * (2*i-1);
		if (is_pentagon_num(tmp))
		{
			printf("%lld\n", tmp);
			return 0;
		}
		i++;

	}
	

	return 0;
}
