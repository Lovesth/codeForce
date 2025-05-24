#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int maxVal{0};
    int minVal{INT_MAX};
    vector<int> nums(n);

    ll S{0};
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      S += nums[i];
      maxVal = max(maxVal, nums[i]);
      minVal = min(minVal, nums[i]);
    }

    int cnt{0};
    for (auto num : nums)
      cnt += (num == maxVal);

    int diff = maxVal - minVal;
    if (diff > k + 1 || (diff == k+1 && cnt >= 2)) {
      cout << "Jerry" << endl;
      continue;
    }

    cout << (S & 1 ? "Tom" : "Jerry") << endl;
  }
}