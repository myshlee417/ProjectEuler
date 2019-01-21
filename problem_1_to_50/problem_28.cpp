//
//  main.cpp
//  practice
//
//  Created by User on 2018. 11. 7..
//  Copyright © 2018년 User. All rights reserved.
//
//21124

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#define NUM 1001

using namespace std;

int main(int argc, const char * argv[]) {
    int data[NUM][NUM]={0};
    int number_slot=1;
    int x = NUM/2;
    int y = NUM/2;
    
    data[x][y]=number_slot++;
    
    for(int i=1;i<=NUM/2;i++)
    {
        data[x][++y]=number_slot++;
        for(int j=0;j<2*i-1;j++)
        {
            data[--x][y]=number_slot++;
        }
        for(int j=0;j<=2*i-1;j++)
        {
            data[x][--y]=number_slot++;
        }
        for(int j=0;j<=2*i-1;j++)
        {
            data[++x][y]=number_slot++;
        }
        for(int j=0;j<=2*i-1;j++)
        {
            data[x][++y]=number_slot++;
        }
    }
    
    int sum=0;
    for(int i=0;i<NUM;i++)
    {
        sum+=data[i][i];
        sum+=data[NUM-i-1][i];
    }
    sum--;
    printf("%d\n", sum);
    
    return 0;
}
