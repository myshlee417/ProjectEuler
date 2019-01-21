#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 100

using namespace std;

int HCF(int n, int m)
{
    while(n!=m)
    {
        if(n>m)
            n-=m;
        else
            m-=n;
    }
    return n;
}

int main(int argc, const char * argv[]) {
    
    int start,end;
    int num=0;
    
    for(int i=4;i<=12000;i++)
    {
        start=(int)ceil(i/3.0);
        end=i/2;
        for(int j=start;j<=end;j++)
        {
            if(HCF(i,j)==1)
                num++;
        }
    }
    printf("%d\n",num);
    return 0;
}
