#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_primes(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {

	vector <int> primes;

	for (int i = 2;; i++)
	{
		vector <int> data;
		
		if (is_primes(i))
		{
			primes.push_back(i);
		}

		for (int j = 0; j <= i; j++)
		{
			data.push_back(0);
		}
		data[0] = 1;

		for (int k = 0; k < primes.size(); k++)
		{
			for (int j = primes[k]; j <= i; j++)
			{
				data[j] += data[j-primes[k]];
			}
		}

		if (data[i] > 5000)
		{
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
