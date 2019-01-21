#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

using namespace std;

int cubic[37]={0};
int pyramic[37]={0};

void cubic_recursion(int n, int recur_num)
{
    if(recur_num==0)
    {
        cubic[n]++;
        return ;
    }
    for(int i=1;i<=6;i++)
        cubic_recursion(n+i, recur_num-1);
}

void pyramic_recursion(int n, int recur_num)
{
    if(recur_num==0)
    {
        pyramic[n]++;
        return ;
    }
    for(int i=1;i<=4;i++)
        pyramic_recursion(n+i, recur_num-1);
}

int main(int argc, const char * argv[]) {
    
    cubic_recursion(0,6);
    
    pyramic_recursion(0,9);
    
    
    unsigned long long total=0;
    double sol;
    unsigned long long num=0;
    
    total=pow(6,6)*pow(4,9);
    
    for(int i=0;i<=36;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            num+=pyramic[i]*cubic[j];
        }
    }
    sol=num/(double)total;
    cout.precision(7);
    cout << sol << endl;
    
    return 0;
}
