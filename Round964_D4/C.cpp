#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int t;
  int n, s, m;
  int l1, r1, l2, r2;
  cin >> t;
  while (t--) {
    cin >> n >> s >> m;
    cin >> l1 >> r1;
    bool flag = false;
    if (l1 >= s) {
      flag = true;
    }
    for (int i = 1; i < n; i++) {
      cin >> l2 >> r2;
      if (l2 - r1 >= s) {
        flag |= true;
      }
      l1 = l2;
      r1 = r2;
    }
    if (m - r1 >= s) {
      flag |= true;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}