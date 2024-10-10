#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        vector<ll> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        vector<ll> memo(n + 1, -1);
        auto solve = [&](auto &&solve, int pos)
        {
            if (pos > n)
                return 0ll;
            if (memo[pos] != -1)
            {
                return memo[pos];
            }
            ll s = 0;
            int i = pos;
            for (; i <= n; i++)
            {
                s += nums[i];
                if (s > x)
                {
                    memo[pos] = i - pos + solve(solve, i + 1);
                    break;
                }
            }
            if (i == n + 1)
            {
                for (int j = pos; j <= n; j++)
                {
                    memo[j] = i - j;
                }
            }
            return memo[pos];
        };
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += solve(solve, i);
        }
        cout << res << endl;
    }
}