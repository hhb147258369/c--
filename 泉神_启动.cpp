#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    int a[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<a[s.size()]+1<<'\n';
    }
}