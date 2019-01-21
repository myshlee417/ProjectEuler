#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int my_min(int x, int y)
{
    if(x<y)
        return x;
    return y;
}

int main(int argc, const char * argv[]) {
    
    ifstream in("matrix.txt");
    string input_str;
    int start,end;
    int matrix[80][80];
    int min_sum[80][80]={0};
    int temp;
    
    for(int j=0;j<80;j++)
    {
        in >> input_str;
        start=0;
        temp=0;
        for (int i = 0; i < input_str.size(); i++)
        {
            if (input_str.at(i) == ',' || i==input_str.size()-1)
            {
                end = i-1;
                if(i==input_str.size()-1)
                    end++;
                matrix[j][temp] = stoi(input_str.substr(start,end-start+1));
                start = i+1;
                temp++;
            }
        }
    }
    
    min_sum[0][0]=matrix[0][0];
    
    for(int j=1;j<80;j++)
    {
        min_sum[0][j]=min_sum[0][j-1]+matrix[0][j];
        min_sum[j][0]=min_sum[j-1][0]+matrix[j][0];
    }
    
    for(int i=1;i<80;i++)
    {
        for(int j=1;j<80;j++)
        {
            min_sum[i][j]=my_min(min_sum[i][j-1],min_sum[i-1][j])+matrix[i][j];
        }
    }
    printf("%d\n",min_sum[79][79]);
    
    return 0;
}

