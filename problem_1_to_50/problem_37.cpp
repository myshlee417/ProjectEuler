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
	if (n == 1 || n == 0)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {
	
	int num = 0;
	int sum = 0;
	int value = 10;
	int tmp;
	bool check;

	while (num < 11)
	{
		tmp = value;
		check = true;
		while (tmp != 0)
		{
			if (!is_prime(tmp))
			{
				check = false;
				break;
			}
			tmp /= 10;
		}
		tmp = value;
		if (check)
		{
			while (tmp != 0)
			{
				if (!is_prime(tmp))
				{
					check = false;
					break;
				}
				tmp %= (int)pow(10,(int)log10(tmp));
			}
		}
		if (check)
		{
			sum += value;
			num++;
		}
		value++;
	}
	printf("%d\n", sum);
	return 0;
}
