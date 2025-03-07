#include<bits/stdc++.h>
using namespace std;
#define i64 long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        i64 n;
        cin>>n;
        if(n==1)
        {
            cout<<0<<' '<<0<<'\n';
            continue;
        }
        n--;
        i64 q=sqrt(n);
        int len=n-q*q;

        int x,y;
        if(q%2==0)
        {
            x=-(q/2),y=-(q/2);
            if(len<=q)
            {
                y+=len;
            }
            else
            {
                y=q/2;
                x+=(len-q);
            }
        }
        else
        {
            x=(q+1)/2,y=x-1;
            if(len<=q)
            {
                y-=len;
            }
            else
            {
                y=(-y-1);
                x-=(len-q);
            }
        }
        cout<<x<<' '<<y<<'\n';
    }
}