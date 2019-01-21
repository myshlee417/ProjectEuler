#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 10000

using namespace std;

int main(int argc, const char * argv[]) {
	
	ifstream in("names.txt");
	string input_str;
	string name[NUM];
	int temp = 0;
	bool check = true;
	int start;
	int end;
	unsigned long long sum=0;
	int alphabet_sum = 0;

	in >> input_str;

	for (int i = 0; i < input_str.size(); i++)
	{
		if (input_str.at(i) == '"' && check==true)
		{
			start = i+1;
			check = false;
		}
		else if (input_str.at(i) == '"')
		{
			end = i-1;
			check = true;
			name[temp] = input_str.substr(start,end-start+1);
			temp++;
		}
	}
	sort(name, name + temp);

	for (int i = 0; i < temp; i++)
	{
		alphabet_sum = 0;
		for (int j = 0; j < name[i].size(); j++)
		{
			alphabet_sum += name[i].at(j) - 'A'+1;
		}
		sum += alphabet_sum * (i+1);
	}
	printf("%lld\n", sum);

	return 0;
}
