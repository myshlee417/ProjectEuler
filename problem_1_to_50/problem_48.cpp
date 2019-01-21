#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 10000000000

using namespace std;

int main(int argc, const char * argv[]) {

	unsigned long long data;
	unsigned long long sum=0;

	for (int i = 1; i <= 1000; i++)
	{
		data = i;
		for (int j = 1; j < i; j++)
		{
			data *= i;
			data %= NUM;
		}
		sum = (sum + data) % NUM;
	}
	
	printf("%lld\n",sum);
	return 0;
}
