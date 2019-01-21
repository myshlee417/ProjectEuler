#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

class BigInteger
{
public:
	vector <int> data;
	BigInteger()
	{
		data.clear();
	}
	BigInteger(int i)
	{
		data.clear();
		if (i == 0)
		{
			data.push_back(0);
		}
		else
		{
			int temp = i;
			while (temp > 0)
			{
				data.push_back(temp % 10);
				temp /= 10;
			}
		}
	}

	bool operator<(const BigInteger &x)
	{
		if (data.size() > x.data.size())
			return false;
		if (data.size() < x.data.size())
			return true;
		for (int i = data.size() - 1; i >= 0; i--)
		{
			if (data[i] > x.data[i])
				return false;
			if (data[i] < x.data[i])
				return true;
		}
		return false;
	}

	bool operator>(const BigInteger &x)
	{
		if (data.size() < x.data.size())
			return false;
		if (data.size() > x.data.size())
			return true;
		for (int i = data.size() - 1; i >= 0; i--)
		{
			if (data[i] < x.data[i])
				return false;
			if (data[i] > x.data[i])
				return true;
		}
		return false;
	}

	bool operator=(const BigInteger &x)
	{
		data.clear();
		for (int i = 0; i <x.data.size(); i++)
		{
			data.push_back(x.data[i]);
		}
		return true;
	}

	BigInteger operator+(const BigInteger &x)
	{
		if (*this > x)
		{
			BigInteger ret = x;
			int up = 0;
			for (int i = 0; i < data.size(); i++)
			{
				if (i >= x.data.size())
				{
					ret.data.push_back(0);
				}
				ret.data[i] += data[i];
				up = ret.data[i] / 10;
				ret.data[i] %= 10;
			}
			if (up > 0)
			{
				ret.data.push_back(up);
			}
			return ret;
		}

		BigInteger ret = *this;
		int up = 0;
		for (int i = 0; i < x.data.size(); i++)
		{
			if (i >= data.size())
			{
				ret.data.push_back(0);
			}
			ret.data[i] += x.data[i];
			up = ret.data[i] / 10;
			ret.data[i] %= 10;
		}
		if (up > 0)
		{
			ret.data.push_back(up);
		}
		return ret;
	}

	BigInteger operator+(int x)
	{
		BigInteger y(x);

		return (*this) + y;
	}

	BigInteger operator-(const BigInteger &x) //only for positive
	{
		BigInteger ret;


		for (int i = 0; i < x.data.size(); i++)
		{
			ret.data.push_back(data[i] - x.data[i]);
		}

		for (int i = x.data.size(); i < data.size(); i++)
		{
			ret.data.push_back(data[i]);
		}

		for (int i = 0; i < data.size(); i++)
		{
			if (ret.data[i] < 0)
			{
				ret.data[i] += 10;
				ret.data[i + 1]--;
			}
		}
		int k = ret.data.size() - 1;
		while (ret.data[k] == 0)
		{
			ret.data.pop_back();
			k--;
		}

		return ret;
	}

	BigInteger operator*(const BigInteger &x)
	{
		int up = 0;
		BigInteger ret;
		for (int i = 0; i < x.data.size(); i++)
		{
			if (x.data[i] != 0)
			{
				BigInteger factor;
				for (int j = 0; j < i; j++)
				{
					factor.data.push_back(0);
				}
				for (int j = 0; j < data.size(); j++)
				{
					up += x.data[i] * data[j];
					factor.data.push_back(up % 10);
					up /= 10;
				}
				if (up > 0)
				{
					factor.data.push_back(up);
				}

				if (i == 0)
					ret = factor;
				else
					ret = ret + factor;
			}
		}
		return ret;
	}

	BigInteger operator*(int x)
	{
		BigInteger y(x);

		return (*this)*y;
	}

	void print()
	{
		for (int i = data.size() - 1; i >= 0; i--)
		{
			cout << data[i];
		}
	}
};

int main(int argc, const char * argv[]) {

	int sum = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i != 1 && i != 4 && i != 9 && i != 16 && i != 25 && i != 36 && i != 49 && i != 64 && i != 81 && i != 100)
		{
			BigInteger p;
			BigInteger temp(i);
			int x;
			for (int j = 0; j < 100; j++)
			{
				for (x = 1; x <= 9; x++)
				{
					if ((p * 20 + x)*x > temp)
						break;
				}
				x = x - 1;
				temp = temp - (p * 20 + x)*x;
				temp = temp * 100;
				p = p * 10 + x;
				sum += x;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
