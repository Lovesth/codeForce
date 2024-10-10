#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 200100;

ll n, m, a[maxn], f[maxn];
pii b[maxn];
bool vis[maxn];
vector<int> G[maxn];

inline ll calc(ll l, ll r)
{
    return (l + r) * (r - l + 1) / 2;
}

void solve()
{
    scanf("%lld%lld", &n, &m);
    ll t = -1, ans = 0, k = 0;
    for (int i = 1, l; i <= n; ++i)
    {
        scanf("%d", &l);
        for (int j = 1; j <= l; ++j)
        {
            scanf("%lld", &a[j]);
            if (a[j] < maxn)
            {
                vis[a[j]] = 1;
            }
        }
        ll u = 0;
        while (vis[u])
        {
            ++u;
        }
        t = max(t, u);
        ll v = u;
        vis[u] = 1;
        while (vis[v])
        {
            ++v;
        }
        b[i] = mkp(u, v);
        k = max(k, v);
        vis[u] = 0;
        for (int j = 1; j <= l; ++j)
        {
            if (a[j] < maxn)
            {
                vis[a[j]] = 0;
            }
        }
    }
    for (int i = 0; i <= k; ++i)
    {
        vector<int>().swap(G[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        G[b[i].fst].pb(b[i].scd);
    }
    for (int u = k; ~u; --u)
    {
        f[u] = u;
        for (int v : G[u])
        {
            f[u] = max(f[u], f[v]);
        }
        if ((int)G[u].size() >= 2)
        {
            t = max(t, f[u]);
        }
    }
    for (int i = 0; i <= min(k, m); ++i)
    {
        ans += max(t, f[i]);
    }
    if (k < m)
    {
        ans += calc(k + 1, m);
    }
    printf("%lld\n", ans);
}

int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}