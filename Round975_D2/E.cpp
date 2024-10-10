#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        unordered_map<int, vector<int>> edges;
        int u, v;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        vector<int> maxDeepth(n + 1);
        vector<int> rec(n+2);
        auto dfs = [&](auto &&dfs, int curDeep, int curNode) -> void
        {
            rec[curDeep]++;
            maxDeepth[curNode] = curDeep;
            for (auto &node : edges[curNode])
            {
                if (!vis[node])
                {
                    vis[node] = 1;
                    dfs(dfs, curDeep + 1, node);
                    maxDeepth[curNode] = max(maxDeepth[curNode], maxDeepth[node]);
                }
            }
            rec[maxDeepth[curNode]+1]--;
        };
        dfs(dfs, 1, 1);
        int res = 0;
        for(int d=1; d<=n; d++){
            rec[d] += rec[d-1];
            res = max(res, rec[d]);
        }
        cout << n-res << endl;
    }
}