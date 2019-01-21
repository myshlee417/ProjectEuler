#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 2000

using namespace std;

int main(int argc, const char * argv[]) {

	ifstream in("words.txt");
	string input_str;
	string word[NUM];
	int word_num[NUM] = { 0 };
	int temp = 0, tmp = 0, tmp2, tmp3;
	bool check = true;
	int start;
	int end;
	unsigned long long sum = 0;
	int alphabet_sum = 0;
	int num=0;

	in >> input_str;

	for (int i = 0; i < input_str.size(); i++)
	{
		if (input_str.at(i) == '"' && check == true)
		{
			start = i + 1;
			check = false;
		}
		else if (input_str.at(i) == '"')
		{
			end = i - 1;
			check = true;
			word[temp] = input_str.substr(start, end - start + 1);
			temp++;
		}
	}

	for (int i = 0; i < temp; i++)
	{
		for (int j = 0; j < word[i].size(); j++)
		{
			word_num[i] += word[i].at(j) - 'A' + 1;
		}
	}

	sort(word_num, word_num + temp);

	tmp2 = 1;
	tmp3 = 1;
	while (tmp < temp)
	{
		if (tmp2 < word_num[tmp])
		{
			tmp3++;
			tmp2 = tmp3 * (tmp3 + 1) / 2;
		}
		else if (tmp2 == word_num[tmp])
		{
			num++;
		}
		tmp++;
	}

	printf("%d\n", num);
	return 0;
}
