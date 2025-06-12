// #include <bits/stdc++.h>
// using namespace std;

// int n, t1, cnt{0};
// vector<int> d(2e5 + 10);
// vector<pair<int, int>> obs(2e5 + 10);
// vector<vector<int>> dp(2e5 + 10, vector<int>(2));
// vector<int> res(2e5 + 10);

// void solve()
// {
//     cnt++;

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> d[i];

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> obs[i].first >> obs[i].second;
//     }

//     // if(obs[0].first > 0){
//     //     cout << -1 << endl;
//     //     return;
//     // }


//     // if (t1 >= 1e4)
//     // {
//     //     if (cnt == 83)
//     //     {
//     //         cout << n << endl;
//     //         for (int i = 1; i <= n; i++)
//     //             cout << d[i] << " ";
//     //         cout << endl;
//     //         for (int i = 1; i <= n; i++)
//     //         {
//     //             cout << obs[i].first << " " << obs[i].second;
//     //             cout << endl;
//     //         }
//     //     }
//     //     else
//     //     {
//     //         return;
//     //     }
//     // }

//     dp[0][0] = dp[0][1] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         if (d[i] == -1)
//         {
//             dp[i][0] = max(dp[i - 1][0], obs[i].first);
//             dp[i][1] = min(dp[i - 1][1] + 1, obs[i].second);
//         }
//         else if (d[i] == 0)
//         {
//             dp[i] = dp[i - 1];
//         }
//         else
//         {
//             dp[i][0] = dp[i - 1][0] + 1;
//             dp[i][1] = dp[i - 1][1] + 1;
//         }

//         dp[i][0] = max(dp[i][0], obs[i].first);
//         dp[i][1] = min(dp[i][1], obs[i].second);
        
//         if (dp[i][1] < obs[i].first || dp[i][0] > obs[i].second)
//         {
//             cout << -1 << endl;
//             return;
//         }
//     }

//     // res[0] = 0;
    
//     for (int i = n; i >= 1; i--)
//     {
//         int tmp = dp[i][0];
//         if (d[i] != -1)
//         {
//             res[i] = d[i];
//             continue;
//         }
//         if (dp[i - 1][1] < tmp)
//         {
//             res[i] = 1;
//             tmp = dp[i - 1][1];
//         }
//         else
//         {
//             res[i] = 0;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << res[i] << endl;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     t1 = t;
//     while (t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto &x : d) {
        cin >> x;
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    int left = 0;
    vector<int> last;
    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) {
            last.push_back(i);
        } else {
            left += d[i];
        }
        while (left < l[i]) {
            if (last.empty()) {
                cout << -1 << '\n';
                return;
            }
            d[last.back()] = 1;
            ++left;
            last.pop_back();
        }
        while (left + last.size() > r[i]) {
            if (last.empty()) {
                cout << -1 << '\n';
                return;
            }
            d[last.back()] = 0;
            last.pop_back();
        }
    }
    for (auto &x : d) {
        cout << max(0, x) << " ";
    }
    cout << "\n";
    return;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}