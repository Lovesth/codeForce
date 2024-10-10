#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

int main() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    vector<ll> sum_(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
      sum_[i + 1] += (s[i] == '0' ? -1 : 1) + sum_[i];
    }
    unordered_map<ll, ll> record;
    ll res = 0;
    ll n = s.size();
    for (int i = 0; i <= n; i++) {
      res += ll(n - i + 1) * record[sum_[i]] % MOD;
      record[sum_[i]] += (i + 1);
    }
    cout << res % MOD << endl;
  }
}