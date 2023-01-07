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

bool is_palidrome(string tmp)
{
    
    for(int i=0;i<tmp.size()/2;i++)
    {
        if(tmp.at(i)!=tmp.at(tmp.size()-1-i))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    string tmp;
    string tmp2;
    string rvs;
    bool check;
    int sum=0;
    int up;
    
    for(int i=1;i<10000;i++)
    {
        check=true;
        tmp=to_string(i);
        for(int j=0;j<50;j++)
        {
            rvs=tmp;
            tmp2="";
            reverse(rvs.begin(),rvs.end());
            up=0;
            for(int i=0;i<tmp.size();i++)
            {
                tmp2 = to_string((tmp.at(i)-'0'+rvs.at(i)-'0'+up)%10) + tmp2;
                if(tmp.at(i)-'0'+rvs.at(i)-'0'+up>=10)
                {
                    up=1;
                }
                else
                {
                    up=0;
                }
            }
            if(up==1)
            {
                tmp2 = "1"+tmp2;
            }
            tmp=tmp2;
            
            if(is_palidrome(tmp))
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    
    return 0;
}
