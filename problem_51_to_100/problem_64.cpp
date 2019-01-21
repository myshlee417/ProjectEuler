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

class nu_de_an
{
public:
    int nu;
    int de;
    int an;
};

int main(int argc, const char * argv[]) {
    
    int num=0;
    
    for(int i=1;i<=10000;i++)
    {
        if((int)sqrt(i)*(int)sqrt(i)!=i)
        {
            int nu=0;
            int de=1;
            int a0=(int)sqrt(i);
            int an=a0;
            bool check=true;
            
            vector <nu_de_an> data;
            nu_de_an  new_data;
            
            while(check)
            {
                nu=de*an-nu;
                de=(i-nu*nu)/de;
                an=(a0+nu)/de;
                for(int i=0;i<data.size();i++)
                {
                    if(data[i].nu==nu && data[i].de==de && data[i].an==an)
                    {
                        check=false;
                        break;
                    }
                }
                if(check)
                {
                    new_data.nu=nu;
                    new_data.de=de;
                    new_data.an=an;
                    data.push_back(new_data);
                }
            }
            
            if(data.size()%2==1)
            {
                num++;
            }
        }
    }
    
    cout << num << endl;
    
    return 0;
}

