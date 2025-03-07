#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        if(n==1&&v[1]==-1)
        {
            cout<<"Bob\n";
            continue;
        }

        stack<int> pq;
        for(int i=1;i<=n;i++)
        {
            if(pq.empty())
            {
                pq.push(v[i]);
            }
            else
            {
            if(pq.top()==v[i])
            {
                if(v[i]==-1)
                {
                    pq.pop();
                    pq.push(1);
                }
                else
                {
                    pq.push(1);
                }
            }
            else
            {
                pq.push(v[i]);
            }
            }
        }
        vector<int> vp;
        while(!pq.empty())
        {
            vp.push_back(pq.top());
            pq.pop();
        }
        reverse(vp.begin(),vp.end());

        int l=0,r=0,tim=0;
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i]==0)
            {
                tim++;
            }
            else
            {
                
            }
        }







        /*for(auto gg:vp)
        {
            cout<<gg<<' ';
        }
        cout<<endl;



        /*if(vp.size()==3&&vp[0]==1&&vp[1]==-1&&vp[2]==1)
        {
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }*/
    }
}
