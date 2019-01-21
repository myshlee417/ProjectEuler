//
//  main.cpp
//  practice
//
//  Created by User on 2018. 11. 7..
//  Copyright © 2018년 User. All rights reserved.
//
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#define NUM 1000000

using namespace std;

bool is_prime(int n)
{
    if(n<=1)
        return false;
    
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector <int> prime;
    vector <int> prime_sum;
    int tmp=0;
    int max=0;
    int max_index=0;
    
    for(int i=2;i<NUM;i++)
    {
        if(is_prime(i))
        {
            prime.push_back(i);
            tmp=i;
        }
    }
    
    for(int i=0;i<prime.size();i++)
    {
        tmp+=prime[i];
        prime_sum.push_back(tmp);
    }
    
    for(int i=0;i<prime_sum.size();i++)
    {
        for(int j=i+1;j<prime_sum.size();j++)
        {
            tmp=prime_sum[j]-prime_sum[i];
            if(tmp>=NUM)
                break;
            if(is_prime(tmp) && (j-i)>max_index)
            {
                max=tmp;
                max_index=j-i;
            }
        }
    }
    printf("%d\n",max);
}
