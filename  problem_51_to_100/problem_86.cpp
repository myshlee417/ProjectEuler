#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, const char * argv[]) {

	int num = 0;
	long long a, b, c;

	for (c = 1;; c++)
	{
		for (a = 1; a <= c; a++)
		{
			for (b = a; b <= c; b++)
			{
				if ((long long)sqrt(c*c + (a + b)*(a + b)) == sqrt(c*c + (a + b)*(a + b)))
				{
					num++;
				}
			}
		}
		if (num>1000000)
		{
			break;
		}
	}

	cout << c << endl;

	return 0;
}
