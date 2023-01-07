#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream in("matrix.txt");
    string input_str;
    int data[80][80];
    int least_route[80][80];
    
    for(int i=0;i<80;i++)
    {
        in >> input_str;
        int start=0;
        int num=0;
        
        for(int j=0;j<input_str.size();j++)
        {
            if(input_str.at(j)==',')
            {
                data[i][num++]=stoi(input_str.substr(start,start-j));
                start=j+1;
            }
        }
        data[i][79]=stoi(input_str.substr(start,input_str.size()-start));
    }
    
    for(int i=0;i<80;i++)
    {
        least_route[i][0]=data[i][0];
    }
    
    for(int j=1;j<80;j++)
    {
        for(int i=0;i<80;i++)
        {
            least_route[i][j]=least_route[i][j-1]+data[i][j];
        }
        for(int i=0;i<80;i++)
        {
            int temp=least_route[i][j];
            for(int k=i-1;k>=0;k--)
            {
                temp+=data[k][j];
                if(temp<least_route[k][j])
                {
                    least_route[k][j]=temp;
                }
                else
                {
                    break;
                }
            }
            
            temp=least_route[i][j];
            for(int k=i+1;k<80;k++)
            {
                temp+=data[k][j];
                if(temp<least_route[k][j])
                {
                    least_route[k][j]=temp;
                }
                else
                {
                    break;
                }
            }
            
        }
    }
    
    int sol=INT_MAX;
    
    for(int i=0;i<80;i++)
    {
        if(least_route[i][79]<sol)
        {
            sol=least_route[i][79];
        }
    }
    
    cout << sol << endl;
    
    return 0;
}

