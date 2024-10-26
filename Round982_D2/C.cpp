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
        map<ll, vector<int>> rec;
        vector<ll> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            if (i == 1)
                continue;
            rec[nums[i] + i - 1LL].push_back(i);
        }
        // ll len = n;
        ll res = n;
        map<ll, ll> memo;
        auto dfs = [&](auto &&dfs, ll len) -> ll
        {
            if (memo.count(len))
                return memo[len];
            ll &ret = memo[len];
            for (auto i : rec[len])
            {
                ret = max(dfs(dfs, len + i - 1), ret);
            }
            ret = max(ret, len);
            res = max(res, ret);
            return ret;
        };
        dfs(dfs, n);
        cout << res << endl;
    }
}