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
        partial_sum(nums.begin()+1, nums.end(), nums.begin()+1);
        vector<ll> dp(n + 2);
        ll res = 0;
        for (int i = n-1; i >= 0; i--)
        {
            int pos = upper_bound(nums.begin() + i, nums.end(), nums[i] + x) - nums.begin();
            dp[i] = pos - i - 1 + dp[pos];
            res += dp[i];
        }//
        cout << res << endl;
    }
    return 0;
}