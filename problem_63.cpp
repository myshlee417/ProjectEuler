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

int main(int argc, const char * argv[]) {
    double tmp;
    int sum=0;
    
    for(int n=1;pow(10,(double)(n-1)/n)<=9;n++)
    {
        int first=pow(10,(double)(n-1)/n);
        if(pow(10,(double)(n-1)/n)!=(int)pow(10,(double)(n-1)/n))
        {
            first++;
        }
        sum+=9-first+1;
    }
    printf("%d\n", sum);
    
    
    return 0;
}
