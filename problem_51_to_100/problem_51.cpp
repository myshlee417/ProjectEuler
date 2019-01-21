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

vector <int> digits[10];

bool is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int vector_to_int()
{
    int sol=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<digits[i].size();j++)
        {
            sol+=(int)pow(10,digits[i][j])*i;
        }
    }
    return sol;
}

bool check_prime_digit_rep(int i, int digit_num)
{
    int num=0;
    int changedigit[3];
    for(int j=0;j<3;j++)
    {
        changedigit[j]=digits[i][j];
    }
    for(int j=0;j<3;j++)
    {
        digits[i].pop_back();
    }
    
    int start=0;
    
    if(changedigit[2]==digit_num-1)
    {
        start=1;
    }
    
    for(int j=start;j<10;j++)
    {
        for(int k=0;k<3;k++)
        {
            digits[j].push_back(changedigit[k]);
        }
        if(is_prime(vector_to_int()))
        {
            num++;
        }
        for(int k=0;k<3;k++)
        {
            digits[j].pop_back();
        }
    }
    
    for(int k=0;k<3;k++)
    {
        digits[i].push_back(changedigit[k]);
    }
    
    if(num==8)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    
    int i=1101;
    int tmp;
    int digit_num;
    
    while(1)
    {
        if(is_prime(i))
        {
            for(int i=0;i<10;i++)
            {
                digits[i].clear();
            }
            digit_num=0;
            tmp=i;
            while(tmp!=0)
            {
                digits[tmp%10].push_back(digit_num++);
                tmp/=10;
            }
            for(int i=0;i<10;i++)
            {
                if(digits[i].size()==3 && check_prime_digit_rep(i,digit_num))
                {
                    printf("%d\n",vector_to_int());
                    return 0;
                }
            }
        }
        i++;
    }
    
    return 0;
}
