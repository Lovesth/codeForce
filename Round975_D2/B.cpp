#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<ll> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        unordered_map<ll, ll> rec;
        for (int i = 1; i <= n; i++)
        {
            rec[1LL * i * (n - i) + i - 1] += 1;
            if (i < n)
            {
                rec[1LL * i * (n - i)] += nums[i + 1] - nums[i] - 1;
            }
        }
        ll k;
        for(int i=1; i<=q; i++){
            cin >> k;
            cout << rec[k] << " ";
        }
        cout << endl;
    }
}