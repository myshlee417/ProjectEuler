#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 1000000

using namespace std;

bool is_prime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {

	unsigned long long num=0;
	int tmp, tmp2, tmp3;
	bool check;
	vector <int> primes;

	for (int i = 2; i <= NUM; i++)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
		printf("%d\n", i);
	}

	for (int i = 2; i <= NUM; i++)
	{
		tmp = i;
		tmp2 = 0;
		tmp3 = i;
		check = true;

		while (tmp != 1)
		{
			if (tmp%primes[tmp2] == 0)
			{
				if (check == true)
				{
					tmp3 /= primes[tmp2];
					tmp3 *= (primes[tmp2] - 1);
					check = false;
				}
				tmp /= primes[tmp2];
				continue;
			}
			check = true;
			tmp2++;
		}
		num += tmp3;
		printf("%d %lld\n", i, num);
	}
	printf("%lld\n", num);
	return 0;
}
