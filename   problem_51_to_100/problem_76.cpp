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

using namespace std;

int main(int argc, const char * argv[]) {
    
    int data[101][101]={0};
    
    for(int i=1;i<=100;i++)
    {
        data[0][i]=1;
        data[1][i]=1;
        data[i][1]=1;
    }
    
    for(int i=2;i<=100;i++) //i:col, j:row
    {
        for(int j=2;j<=100;j++)
        {
            if(i>j)
            {
                data[j][i]=data[j][i-1];
            }
            else
            {
                data[j][i]=data[j-i][i]+data[j][i-1];
            }
        }
    }
    printf("%d\n",data[100][100]-1);
    
    return 0;
}
