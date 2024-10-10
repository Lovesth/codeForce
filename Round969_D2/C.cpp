#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        int d = gcd(a, b);
        vector<int> nums(n);
        for (auto &num : nums)
        {
            cin >> num;
            num %= d;
        }
        sort(nums.begin(), nums.end());
        int res = nums[n - 1] - nums[0];
        for(int i=1; i<n; i++){
            res = min(res, (nums[i-1]+d-nums[i]));
        }
        cout << res << endl;
    }
}