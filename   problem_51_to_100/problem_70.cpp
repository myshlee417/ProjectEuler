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
#define NUM 10000000

using namespace std;

int phi(int n)
{
    int phi=n;
    int tmp=n;
    int index=2;
    bool check=true;
    
    while(tmp!=1)
    {
        if(tmp%index==0 && check)
        {
            check=false;
            tmp/=index;
            phi/=index;
            phi*=(index-1);
        }
        else if(tmp%index==0)
        {
            tmp/=index;
        }
        else
        {
            index++;
            check=true;
        }
    }
    
    return phi;
    
}

bool is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    double min_data=NUM;
    double tmp;
    int min_index=0;
    int phi_value;
    string temp1,temp2,temp3;
    vector<int> primes;
    
    for(int i=2;i<=NUM-1;i++)
    {
        if(is_prime(i))
        {
            primes.push_back(i);
        }
    }
        
    for(int j=0;j<primes.size();j++)
    {
        if(primes[j]>=2000 && primes[j]<=5000)
        {
            for(int k=j;k<primes.size();k++)
            {
                if(primes[k]>=5000 ||  primes[k]<=2000)
                    break;
                if(primes[k]*primes[j]>=NUM)
                    break;
                
                int i=primes[j]*primes[k];
                
                phi_value=phi(i);
                temp1=to_string(phi_value);
                temp2=to_string(phi_value);
                temp3=to_string(i);
                next_permutation(temp2.begin(),temp2.end());
                
                while(temp1.compare(temp2)!=0)
                {
                    if(temp2.compare(temp3)==0)
                    {
                        break;
                    }
                    next_permutation(temp2.begin(),temp2.end());
                }
                
                
                if(temp1.compare(temp2)!=0)
                {
                    tmp=(double)i/phi_value;
                    if(tmp<min_data)
                    {
                        min_data=tmp;
                        min_index=i;
                    }
                }
            }
        }
    }
    
    cout<< min_index << endl;
    return 0;
}
