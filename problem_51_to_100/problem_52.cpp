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

bool is_permute(string s, string t)
{
    string tmp=s;
    do
    {
        if(tmp.compare(t)==0)
            return true;
        next_permutation(tmp.begin(), tmp.end());
    }while(tmp.compare(s)!=0);
    return false;
}

int main(int argc, const char * argv[]) {
    int i=1;
    bool check;
    
    while(1)
    {
        check=true;
        for(int j=1;j<=6;j++)
        {
            if(!is_permute(to_string(j*i),to_string(i)))
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            printf("%d\n", i);
            return 0;
        }
        i++;
    }
    return 0;
}
