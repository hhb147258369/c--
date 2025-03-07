#include "hhb.h"
#include<bits/stdc++.h>
using namespace std;
string Big_add(string s1,string s2)
{
    string s;
    int i=s1.size()-1,j=s2.size()-1;
    int sum=0;
    while(i>=0||j>=0||sum>0)
    {
        if(i>=0)
        {
            sum+=(s1[i--]-'0');
        }
        if(j>=0)
        {
            sum+=(s2[j--]-'0');
        }
        int array=sum%10;
        sum/=10;
        s+=(array+'0');
    }
    reverse(s.begin(),s.end());
    return s;
}
