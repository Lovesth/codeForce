#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> nums(n + 1);

    for (int i = 1; i <= n; i++)
      cin >> nums[i];

    auto g{nums[1]};
    for (int i = 1; i <= n; i++)
      g = gcd(g, nums[i]);

    if (g == *max_element(nums.begin(), nums.end())) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (nums[i] != g && !flag) {
        cout << 1 << " ";
        flag = true;
      } else {
        cout << 2 << " ";
      }
    }
    cout << endl;
  }
}

// #include <iostream>
// #include <numeric> // 用于 std::gcd
// #include <vector>

// using namespace std;

// // 计算数组的GCD
// int compute_gcd(const vector<int> &arr) {
//   if (arr.empty()) {
//     return 0; // 理论上不会出现空数组
//   }
//   int res = arr[0];
//   for (size_t i = 1; i < arr.size(); ++i) {
//     res = gcd(res, arr[i]);
//     if (res == 1)
//       break; // 优化：GCD为1时无法更小
//   }
//   return res;
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);

//   int t;
//   cin >> t;

//   while (t--) {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//       cin >> a[i];
//     }

//     // 检查所有元素是否相同
//     bool all_same = true;
//     for (int x : a) {
//       if (x != a[0]) {
//         all_same = false;
//         break;
//       }
//     }
//     if (all_same) {
//       cout << "No\n";
//       continue;
//     }

//     vector<int> res;
//     bool found = false;

//     // 检查每个元素是否可以单独分割
//     for (int i = 0; i < n; ++i) {
//       vector<int> rest;
//       for (int j = 0; j < n; ++j) {
//         if (j != i) {
//           rest.push_back(a[j]);
//         }
//       }
//       int g = compute_gcd(rest);
//       if (g != a[i]) {
//         res.assign(n, 2);
//         res[i] = 1;
//         found = true;
//         break;
//       }
//     }

//     cout << "Yes\n";
//     for (int x : res) {
//       cout << x << ' ';
//     }
//     cout << '\n';
//   }

//   return 0;
// }