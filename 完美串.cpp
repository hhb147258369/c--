#include <bits/stdc++.h>
using namespace std;
vector<int> word(26, 0);
signed main()
{
    string s;
    cin >> s;
    int sum = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        word[s[i] - 'a']++;
    }

    vector<pair<char, int>> v;
    string s_pre;

    int num = 0;
    int Max = 0;
    for (int i = 0; i < 26; i++)
    {
        Max = max(Max, word[i]);
    }
    for (int i = 0; i < 26; i++)
    {
        if (word[i] == Max)
            num++;
    }
    int len;
    if (Max == 1)
    {
        len = sum;
        cout<<len<<'\n';
        cout<<s;
        return 0;
    }
    else
        len = (sum - num * Max) / (Max - 1);

    for (int i = 0; i <= 25; i++)
    {
        if (word[i] > 0)
            v.push_back({('a' + i), word[i]});
    }

    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b)
         { return a.second > b.second; });

    for (int i = 0; i < num; i++)
        s_pre += v[i].first;

    string erp;
    for (int i = num; i < v.size(); i++)
    {
        for (int j = 1; j <= v[i].second; j++)
        {
            erp += v[i].first;
        }
    }

    string ans(s.size(),'A');
    int rem=s.size()-num*Max-len*(Max-1);
    
    //num-1  len+1  num  len+1+*2num   0+(len+1)*rem 0+(len+1)*rem+len     +(len+1+num)
    int i=0;
   // cout<<len<<num<<rem;
    while(i<sum)
    {
        for(int j=0;j<num;j++)
        {
            ans[i+j]=s_pre[j];
        }
        if(i<(len+1+num)*rem)
        {
            i+=len+1+num;
        }
        else
        {
            i+=len+num;
        }
    }
    //cout<<ans;
    int p=0;
    bool flag=0;
    if(erp.size()>0)
    for(int i=0;i<len+1;i++)
    {
        int j=num+i;
        while(j<sum)
        {
            /*cout<<j<<' ';
            cout<<p<<' ';*/
            ans[j]=erp[p];
            p++;
            if(j<(len+1+num)*rem)
            {
                j+=len+1+num;
            }
            else
            {
                j+=len+num;
            }
            if(p>=erp.size())
        {
            flag=1;
            break;
        }
        }
        if(flag) break;
    }
    //cout<<erp.size();
    cout<<len+num<<'\n';
    cout<<ans;
}   