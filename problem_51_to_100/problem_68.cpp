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

	int min = INT32_MAX;

	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			for (int c = 1; c <= 9; c++)
			{
				for (int d = 1; d <= 9; d++)
				{
					for (int e = 1; e <= 9; e++)
					{
						if ((a + b + c + d + e) % 5 == 0)
						{
							int num[11] = { 0 };
							num[a]--;
							num[b]--;
							num[c]--;
							num[d]--;
							num[e]--;
							int k = (a + b + c + d + e) / 5;
							int sum = 11 + k;
							bool check = true;
							for (int i = 0; i < 5; i++)
							{
								int n;
								switch (i)
								{
								case 0:
									n = sum - e - d;
									break;
								case 1:
									n = sum - e - a;
									break;
								case 2:
									n = sum - a - b;
									break;
								case 3:
									n = sum - b - c;
									break;
								case 4:
									n = sum - c - d;
									break;
								}
								if (n > 0 && n <= 10)
								{
									num[n]--;
								}
							}
							bool check2 = true;
							for (int i = 1; i <= 10; i++)
							{
								if (num[i] != -1)
								{
									check2 = false;
								}
							}
							if (check2 && min > a + b + c + d + e)
							{
								min = a + b + c + d + e;
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
