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
#include <algorithm>
#include <string>
#define NUM 1000000
using namespace std;

bool is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int newvalue=9;
    int edge=5;
    int de=5;
    int nu=3;
    
    while(1)
    {
        for(int i=0;i<=3;i++)
        {
            newvalue+=(edge-1);
            de++;
            if(is_prime(newvalue))
            {
                nu++;
            }
        }
        
        if((double)nu/de<0.1)
        {
            printf("%d\n", edge);
            return 0;
        }
        
        edge+=2;
    }
    return 0;
}
