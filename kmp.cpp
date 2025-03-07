#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="dasdaafwffaassaassaaaaddwfewv";
    string t="aassaassaaa";

//求最长公共前后缀
    vector<int> next(11,0);//表示[0,i]的最长公共前后缀（长度）
    int i=0,j=1;    
    next[0]=0;
    while(i<s.size()-1&&j<s.size())//j不回退
    {
        if(t[i]==t[j])
        {
            next[j]=i+1;
            i++;
            j++;
        }
        else if(i!=0)
        {
           i=next[i-1];
        }
        else if(i==0)
        {
            j++;
        }
    }

//匹配
    int x=0,y=0;
    while (x<s.size()&&y<t.size())//x不回退
    {
        if(s[x]==t[y])
        {
            x++;
            y++;
        }
        else if(y!=0)
        {
            y=next[y-1];
        }
        else if(y==0)
        {
            x++;
        }
        if(y==t.size())
        {
            cout<<"RES";
            return 0;
        }
    }
    cout<<"NO";
}