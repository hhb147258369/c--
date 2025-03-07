#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e9 + 7;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0)); // 0表示其他 1表示c 2表示n
    dp[1][0] = 25;                                     // 无c,n
    dp[1][1] = 1;                                                                                            //n->c
    dp[1][2] = 0;                                     // 有c -> n
    for (int i = 2; i <= n; i++)
    {
        dp[i][0]=dp[i-1][0]*25;
        dp[i][0]%=N;
        dp[i][1]=dp[i-1][0]+dp[i-1][1]*25;
        dp[i][1]%=N;
        dp[i][2]=dp[i-1][2]*26+dp[i-1][1];
        dp[i][2]%=N;
    }
    cout<<dp[n][2];
}