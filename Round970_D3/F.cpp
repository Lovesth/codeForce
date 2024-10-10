#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

ll qPow(ll a, ll p, ll m)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
        {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        p /= 2;
    }
    return res % m;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> data(n + 1);
        ll P = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> data[i];
            P += data[i] * data[i - 1];
            P %= MOD;
            data[i] += data[i - 1];
            data[i] %= MOD;
        }
        ll Q = ll(n) * (n - 1) / 2;
        Q %= MOD;
        Q = qPow(Q, MOD-2, MOD);
        cout << (P*Q)%MOD << endl;
    }
}