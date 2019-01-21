#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_pandigital(unsigned long long data)
{
	int dataset[10] = { 0 };
	unsigned long long tmp = data;
	while (tmp != 0)
	{
		if (dataset[tmp % 10] != 0 || tmp%10==0)
		{
			return false;
		}
		else
		{
			dataset[tmp % 10] = 1;
		}
		tmp /= 10;
	}
	return true;
}

int main(int argc, const char * argv[]) {
	
	unsigned long long max = 918273645;
	unsigned long long tmp;
	for (int i = 9999; i >= 9000; i--)
	{
		tmp = (unsigned long long)i * 100000 + i * 2;
		if (is_pandigital(tmp))
		{
			if (tmp < max)
				printf("%lld\n", max);
			else
			{
				printf("%lld\n", tmp);
			}
			break;
		}
	}
	return 0;
}
