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

double my_min(double x1, double x2)
{
	if (x1 < x2)
		return x1;
	return x2;
}

double my_max(double x1, double x2)
{
	if (x1 < x2)
		return x2;
	return x1;
}

int x_intercept_value(double x1, double x2, double y1, double y2)
{
	//y=(y2-y1)/(x2-x1)(x-x1) + y1
	double m = (y2 - y1) / (x2 - x1);
	double b = y1 - m * x1;

	double x_intercept=(-1.0)*b/m;
	if (x_intercept >= my_min(x1, x2) && x_intercept <= my_max(x1, x2))
	{
		if (x_intercept > 0.0)
			return 2;
		return 1;
	}
	return 0;
}

int main(int argc, const char * argv[]) {

	ifstream in("triangles.txt");
	string input;
	int x[4], y[4];
	int num = 0;
	int tmp, tmp2, tmp3[3];

	for (int i = 0; i < NUM; i++)
	{
		in >> input;
		tmp = 0;
		tmp2 = 2;
		for (int j = 0; j < input.size(); j++)
		{
			if (input.at(j) == ',')
			{
				if (tmp2 % 2 == 0)
				{
					x[tmp2 / 2] = stoi(input.substr(tmp, j - tmp));
				}
				else
				{
					y[tmp2 / 2] = stoi(input.substr(tmp, j - tmp));
				}
				tmp = j + 1;
				tmp2++;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			tmp3[j] = 0;
		}
		for (int j = 1; j <= 3; j++)
			tmp3[x_intercept_value((double)x[j], (double)x[1+j%3], (double)y[j], (double)y[1 + j % 3])]++;

		if (tmp3[1]>0 && tmp3[2]>0)
		{
			num++;
		}
	}
	printf("%d\n", num);

	return 0;
}
