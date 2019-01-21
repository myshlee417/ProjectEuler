#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 1000
using namespace std;

int my_max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

class BigInteger
{
public:
	vector<int> data;


	BigInteger()
	{
		data.clear();
	}

	BigInteger(vector<int> x)
	{
		data.clear();
		for (int i = 0; i < x.size(); i++)
		{
			data.push_back(x[i]);
		}
	}

	BigInteger(int x)
	{
		data.clear();
		int temp = x;
		while (temp != 0)
		{
			data.push_back(temp % 10);
			temp /= 10;
		}
	}

	void assign(BigInteger x)
	{
		data.clear();
		for (int i = 0; i < x.data.size(); i++)
		{
			data.push_back(x.data[i]);
		}
	}

	BigInteger sum(BigInteger x, BigInteger y)
	{
		int up;
		BigInteger sol;
		if (x.data.size() > y.data.size()) {
			up = 0;
			for (int i = 0; i < y.data.size(); i++)
			{
				sol.data.push_back((x.data[i] + y.data[i] + up) % 10);
				up = (x.data[i] + y.data[i] + up) / 10;
			}
			for (int i = y.data.size(); i < x.data.size(); i++)
			{
				sol.data.push_back((x.data[i] + up) % 10);
				up = (x.data[i] + up) / 10;
			}
			while (up != 0)
			{
				sol.data.push_back(up % 10);
				up = up / 10;
			}
			return sol;
		}

		up = 0;
		for (int i = 0; i < x.data.size(); i++)
		{
			sol.data.push_back((x.data[i] + y.data[i] + up) % 10);
			up = (x.data[i] + y.data[i] + up) / 10;
		}
		for (int i = x.data.size(); i < y.data.size(); i++)
		{
			sol.data.push_back((y.data[i] + up) % 10);
			up = (y.data[i] + up) / 10;
		}
		while (up != 0)
		{
			sol.data.push_back(up % 10);
			up = up / 10;
		}
		return sol;
	}

	BigInteger mult_one(BigInteger x, int y)
	{
		int up = 0;
		BigInteger sol;
		for (int i = 0; i < x.data.size(); i++)
		{
			sol.data.push_back((x.data[i] * y + up) % 10);
			up = (x.data[i] * y + up) / 10;
		}
		while (up != 0)
		{
			sol.data.push_back(up % 10);
			up = up / 10;
		}
		return sol;
	}

	BigInteger mult_ten(BigInteger x, int y)
	{
		BigInteger sol;
		for (int i = 0; i<y; i++)
			sol.data.push_back(0);

		for (int i = 0; i < x.data.size(); i++)
		{
			sol.data.push_back(x.data[i]);
		}
		return sol;
	}

	BigInteger mult(BigInteger x, BigInteger y)
	{
		BigInteger sol;
		if (x.data.size() > y.data.size()) {

			for (int i = 0; i < y.data.size(); i++)
			{
				sol.assign(sum(sol, mult_ten(mult_one(x, y.data[i]), i)));
			}
			return sol;
		}

		for (int i = 0; i < x.data.size(); i++)
		{
			sol.assign(sum(sol, mult_ten(mult_one(y, x.data[i]), i)));
		}

		return sol;
	}

	int digit_sum()
	{
		int sol = 0;
		for (int i = 0; i < data.size(); i++)
			sol += data[i];
		return sol;
	}

	void print()
	{
		for (int i = 0; i < data.size(); i++)
			printf("%d", data[data.size() - i - 1]);
		printf("\n");
	}
};

int main(int argc, const char * argv[]) {

	BigInteger numerator(3);
	BigInteger denominator(2);
	BigInteger tmp;
	int num = 0;

	for (int i = 0; i < NUM-1; i++)
	{
		tmp.assign(denominator);
		denominator.assign(denominator.sum(denominator,numerator));
		numerator.assign(denominator.sum(denominator, tmp));

		if (denominator.data.size() < numerator.data.size())
		{
			num++;
		}
	}
	printf("%d\n", num);

	return 0;
}
