#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
#define NUM 1000000000

using namespace std;

int main(int argc, const char * argv[]) {

	long long temp;
	long long reverse_num;
	bool check;
	int sol = 0;

	for (long long i = 0; i < NUM; i++)
	{
		if (i % 10 != 0)
		{
			check = true;
			temp = i;
			reverse_num = 0;
			while (temp > 0)
			{
				reverse_num *= 10;
				reverse_num += temp % 10;
				temp /= 10;
			}
			reverse_num += i;
			while (reverse_num > 0)
			{
				if ((reverse_num % 10) % 2 == 0)
				{
					check = false;
					break;
				}
				reverse_num /= 10;
			}
			if (check)
			{
				sol++;
			}
		}
	}
	cout << sol << endl;
	return 0;
}
