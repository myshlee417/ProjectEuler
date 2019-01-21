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
#define NUM 10000000
using namespace std;

int my_max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

class BigInteger
{
public:
    vector<int> data;
    
    
    BigInteger()
    {
        data.clear();
    }
    
    BigInteger(vector<int> x)
    {
        data.clear();
        for (int i = 0; i < x.size(); i++)
        {
            data.push_back(x[i]);
        }
    }
    
    BigInteger(int x)
    {
        data.clear();
        int temp = x;
        while (temp != 0)
        {
            data.push_back(temp % 10);
            temp /= 10;
        }
    }
    
    void assign(BigInteger x)
    {
        data.clear();
        for (int i = 0; i < x.data.size(); i++)
        {
            data.push_back(x.data[i]);
        }
    }
    
    void assign(vector <int> x)
    {
        data.clear();
        for (int i = 0; i < x.size(); i++)
        {
            data.push_back(x[i]);
        }
    }
    
    BigInteger sum(BigInteger x, BigInteger y)
    {
        int up;
        BigInteger sol;
        if (x.data.size() > y.data.size()) {
            up = 0;
            for (int i = 0; i < y.data.size(); i++)
            {
                sol.data.push_back((x.data[i] + y.data[i] + up) % 10);
                up = (x.data[i] + y.data[i] + up) / 10;
            }
            for (int i = y.data.size(); i < x.data.size(); i++)
            {
                sol.data.push_back((x.data[i] + up) % 10);
                up = (x.data[i] + up) / 10;
            }
            while (up != 0)
            {
                sol.data.push_back(up % 10);
                up = up / 10;
            }
            return sol;
        }
        
        up = 0;
        for (int i = 0; i < x.data.size(); i++)
        {
            sol.data.push_back((x.data[i] + y.data[i] + up) % 10);
            up = (x.data[i] + y.data[i] + up) / 10;
        }
        for (int i = x.data.size(); i < y.data.size(); i++)
        {
            sol.data.push_back((y.data[i] + up) % 10);
            up = (y.data[i] + up) / 10;
        }
        while (up != 0)
        {
            sol.data.push_back(up % 10);
            up = up / 10;
        }
        return sol;
    }
    
    BigInteger mult_one(BigInteger x, int y)
    {
        int up = 0;
        BigInteger sol;
        for (int i = 0; i < x.data.size(); i++)
        {
            sol.data.push_back((x.data[i] * y + up) % 10);
            up = (x.data[i] * y + up) / 10;
        }
        while (up != 0)
        {
            sol.data.push_back(up % 10);
            up = up / 10;
        }
        return sol;
    }
    
    BigInteger mult_ten(BigInteger x, int y)
    {
        BigInteger sol;
        for (int i = 0; i<y; i++)
            sol.data.push_back(0);
        
        for (int i = 0; i < x.data.size(); i++)
        {
            sol.data.push_back(x.data[i]);
        }
        return sol;
    }
    
    BigInteger mult(BigInteger x, BigInteger y)
    {
        BigInteger sol;
        if (x.data.size() > y.data.size()) {
            
            for (int i = 0; i < y.data.size(); i++)
            {
                sol.assign(sum(sol, mult_ten(mult_one(x, y.data[i]), i)));
            }
            return sol;
        }
        
        for (int i = 0; i < x.data.size(); i++)
        {
            sol.assign(sum(sol, mult_ten(mult_one(y, x.data[i]), i)));
        }
        
        return sol;
    }
    
    int digit_sum()
    {
        int sol = 0;
        for (int i = 0; i < data.size(); i++)
            sol += data[i];
        return sol;
    }
    
    void print()
    {
        for (int i = 0; i < data.size(); i++)
            printf("%d", data[data.size() - i - 1]);
        printf("\n");
    }
};

int main(int argc, const char * argv[]) {
    BigInteger value(28433);
    BigInteger two(2);
    BigInteger one(1);
    
    for(int i=0;i<7830457;i++)
    {
        value.assign(value.mult(value,two));
        for(int j=10;j<value.data.size();j++)
        {
            value.data.pop_back();
        }
    }
    
    value.assign(value.sum(value,one));
    value.print();    
    return 0;
}
