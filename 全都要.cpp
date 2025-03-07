#include <bits/stdc++.h>
using namespace std;
#define i64 long long
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<i64>> dp(k+1, vector<i64>(n + 1, -(long long)(1e14)));
    for (int i = 1; i <= 6; i++)
    {
        dp[1][i] = a[i];
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int kk = max(i - 1, j - 6); kk <= min(j - 1, 6 * i - 6); kk++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][kk] + a[j]);
            }
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }

    i64 ans = LLONG_MIN;
    for (int i = k; i <= 6 * k; i++)
    {
        ans = max(ans, dp[k][i]);
    }
    cout << ans;
}