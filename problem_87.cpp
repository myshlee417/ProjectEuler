#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 50000000

using namespace std;

bool is_prime(int n)
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
	set <int> data;
	int temp;

	for (int i = 2; i < 7071; i++)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
	}

	for (int i = 0; i < primes.size(); i++)
	{
		for (int j = 0; j < primes.size(); j++)
		{
			temp = primes[i] * primes[i];
			temp += primes[j] * primes[j] * primes[j];
			if (temp >= NUM)
				break;

			for (int k = 0; k < primes.size(); k++)
			{
				temp = primes[i] * primes[i];
				temp += primes[j] * primes[j] * primes[j];
				temp += primes[k]*primes[k]*primes[k]*primes[k];
				if (temp >= NUM)
					break;
				data.insert(temp);
			}
		}
	}
	cout << data.size() <<endl;
	return 0;
}
