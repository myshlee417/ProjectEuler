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
	
	int fraction_num = 1;
	int cur = 0;
	int border[7] = { 1,10,100,1000,10000,100000,1000000 };
	string fraction;
	int num = 0;
	int mult = 1;

	while (num<7)
	{
		fraction = to_string(fraction_num);
		if (cur + fraction.size() >= border[num])
		{
			mult *= fraction.at(border[num] - cur - 1)-'0';
			num++;
		}
		cur += fraction.size();
		fraction_num++;
	}
	printf("%d\n", mult);
	return 0;
}
