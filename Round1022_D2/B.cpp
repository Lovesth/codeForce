#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int main() {
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;

    if (x == 0 && n == 1) {
      cout << -1 << endl;
      continue;
    }

    if (x == 0) {
      if (n & 1) {
        cout << 6 + (n - 3) << endl;
        continue;
      } else {
        cout << n << endl;
        continue;
      }
    }

    // if (n & 1) {
    //   cout << x + n - 1 << endl;
    //   continue;
    // }

    int cnt{0};
    int tmp{x};
    while (tmp) {
      if (tmp & 1)
        cnt++;
      tmp >>= 1;
    }

    if (n <= cnt) {
      cout << x << endl;
    } else {
      int dif = n - cnt;
      if (dif % 2 == 0) {
        cout << x + dif << endl;
      } else {
        if (cnt > 1) {
          cout << x + dif + 1 << endl;
          continue;
        }
        if (x & 1) {
          cout << x + 4 + dif - 1 << endl;
        } else {
          cout << x + 2 + dif - 1 << endl;
        }
      }
    }
  }
}