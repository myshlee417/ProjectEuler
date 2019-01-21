#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

bool is_palindrome(vector <int> data)
{
	int j;
	for (int i = 0; i < data.size() / 2; i++)
	{
		j = data.size() - 1 - i;
		if (data[i] != data[j])
		{
			return false;
		}
	}
	return true;
}

int main(int argc, const char * argv[]) {
	int tmp;
	int sum=0;

	for (int i = 1; i < 1000000; i++)
	{
		vector <int> decimal;
		vector <int> binary;

		tmp = i;
		while (tmp != 0)
		{
			decimal.push_back(tmp % 10);
			tmp /= 10;
		}
		tmp = i;
		while (tmp != 0)
		{
			binary.push_back(tmp % 2);
			tmp /= 2;
		}
		if (is_palindrome(decimal) && is_palindrome(binary))
		{
			sum += i;
		}
	}
	printf("%d\n", sum);

	return 0;
}
