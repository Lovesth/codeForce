#include <bits/stdc++.h>
using namespace std;

int n, t1, cnt{0};
vector<int> d(2e5 + 10);
vector<pair<int, int>> obs(2e5 + 10);
vector<int> res(2e5 + 10);

void solve()
{
    cnt++;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> obs[i].first >> obs[i].second;
    }

    int h{0};
    vector<int> pos{};
    for(int i=1; i<=n; i++){
        if(d[i] == -1){
            pos.push_back(i);
        }else{
            h += d[i];
        }
        while(h < obs[i].first){
            if(pos.empty()){
                cout << -1 << endl;
                return;
            }
            h++;
            d[pos.back()] = 1;
            pos.pop_back();
        }

        while(h + pos.size() > obs[i].second){
            if(pos.empty()){
                cout << -1 << endl;
                return;
            }
            d[pos.back()] = 0;
            pos.pop_back();
        }
    }
    for(int i=1; i<=n; i++)
        cout << max(0, d[i]) << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    t1 = t;
    while (t--)
    {
        solve();
    }
}

// #include <bits/stdc++.h>

// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> d(n);
//     for (auto &x : d) {
//         cin >> x;
//     }
//     vector<int> l(n), r(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> l[i] >> r[i];
//     }
//     int left = 0;
//     vector<int> last;
//     for (int i = 0; i < n; ++i) {
//         if (d[i] == -1) {
//             last.push_back(i);
//         } else {
//             left += d[i];
//         }
//         while (left < l[i]) {
//             if (last.empty()) {
//                 cout << -1 << '\n';
//                 return;
//             }
//             d[last.back()] = 1;
//             ++left;
//             last.pop_back();
//         }
//         while (left + last.size() > r[i]) {
//             if (last.empty()) {
//                 cout << -1 << '\n';
//                 return;
//             }
//             d[last.back()] = 0;
//             last.pop_back();
//         }
//     }
//     for (auto &x : d) {
//         cout << max(0, x) << " ";
//     }
//     cout << "\n";
//     return;
// }

// signed main() {
//     // ios::sync_with_stdio(false);
//     // cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }