#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &e : a)
      cin >> e;
    for (auto &e : b)
      cin >> e;
    int al = 0, ar = n - 1, bl = 0, br = n - 1;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if ((a[al] != b[bl] && a[al] != b[br]) ||
          (a[ar] != b[bl] && a[ar] != b[br])) {
        flag = false;
        break;
      } else {
        if (b[bl] == a[al])
          bl++;
        else
          br--;
        al++;
      }
    }
    if (flag)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
}