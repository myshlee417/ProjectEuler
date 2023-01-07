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
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {
	
	int max_prime = 0;
	int max_product;
	int n;

	for (int a = -999; a < 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			n = 0;
			while (is_prime(n*n + a * n + b))
			{
				n++;
			}
			if (max_prime < n)
			{
				max_prime = n;
				max_product = a * b;
			}
		}
	}
	printf("%d\n", max_product);

	return 0;
}
