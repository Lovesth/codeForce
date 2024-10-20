#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll qpower(ll a, ll n, ll MOD = MOD)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> rec(n + 10);
        int tmp;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            rec[tmp]++;
        }
        for (int i = 0; i <= n; i++)
        {
            if (rec[i] == 0)
            {
                tmp = i;
                break;
            }
        }
        ll res = 0;
        int s = 0;
        ll mulRes = 1;
        for (int i = 0; i < tmp; i++)
        {
            s += rec[i];
            if (i == 0)
            {
                mulRes = mulRes * (qpower(2, s) - 1) % MOD;
                continue;
            }
            res = (res + mulRes * qpower(2, n - s) % MOD) % MOD;
            mulRes = mulRes * (qpower(2, s) - 1) % MOD;
        }
        cout << res << endl;
    }
}