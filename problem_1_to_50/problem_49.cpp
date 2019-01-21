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
		{
			return false;
		}
	}
	return true;
}

bool is_permutation(string n, string s)
{
	string q = n;
	do
	{
		if (n.compare(s) == 0)
			return true;
		next_permutation(n.begin(),n.end());
	} while (q.compare(n) != 0);
	return false;
}

int main(int argc, const char * argv[]) {

	int n = 1488;
	string number;
	string tmp;

	while (1)
	{
		number = to_string(n);
		tmp = number;
		for (int i = 0; i < 23; i++)
		{
			next_permutation(number.begin(),number.end());
			if (number.compare(tmp)!=0 && is_prime(stoi(tmp)) && is_prime(stoi(number)) && is_prime(2 * stoi(number) - stoi(tmp))&& 2 * stoi(number) - stoi(tmp)>=0 && is_permutation(number, to_string(2*stoi(number)-stoi(tmp))))
			{
				cout<< tmp << number << to_string(2 * stoi(number) - stoi(tmp)) << endl;
				return 0;
			}
		}
		n++;
	}
	return 0;
}
