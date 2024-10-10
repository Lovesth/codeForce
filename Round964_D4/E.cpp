#include <bits/stdc++.h>
#include <ctime>
#include <vector>
using namespace std;
using ll = long long;

int cnt(int m) {
  int res = 0;
  while (m) {
    res++;
    m /= 3;
  }
  return res;
}

int main() {
  vector<int> preSum(2 * 1e5 + 7);
  for (int i = 1; i < preSum.size(); i++) {
    preSum[i] = preSum[i - 1] + cnt(i);
  }
  int t;
  int l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    cout << preSum[r] - preSum[l - 1] + preSum[l] - preSum[l - 1] << endl;
  }
}

// int main() {
//   int t;
//   ll l, r;
//   cin >> t;
//   while (t--) {
//     cin >> l >> r;
//     ll cnt = 0;
//     ll i = l;
//     ll flag = 0;
//     while (i) {
//       i /= 3;
//       flag++;
//     }
//     cnt += 2 * flag;
//     i = 1;
//     for (int j = 0; j < flag; j++) {
//       i *= 3;
//     }
//     // cout << cnt << endl;
//     for (l++; l <= r;) {
//       while (l >= i) {
//         i *= 3;
//         flag++;
//       }
//       ll tmp = min(r, i - 1);
//       cnt += flag * (tmp - l + 1);
//       l = tmp + 1;
//     }
//     cout << cnt << endl;
//   }
// }