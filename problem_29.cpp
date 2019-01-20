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

using namespace std;

int find_duplicate(int n)
{
    int tmp[601]={0};
    int minus=0;
    
    for(int i=1;i<=99;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(tmp[j*(i+1)]==1)
                minus++;
            else
                tmp[j*(i+1)]=1;
        }
    }
    
    return minus;
}

int main(int argc, const char * argv[]) {
    int sum=99*99;
    //six duplicate : 2, four duplicate : 3, two duplicate : 5,6,7,10
    sum-=(4*find_duplicate(2)+find_duplicate(4)+find_duplicate(6));
    printf("%d\n", sum);
    return 0;
}
