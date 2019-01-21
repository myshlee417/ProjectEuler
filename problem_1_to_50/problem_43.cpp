#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, const char * argv[]) {

	string pandigital;
	string final_pan;
	int tmp;
	bool check;
	unsigned long long sum=0;
	int prime[7] = { 2,3,5,7,11,13,17 };
	for (int i = 9; i >= 0; i--)
	{
		pandigital.append(to_string(i));
	}
	for (int i = 0; i <= 9; i++)
	{
		final_pan.append(to_string(i));
	}


	do {
		check = true;
		for (int i = 1; i <= 7; i++)
		{
			tmp = stoi(pandigital.substr(i, 3));
			if (tmp%prime[i - 1] != 0)
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			sum += stoll(pandigital);
		}
		prev_permutation(pandigital.begin(),pandigital.end());
	}
	while (pandigital.compare(final_pan) != 0);

	printf("%lld\n", sum);

	return 0;
}
