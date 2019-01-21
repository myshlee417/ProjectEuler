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

unsigned long long num_relative(int n)
{
    unsigned long long tmp=n;
    int divide=2;
    bool check=true;
    unsigned long long sol=n;
    while(tmp!=1)
    {
        if(tmp%divide==0)
        {
            if(check)
            {
                sol=sol/divide*(divide-1);
                check=false;
            }
            tmp/=divide;
            continue;
        }
        divide++;
        check=true;
    }
    //printf("%d\n", sol);
    return sol;
}

int main(int argc, const char * argv[]) {
    double max=0,tmp;
    int index;
    
    for(int i=NUM;i>=2;i--)
    {
        tmp=i/(double)num_relative(i);
        if(tmp>max)
        {
            max=tmp;
            index=i;
        }
      printf("%d\n",i);
    }
    printf("%d\n", index);
    
    return 0;
}
