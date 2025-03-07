#include<bits/stdc++.h>
using namespace std;
//#define int long long
int sqrt_int(int n) {
    if (n <= 1) return n;
    int q = n;
    while (q > (n/q)) q = (q + n / q) / 2;
    return q;
}
int main()
{
    double p=6399999999999999;
    cout<<(long long)p;
    cout<<(int)sqrt(p);
}
