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
            cout << ret[l] << endl;
        }
    }
}

// #include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
// #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define endl '\n'
// #define int long long
// #define f first
// #define mp make_pair
// #define s second
// using namespace std;

// void solve()
// {
//     int n, k, q;
//     cin >> n >> k >> q;
//     int a[n + 1];
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     map<int, int> m;
//     multiset<int> tot;
//     for (int i = 1; i <= n; i++)
//         tot.insert(0);
//     for (int i = 1; i < k; i++)
//     {
//         tot.erase(tot.find(m[a[i] - i]));
//         m[a[i] - i]++;
//         tot.insert(m[a[i] - i]);
//     }
//     int ret[n + 1];
//     for (int i = k; i <= n; i++)
//     {
//         tot.erase(tot.find(m[a[i] - i]));
//         m[a[i] - i]++;
//         tot.insert(m[a[i] - i]);
//         int p = i - k + 1;
//         ret[p] = k - *tot.rbegin();
//         tot.erase(tot.find(m[a[p] - p]));
//         m[a[p] - p]--;
//         tot.insert(m[a[p] - p]);
//     }
//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         cout << ret[l] << endl;
//     }
//     tot.clear();
//     m.clear();
// }

// signed main()
// {
//     fast;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }