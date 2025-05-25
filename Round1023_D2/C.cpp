#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

const ll minVal = -1e18;

void solve() {
  ll n, k;
  cin >> n >> k;
  string s{};
  cin >> s;

  vector<ll> nums(n);
  for (auto &num : nums)
    cin >> num;

  ll dp{0};
  ll maxVal{0};
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      dp = 0;
      continue;
    }
    dp = max(dp + nums[i], 1LL * nums[i]);
    maxVal = max(maxVal, dp);
  }

  if (maxVal > k) {
    cout << "No" << endl;
    return;
  }

  //   if (maxVal == k) {
  //     cout << "Yes" << endl;
  //     for (int i = 0; i < n; i++) {
  //       if (s[i] == '0') {
  //         cout << -1e18 << " ";
  //       } else {
  //         cout << nums[i] << " ";
  //       }
  //     }
  //     return;
  //   }

  vector<int> pos{};
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      pos.push_back(i);
    }
  }
  if (maxVal == k) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cout << minVal << " ";
      } else {
        cout << nums[i] << " ";
      }
    }
    cout << endl;
    return;
  }

  if (pos.empty()) {
    cout << "No" << endl;
    return;
  }
  pos.insert(pos.begin(), -1);
  pos.push_back(n);

  int targetPos = pos[1];

  ll maxLeft{0}, maxRight{0};
  ll tmp{0};
  for (int i = targetPos - 1; i > pos[0]; i--) {
    tmp += nums[i];
    maxLeft = max(maxLeft, tmp);
  }

  tmp = 0;
  for (int i = targetPos + 1; i < pos[2]; i++) {
    tmp += nums[i];
    maxRight = max(maxRight, tmp);
  }

  s[targetPos] = '1';
  nums[targetPos] = k - maxLeft - maxRight;
  cout << "Yes" << endl;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cout << minVal << " ";
    } else {
      cout << nums[i] << " ";
    }
  }
  cout << endl;
  return;
}

int main() {
  int t;

  cin >> t;
  while (t--) {
    solve();
  }
}