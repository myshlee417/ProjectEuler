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
    
    int sum=0;
    int combination;
    
    for(int n=1;n<=100;n++)
    {
        combination=n;
        for(int r=1;r<=n;r++)
        {
            if(combination>=NUM)
            {
                sum+=n-2*r+1;
                break;
            }
            
            combination*=(n-r);
            combination/=(r+1);
        }
    }
    printf("%d\n", sum);
    
    return 0;
}
