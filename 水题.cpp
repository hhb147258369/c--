#include <bits/stdc++.h>
using namespace std;
int n, m, h;
pair<int, int> find(char c, vector<string> &v)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == c)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
int main()
{
    cin >> n >> m >> h;
    vector<string> v(n + 1);
    vector<vector<bool>> vis(n+5,vector<bool>(m+5,0));
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    auto [s1, s2] = find('*', v);
    auto [e1, e2] = find('%', v);

    auto cmp = [](array<int, 4> a, array<int, 4> b)
    {
        return a[2] > b[2];
    };

    priority_queue<array<int, 4>, vector<array<int, 4>>, decltype(cmp)> pq(cmp);

    pq.push({s1, s2, 0, 1}); // array[3]=1表示向下;0左，2右

    while (!pq.empty())
    {
        auto [x, y, z, k] = pq.top();
        pq.pop();
        if(!vis[x][y])
        {
            vis[x][y]=true;
        }
        else
        {
            continue;    
        }
        //cout<<x<<' '<<y;

        //cout<<endl;
        
        if (x==e1&&y==e2)
        {
            cout << z;
            return 0;
        }


        if (k == 0)
        {
            if (x + 1 <= n && (v[x + 1][y] == '.'||v[x + 1][y]=='%')) // 水流改为向下
            {
                pq.push({x + 1, y, z + 1, 1});
            }
            else if ((v[x][y-1] == '.'||v[x][y-1]=='%') && y - 1 >= 0)
            {
                pq.push({x, y - 1, z + 1, 0});
            }
        }
        else if (k == 2)
        {

            if (x + 1 <= n &&(v[x + 1][y] == '.'||v[x + 1][y]=='%')) // 水流改为向下
            {
                pq.push({x + 1, y, z + 1, 1});
            }
            else if ((v[x][y+1] == '.'||v[x][y+1]=='%')&& y + 1 < m)
            {
                pq.push({x, y + 1, z + 1, 2});
            }
        }
        else
        {
            if (x + 1 <= n && (v[x + 1][y] == '.'||v[x + 1][y]=='%')) // 水流改为向下
            {
                pq.push({x + 1, y, z + 1, 1});
            }
            else if (x + 1 <= n && v[x + 1][y] == '#' )
            {
                pq.push({x+1, y, z + h+1,1});
                
                if ((v[x][y-1] == '.'||v[x][y-1]=='%') && y - 1 >= 0)
                {
                    pq.push({x, y - 1, z + 1, 0});
                }
                if ((v[x][y+1] == '.'||v[x][y+1]=='%')&& y + 1 < m)
                {
                    pq.push({x, y + 1, z + 1, 2});
                }
            }
        }
    }
    cout << -1;
}