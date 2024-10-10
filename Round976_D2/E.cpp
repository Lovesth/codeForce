#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll MOD = 1e9 + 7;
ll dp[10][10][2][2]{};

ll fastPow(ll x, ll n, ll m)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

ll inv = fastPow(1e4, MOD - 2, MOD);

void transfer(ll a, ll p)
{
    ll p1 = (p * inv) % MOD;
    ll negp1 = (MOD + 1 - p1) % MOD;
    vector<int> bits(10);
    int pos = 0;
    while (a)
    {
        bits[pos++] = a & 1;
        a /= 2;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ll tmp[2][2];
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    tmp[k][l] = (dp[i][j][k][l] * negp1 + dp[i][j][k ^ bits[i]][l ^ bits[j]] * p1) % MOD;
                }
            }
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    dp[i][j][k][l] = tmp[k][l];
                }
            }
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> nums(n + 1);
        vector<ll> pros(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> pros[i];
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[i][j][0][0] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            transfer(nums[i], pros[i]);
        }
        ll res = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                res = (res + (1LL << (i + j)) * dp[i][j][1][1]) % MOD;
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        dp[i][j][k][l] = 0;
                    }
                }
            }
        }
        cout << res << endl;
    }
}