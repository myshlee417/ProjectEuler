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



bool is_four_dis_prime_factor(int n, vector <int> prime)
{
	int i = 0;
	bool check;
	int num = 0;

	while (n != 1)
	{
		if (num >= 4)
		{
			return false;
		}
		check = false;
		while (n % prime[i]==0)
		{
			check = true;
			n /= prime[i];
		}
		if (check)
		{
			num++;
		}
		i++;
	}
	if (num != 4)
	{
		return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {

	vector <int> prime;
	prime.push_back(2);
	int i = 3;
	int num = 0;

	while (1)
	{
		if (is_prime(i))
		{
			prime.push_back(i);
			num = 0;
		}
		else if(is_four_dis_prime_factor(i,prime))
		{
			num++;
			if (num == 4)
			{
				printf("%d\n", i - 3);
				return 0;
			}
		}
		else
		{
			num = 0;
		}
		i++;
	}

	
	

	return 0;
}
