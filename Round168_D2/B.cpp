#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
      int res = 1;
      res &= s1[i] == '.' && s2[i] == '.';
      res &= (s1[i - 1] != s2[i - 1]);
      res &= (s1[i + 1] != s2[i + 1]);
      res &= (s1[i - 1] == s1[i + 1]);
      cnt += res;
    }
    cout << cnt << endl;
  }
}