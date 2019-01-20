#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
#define NUM 100

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
    
    int convergent[101];
    BigInteger num(8);
    BigInteger tmp(3);
    
    convergent[0]=2;
    for(int i=1;i<=100;i++)
    {
        if(i%3==2)
            convergent[i]=(i+1)/3*2;
        else
            convergent[i]=1;
    }
    
    for(int i=4;i<=NUM;i++)
    {
        BigInteger temp(convergent[i-1]);
        temp.assign(temp.mult(num,temp));
        temp.assign(temp.sum(temp,tmp));
        tmp.assign(num);
        num.assign(temp);
    }
    cout << num.digit_sum() << endl;
    return 0;
}
