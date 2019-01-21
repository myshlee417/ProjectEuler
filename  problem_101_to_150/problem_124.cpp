#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 100000

using namespace std;

class my_set
{
public:
	int key;
	int value;

	my_set(int a, int b)
	{
		key = a;
		value = b;
	}

	bool operator <(const my_set &x) const
	{
		if (value == x.value)
			return (key < x.key);
		return (value < x.value);
	}
};

int rad(int n)
{
	int limit = sqrt(n);
	int temp = 1;
	int mul = 1;

	for (int i = 2; i <= limit; i++)
	{
		if (n == 1)
			return mul;
		if (n%i == 0)
		{
			n /= i;
			if (temp < i)
			{
				temp = i;
				mul *= i;
			}
			i--;
		}
	}

	return (mul*n);
}

int main(int argc, const char * argv[]) {

	vector<my_set> data;

	for (int i = 1; i <= 100000; i++)
	{
		data.push_back(my_set(i,rad(i)));
	}

	sort(data.begin(), data.end());

	cout << data[9999].key << endl;

	return 0;
}
