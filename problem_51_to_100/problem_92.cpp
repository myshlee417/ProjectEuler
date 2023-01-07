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
#define NUM 10000000
using namespace std;

int main(int argc, const char * argv[]) {
    int tmp, tmp2;
    int num=0;
    for(int i=1;i<NUM;i++)
    {
        tmp=i;
        while(tmp!=1 && tmp!=89)
        {
            tmp2=0;
            while(tmp!=0)
            {
                tmp2+=pow(tmp%10,2);
                tmp/=10;
            }
            tmp=tmp2;
        }
        if(tmp==89)
        {
            num++;
        }
    }
    
    printf("%d\n", num);
    return 0;
}
