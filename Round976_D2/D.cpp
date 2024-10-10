#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct dsu
{
    vector<int> par;
    vector<int> sz;
    dsu(int n)
    {
        par.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
        sz.resize(n + 1, 1);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
    int Find(int e)
    {
        return e == par[e] ? e : par[e] = Find(par[e]);
    }
};

int main()
{
    int t, n, m, a, d, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> recStart(n + 1, vector<int>(11));
        vector<vector<int>> recEnd(n + 1, vector<int>(11));
        vector<vector<int>> dp(n + 1, vector<int>(11));
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> d >> k;
            recStart[a][d]++;
            recEnd[a + k * d][d]++;
        }
        dsu rec(n);
        for (int i = 1; i <= n; i++)
        {
            for (int di = 1; di <= 10; di++)
            {
                dp[i][di] = recStart[i][di] - recEnd[i][di];
                if (i <= di)
                    continue;
                if (dp[i - di][di])
                {
                    rec.Union(i, i - di);
                    dp[i][di] += dp[i - di][di];
                }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (rec.par[i] == i)
                res++;
        }
        cout << format("{}", res) << endl;
    }
}