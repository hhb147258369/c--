#include<bits/stdc++.h>
using namespace std;
int lcp(string& A,string& B)
{
    int i=0;
    while(i<A.size()&&i<B.size())
    {
        if(A[i]==B[i])
        {
            i++;
        }
    }
    return i;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int max_len=v[0].size();;
    int num=v[0].size();
    for(int i=1;i<n;i++)
    {
        num+=lcp(v[i],v[i-1]);
        max_len=max((int)v[i].size(),max_len);
    }
    cout<<num*2-max_len;
}
