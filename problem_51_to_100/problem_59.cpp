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
    
    ifstream in("cipher.txt");
    string input_str;
    int start=0,end;
    vector <int> data;
    bool check;
    int key[3]={0};
    int temp;
    int sum;
    
    in >> input_str;
    
    for (int i = 0; i < input_str.size(); i++)
    {
        if (input_str.at(i) == ',')
        {
            end = i-1;
            data.push_back(stoi(input_str.substr(start,end-start+1)));
            start=i+1;
        }
    }
    end=input_str.size()-1;
    data.push_back(stoi(input_str.substr(start,end-start+1)));
    
    for(int i=97;i<=122;i++)
    {
        for(int j=97;j<=122;j++)
        {
            for(int k=97;k<=122;k++)
            {
                check=true;
                key[0]=i;
                key[1]=j;
                key[2]=k;
                sum=0;
                
                for(int n=0;n<data.size();n++)
                {
                    temp=data[n]^key[n%3];
                    if(!((temp>='0' && temp<='9') ||
                       (temp>='A' && temp<='Z') ||
                       (temp>='a' && temp<='z') ||
                       (temp==' ' || temp==',' || temp=='.' || temp=='?'
                        || temp=='!' || temp==';' || temp=='-' || temp=='/'
                        || temp=='(' || temp==')' || temp=='\''))) //modify
                    {
                        check=false;
                        break;
                    }
                    sum+=temp;
                }
                if(check)
                {
                    printf("%c%c%c\n",key[0],key[1],key[2]);
                    printf("%d\n", sum);
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
