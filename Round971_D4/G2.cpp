#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, q, l, r;
    int cnt = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> q;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            nums[i] -= i;
        }
        vector<int> ret(n - k + 2);
        map<int, int> m;
        unordered_map<int, int> um;
        for (int i = 1; i <= k; i++)
        {
            um[nums[i]]++;
        }
        for (auto &[k, v] : um)
        {
            m[v]++;
        }
        ret[1] = k - (--m.end())->first;
        for (int i = 2; i <= n - k + 1; i++)
        {
            m[um[nums[i - 1]]]--;
            if (m[um[nums[i - 1]]] <= 0)
                m.erase(um[nums[i - 1]]);
            um[nums[i - 1]]--;
            m[um[nums[i - 1]]]++;

            m[um[nums[i + k - 1]]]--;
            if (m[um[nums[i + k - 1]]] <= 0)
                m.erase(um[nums[i + k - 1]]);
            um[nums[i + k - 1]]++;
            m[um[nums[i + k - 1]]]++;
            ret[i] = k - (--m.end())->first;
        }
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            long long res = ret[l];
            int minVal = ret[l];
            for(int i=l+1; i<=r-k+1; i++){
                minVal = min(minVal, ret[i]);
                res += minVal;
            }
            cout << res << endl;
        }
    }
}