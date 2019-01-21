#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 1000000

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

	bool operator<(const BigInteger &x) const
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

	bool operator==(const BigInteger &x)
	{
		if (data.size() < x.data.size())
			return false;
		if (data.size() > x.data.size())
			return false;
		for (int i = data.size() - 1; i >= 0; i--)
		{
			if (data[i] < x.data[i])
				return false;
			if (data[i] > x.data[i])
				return false;
		}
		return true;
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
				ret.data[i] += data[i]+up;
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
			ret.data[i] += x.data[i]+up;
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
		int up;
		BigInteger ret;
		for (int i = 0; i < x.data.size(); i++)
		{
			if (x.data[i] != 0)
			{
				up = 0;
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

	void print() const
	{
		for (int i = data.size() - 1; i >= 0; i--)
		{
			cout << data[i];
		}
	}
};

int main(int argc, const char * argv[]) {

	BigInteger limit(1);
	for (int i = 1; i <= 12; i++)
		limit = limit * 10;

	set <BigInteger> data;
	BigInteger sum(1);
	
	for (int i = 2; i < NUM; i++)
	{
		BigInteger k(i+1);
		while(true)
		{
			k = k * i + 1;
			if (k > limit || k == limit)
				break;
			data.insert(k);
		}
	}

	for (set<BigInteger>::iterator itr = data.begin(); itr != data.end(); ++itr)
	{
		sum = sum + *itr;
	}
	sum.print();
	cout << endl;
	return 0;
}
