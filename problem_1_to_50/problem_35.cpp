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
	int temp[6];
	int size;
	int tmp;
	bool check;
	int num = 0;

	for (int i = 2; i < 1000000; i++)
	{
		tmp = i;
		size = (int)log10(i) + 1;
		check = true;
		for (int i = 0; i < size; i++)
		{
			temp[i] = tmp % 10;
			tmp /= 10;
		}
		
		for (int i = 0; i < size; i++)
		{
			tmp = temp[0];
			for (int j = 0; j < size; j++)
			{
				temp[j] = temp[j + 1];
			}
			temp[size - 1] = tmp;

			tmp = 0;
			for (int j = size-1; j >=0; j--)
			{
				tmp *= 10;
				tmp += temp[j];
			}
			if (!is_prime(tmp))
			{
				check = false;
			}
		}
		if (check == true)
		{
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}
