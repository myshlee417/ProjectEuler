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
	
	string data;
	string tmp;
	for (int n = 9; n >= 1; n--)
	{
		data.clear();
		for (int i = n; i >= 1; i--)
		{
			data.append(to_string(i));
		}
		tmp = data;

		do
		{
			if (is_prime(stoi(data)))
			{
				cout << data << endl;
				return 0;
			}
			prev_permutation(data.begin(),data.end());
		}
		while (tmp.compare(data) != 0);
	}

	return 0;
}
