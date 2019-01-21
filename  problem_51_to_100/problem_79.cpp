//
//  main.cpp
//  practice
//
//  Created by User on 2018. 11. 7..
//  Copyright © 2018년 User. All rights reserved.
//
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream in("keylog.txt");
    int input[50];
    int tmp[3];
    int temp;
    vector <int> prev[10];
    int prev_num[10]={0};
    
    for(int i=0;i<50;i++)
        in >> input[i];

    for(int i=0;i<50;i++)
    {
        temp=input[i];
        for(int j=0;j<3;j++)
        {
            tmp[j]=temp%10;
            temp/=10;
        }
        if(find(prev[tmp[1]].begin(),prev[tmp[1]].end(),tmp[2])==prev[tmp[1]].end())
        {
            prev[tmp[1]].push_back(tmp[2]);
            sort(prev[tmp[1]].begin(),prev[tmp[1]].end());
        }
        if(find(prev[tmp[0]].begin(),prev[tmp[0]].end(),tmp[1])==prev[tmp[0]].end())
        {
            prev[tmp[0]].push_back(tmp[1]);
            sort(prev[tmp[0]].begin(),prev[tmp[0]].end());
        }
        if(find(prev[tmp[0]].begin(),prev[tmp[0]].end(),tmp[2])==prev[tmp[0]].end())
        {
            prev[tmp[0]].push_back(tmp[2]);
            sort(prev[tmp[0]].begin(),prev[tmp[0]].end());
        }
    }
    
    for(int i=0;i<10;i++)
    {
        printf("%d : ",i);
        for(int j=0;j<prev[i].size();j++)
        {
            prev_num[prev[i][j]]++;
            printf("%d ", prev[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

