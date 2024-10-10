#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll> &nums, int l, int r, ll s)
{
    int n = nums.size() - 1;
    int lround = (l - 1) / n + 1;
    int rround = (r - 1) / n + 1;
    int lPos = l % n;
    int rPos = r % n;
    if (lPos == 0)
        lPos = n;
    if (rPos == 0)
        rPos = n;
    ll lNum = 0, rNum = 0, res = ll(rround - lround - 1) * s;
    lround = (lround % n == 0 ? n : lround % n);
    rround = (rround % n == 0 ? n : rround % n);

    if (lPos > n - lround + 1)
    {
        lNum = nums[0 + lround - 1] - nums[0 + lround - (n - lPos + 1) - 1];
        // lNum = accumulate(nums.begin() + lround-(n-lPos+1), nums.begin() + lround, 0LL);
    }
    else
    {
        lNum = nums[0 + lround - 1] - nums[0];
        // lNum = accumulate(nums.begin() + 1, nums.begin() + lround, 0LL);
        lNum += nums[n] - nums[n - (n - lPos - lround + 2)];
        // lNum = accumulate(nums.end() - (n - lPos - lround + 2), nums.end(), lNum);
    }
    if (rPos <= n - rround + 1)
    {
        rNum = nums[0 + rround + rPos - 1] - nums[rround - 1];
        // rNum = accumulate(nums.begin() + rround, nums.begin() + rround + rPos, 0LL);
    }
    else
    {
        rNum = s - (nums[rround - 1] - nums[rround - (n - rPos) - 1]);
        // rNum = s - accumulate(nums.begin() + rround - (n - rPos), nums.begin() + rround, 0LL);
    }
    return rNum + lNum + res;
}

int main()
{
    int t, n, q, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        int tag1 = n;
        int tag2 = q;
        vector<ll> nums(n + 1);
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            s += nums[i];
            nums[i] = nums[i] + nums[i - 1];
        }
        while (q--)
        {
            cin >> l >> r;
            if (tag1 == 200000 && tag2 == 200000)
            {
                cout << "-------------------" << endl;
                cout << l << " " << r << endl;
                cout << "-------------------" << endl;
                // cout << solve(nums, r, l, s) << endl;
                // continue;
            }

            cout << solve(nums, min(l,r), max(l,r), s) << endl;
        }
    }
}