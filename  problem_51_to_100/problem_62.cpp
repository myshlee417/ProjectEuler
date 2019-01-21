#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 100000000

using namespace std;

class string_num
{
public:
	string str;
	string first;
	int num=1;
};

int main(int argc, const char * argv[]) {

	bool check;
	long long base = 1;
	long long tmp;
	vector <string_num> data;
	vector <string> temp;

	string_num find_value;

	while (1)
	{
		temp.clear();
		tmp = base * base*base;
		find_value.first = "";
		while (tmp != 0)
		{
			temp.push_back(to_string(tmp%10));
			tmp /= 10;
		}
		for (int i = temp.size()-1; i >=0; i--)
		{
			find_value.first.append(temp[i]);
		}

		sort(temp.begin(), temp.end());
		find_value.str = "";
		for (int i = 0; i < temp.size(); i++)
		{
			find_value.str.append(temp[i]);
		}

		check = true;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i].str.compare(find_value.str) == 0)
			{
				data[i].num++;
				if (data[i].num == 5)
				{
					cout << data[i].first << endl;
					return 0;
				}
				check = false;
				break;
			}
		}
		if (check)
		{
			data.push_back(find_value);
		}
		base++;
	}

	return 0;
}
