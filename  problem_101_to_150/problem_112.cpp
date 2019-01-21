#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, const char * argv[]) {
    
    int inorde=2178;
    int bouncy=19602;
    int tmp=21781;
    int is_increase;
    bool temp;
    
    while (1)
    {
        is_increase=-1;
        string tmp_string=to_string(tmp);
        temp=true;
            
        for(int i=0;i<tmp_string.size()-1;i++)
        {
            if(is_increase==-1)
            {
                if(stoi(tmp_string.substr(i,1))<stoi(tmp_string.substr(i+1,1)))
                {
                    is_increase=1;
                }
                else if(stoi(tmp_string.substr(i,1))>stoi(tmp_string.substr(i+1,1)))
                {
                    is_increase=0;
                }
            }
            else if(is_increase==1 && stoi(tmp_string.substr(i, 1))>stoi(tmp_string.substr(i+1,1)))
            {
                temp=false;
                break;
            }
            else if(is_increase==0 && stoi(tmp_string.substr(i, 1))<stoi(tmp_string.substr(i+1,1)))
            {
                temp=false;
                break;
            }
        }
        if(temp==false)
        {
            bouncy++;
        }
        else
        {
            inorde++;
        }
        
        if((double)bouncy/(bouncy+inorde)==0.99)
        {
            cout << tmp << endl;
            return 0;
        }
        
        tmp++;
    }
    
    return 0;
}
