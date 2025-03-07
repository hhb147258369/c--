#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int a;
    cin>>a;//a>=n*(n-1)/2  a<n*(n+1)/2
    auto bf=[&](int p)->int{
        int L=0,R=10000000;
        while(L+1!=R)
        {
            int mid=(R+L)/2;
            if(a>=mid*(mid-1)/2)
            {
                L=mid;
            }
            else
            {
                R=mid;
            }
        }
        return L;
    };
    cout<<bf(a);
}