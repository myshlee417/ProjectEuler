#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {

	vector <int> prime;
	prime.push_back(2);
	int tmp = 3;
	bool check;
	double tmp2;

	while (1)
	{
		if (is_prime(tmp))
		{
			prime.push_back(tmp);
		}
		else
		{
			check = false;
			for (int i = 0; i < prime.size(); i++)
			{
				tmp2 = (tmp - prime[i]) / 2;
				if ((int)tmp2==tmp2
					&& (int)sqrt(tmp2)==sqrt(tmp2))
				{
					check = true;
					break;
				}
			}
			if (check == false)
			{
				printf("%d\n", tmp);
				return 0;
			}
		}

		tmp += 2;
	}
	

	return 0;
}
