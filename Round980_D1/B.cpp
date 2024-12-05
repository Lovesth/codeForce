#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> points(n + 1);
        vector<ll> b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> points[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        vector<vector<pair<ll, ll>>> edges(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
            {
                edges[i].push_back({0, i - 1});
            }
            if (b[i] > i)
            {
                edges[i].push_back({points[i], b[i]});
            }
        }
        vector<ll> dis(n + 1, LLONG_MAX);
        dis[1] = 0;
        vector<int> vis(n + 1);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto edge = pq.top();
            pq.pop();
            if (vis[edge.second])
                continue;
            vis[edge.second] = 1;
            for (auto &e : edges[edge.second])
            {
                if (dis[e.second] > dis[edge.second] + e.first)
                {
                    dis[e.second] = dis[edge.second] + e.first;
                    pq.push({dis[e.second], e.second});
                }
            }
        }

        partial_sum(points.begin(), points.end(), points.begin());
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = max(res, points[i] - dis[i]);
        }
        cout << res << endl;
    }
}