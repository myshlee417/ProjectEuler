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

set <int> list;

double calculate(double n, int op, double m, int *a)
{
	switch (op)
	{
	case 0:
		return n + m;
	case 1:
		return n - m;
	case 2:
		return n * m;
	}
	if (m == 0)
	{
		*a = -1;
		return -1;
	}
	return n / m;
}

void maximum(int a, int b, int c, int d)
{
	double temp[6];

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			for (int k = 0; k<4; k++)
			{
				int data[6] = { 0 };

				temp[0] = calculate(calculate(calculate((double)a, i, (double)b, &data[0]), j, (double)c, &data[0]), k, (double)d, &data[0]);
				temp[1] = calculate(calculate((double)a, i, (double)b, &data[1]), j, calculate((double)c, k, (double)d, &data[1]), &data[1]);
				temp[2] = calculate(calculate((double)a, i, calculate((double)b, j, (double)c, &data[2]), &data[2]), k, (double)d, &data[2]);
				temp[3] = calculate(calculate((double)a, i, (double)b, &data[3]), j, calculate((double)c, k, (double)d, &data[3]), &data[3]);
				temp[4] = calculate((double)a, i, calculate(calculate((double)b, j, (double)c, &data[4]), k, (double)d, &data[4]), &data[4]);
				temp[5] = calculate((double)a, i, calculate((double)b, j, calculate((double)c, k, (double)d, &data[5]), &data[5]), &data[5]);

				for (int y = 0; y<6; y++)
				{
					if (data[y] != -1 && temp[y] == (int)temp[y])
					{
						list.insert(temp[y]);
					}
				}

			}
		}
	}
}

int main(int argc, const char * argv[]) {

	int max = 0;
	int max_data[4];

	for (int a = 1; a <= 9; a++)
	{
		for (int b = a + 1; b <= 9; b++)
		{
			for (int c = b + 1; c <= 9; c++)
			{
				for (int d = c + 1; d <= 9; d++)
				{
					int index = 1;
					string order = "";
					string temp_order = "";
					list.clear();
					order += to_string(a);
					temp_order += to_string(a);
					order += to_string(b);
					temp_order += to_string(b);
					order += to_string(c);
					temp_order += to_string(c);
					order += to_string(d);
					temp_order += to_string(d);

					do
					{
						maximum(stoi(order.substr(0, 1)), stoi(order.substr(1, 1)), stoi(order.substr(2, 1)), stoi(order.substr(3, 1)));
						next_permutation(order.begin(), order.end());
					} while (order.compare(temp_order) != 0);

					while (true)
					{
						if (find(list.begin(), list.end(), index) == list.end())
						{
							if (max < index - 1)
							{
								max = index - 1;
								max_data[0] = a;
								max_data[1] = b;
								max_data[2] = c;
								max_data[3] = d;
							}
							break;
						}
						index++;
					}
				}
			}
		}
	}

	cout << max_data[0] << max_data[1] << max_data[2] << max_data[3] << endl;
	return 0;
}
