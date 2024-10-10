#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
  int t, n, x;
  cin >> t;
  while (t--) {
    ll res = 0;
    cin >> n >> x;
    for (int a = 1; a <= n; a++) {
      for (int b = 1; b <= n / a; b++) {
        for (int c = 1; c <= (n - a * b) / (a + b); c++) {
          if (a + b + c <= x)
            res++;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
