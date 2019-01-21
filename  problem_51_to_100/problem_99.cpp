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
    
    ifstream in("base_exp.txt");
    string input_str;
    int base, expo;
    double max=0.0;
    int max_index=0;
    
    for(int i=1;i<=1000;i++)
    {
        in >> input_str;
        for (int j=0;j<input_str.size();j++)
        {
            if (input_str.at(j) == ',')
            {
                base=stoi(input_str.substr(0,j));
                expo=stoi(input_str.substr(j+1,input_str.size()-j));
            }
        }
        
        if(max<(double)expo * log10(base))
        {
            max=(double)expo * log10(base);
            max_index=i;
        }
    }
    
    printf("%d\n", max_index);
    return 0;
}
