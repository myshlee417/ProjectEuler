#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, const char * argv[]) {
	
	int max = 0;
	int temp;
	int cycle[1000];
	int try_num;
	int index = 1;

	for (int i = 2; i < 1000; i++)
	{
		try_num = 1;
		temp = 10;
		for (int j = 1; j < i; j++)
		{
			cycle[j] = 0;
		}

		while (1)
		{
			temp %= i;
			if (temp == 0)
			{
				break;
			}
			if (cycle[temp] != 0 && try_num-cycle[temp]>max)
			{
				max=try_num - cycle[temp];
				index = i;
				break;
			}
			else if (cycle[temp] != 0)
			{
				break;
			}
			cycle[temp] = try_num;
			try_num++;
			temp *= 10;
		}
	}

	printf("%d\n", index);

	return 0;
}
