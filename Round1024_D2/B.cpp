#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = abs(a[i]);
    }
    int num = a[1];
    sort(a.begin() + 1, a.end());

    auto pos = find(a.begin() + 1, a.end(), num) - a.begin();

    if (pos <= ceil(n / 2.0) || (n - pos + 1) >= ceil(n / 2.0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}