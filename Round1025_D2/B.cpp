#include <bits/stdc++.h>
using namespace std;

int cal(int n, int m) {
  int res{0};
  while (n > 1) {
    res++;
    n = (n + 1) / 2;
  }
  while (m > 1) {
    res++;
    m = (m + 1) / 2;
  }
  return res;
}

int main() {
  int t;
  int n, m, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    cout << 1 + min({cal(n-a+1, m), cal(a, m), cal(n, m-b+1), cal(n, b)}) << endl;
  }
}