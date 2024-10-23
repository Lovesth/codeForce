#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> nums(n + 9);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.begin() + n);
        if (nums[0] >= k || 1LL * n * nums[0] >= k)
        {
            cout << k << endl;
            continue;
        }
        ll res = 0;
        ll curS = 0;
        int pos = 0;
        while (1)
        {
            while (nums[pos] <= curS)
            {
                res++;
                pos++;
            }
            ll tmp = 1LL * (nums[pos] - curS) * (n - pos);
            if (tmp >= k)
            {
                res += k;
                break;
            }
            k -= tmp;
            res += tmp;
            curS = nums[pos];
        }
        cout << res << endl;
    }
}