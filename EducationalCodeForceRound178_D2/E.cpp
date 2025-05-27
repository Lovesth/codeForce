#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int n, k, q;
  string s{}, t{};

  cin >> n >> k;
  cin >> s;

  vector<vector<int>> rec(n + 2, vector<int>(k, n));
  for (int i = n - 1; i >= 0; i--) {
    int tmp = s[i] - 'a';
    for (int j = 0; j < k; j++) {
      if (j == tmp) {
        rec[i][j] = i;
      } else {
        rec[i][j] = rec[i + 1][j];
      }
    }
  }

  vector<int> dp(n + 2);

  for (int i = n - 1; i >= 0; i--) {
    dp[i] = 1 + dp[*max_element(rec[i + 1].begin(), rec[i + 1].end())];
  }

  cin >> q;
  while (q--) {
    cin >> t;
    int pos{-1};
    for (int i = 0; i < t.size() && pos < n; i++) {
      pos = rec[pos + 1][t[i] - 'a'];
    }
    cout << dp[pos] << endl;
  }
}