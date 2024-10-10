#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    int n, m, tmp;
    vector<int> vis(2e5+10);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        // vector<int> record(n);
        int li, maxVal = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> li;
            for(int i=0; i<li+5; i++){
                vis[i] = 0;
            }
            for(int i=0; i<li; i++){
                cin >> tmp;
                if(tmp<li+5)
                    vis[tmp] = 1;
            }
            int mex = 0;
            while(vis[mex]){
                mex++;
            }
            mex++;
            while(vis[mex]){
                mex++;
            }
            maxVal = max(maxVal, mex);
        }
        ll res = 0;
        if (m <= maxVal)
        {
            res = ll(m + 1) * (maxVal);
        }
        else
        {
            res = ll(maxVal + 1) * maxVal + ll(ll(m) - maxVal) * (ll(maxVal) + 1 + m) / 2;
        }
        cout << res << endl;
    }
}