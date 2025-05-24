#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  bool allOneFlag = true;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    if (nums[i] == 0) {
      allOneFlag = false;
    }
  }

  if (allOneFlag) {
    cout << "YES" << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (nums[i] == 0) {
      if (i + 1 <= n && nums[i + 1] == 0) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  int n;
  cin >> t;

  while (t--) {
    solve();
  }
}