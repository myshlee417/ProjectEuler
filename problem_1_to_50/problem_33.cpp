#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

class Fraction
{
public:
	int denominator=1, nomerator=1; //분모 분자
	
	Fraction wrong_reduction()
	{
		Fraction reduction_fraction;

		int deno[2] = { denominator / 10 , denominator % 10 };
		int nome[2] = { nomerator / 10 , nomerator % 10 };

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (deno[i] == nome[j])
				{
					reduction_fraction.denominator = deno[1 - i];
					reduction_fraction.nomerator = nome[1 - j];
					return reduction_fraction;
				}
			}
		}
		reduction_fraction.denominator = 0; //non wrong_reduction
		return reduction_fraction;
	}

	Fraction reduction()
	{
		Fraction reduction_fraction;
		int t1 = denominator, t2 = nomerator;
		while (t1 != t2)
		{
			if (t1 > t2)
				t1 -= t2;
			else
				t2 -= t1;
		}
		reduction_fraction.denominator = denominator / t1;
		reduction_fraction.nomerator = nomerator / t1;
		return reduction_fraction;
	}

	bool is_equal(Fraction a, Fraction b)
	{
		if (a.reduction().denominator == b.reduction().denominator && a.reduction().nomerator == b.reduction().nomerator)
		{
			return true;
		}
		return false;
	}
};

int main(int argc, const char * argv[]) {

	Fraction mult_fraction;

	for (int i = 11; i <= 99; i++)
	{
		Fraction tmp;
		tmp.denominator = i;
		for (int j = 10; j < i; j++)
		{
			tmp.nomerator = j;
			if (j%10!=0 && tmp.wrong_reduction().denominator != 0 && tmp.wrong_reduction().nomerator != 0 && tmp.is_equal(tmp, tmp.wrong_reduction()))
			{
				mult_fraction.denominator *= tmp.reduction().denominator;
				mult_fraction.nomerator *= tmp.reduction().nomerator;
			}
		}
	}
	
	printf("%d\n", mult_fraction.reduction().denominator);

	return 0;
}
