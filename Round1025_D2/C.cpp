#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  int res{};
  while (t--) {
    cin >> n;

    cout << "digit" << endl;
    cout.flush();
    cin >> res;

    cout << "digit" << endl;
    cout.flush();
    cin >> res;

    int l{1}, r{16};
    while (l < r) {
      int mid = (l + r) / 2;
      cout << "add -" + to_string(mid) << endl;
      cout.flush();
      cin >> res;
      if (res == 0) {
        r = mid;
      } else {
        l = 1;
        r = r - mid;
      }
    }
    cout << "add " + to_string(n - 1) << endl;
    cout.flush();
    cin >> res;

    cout << "!" << endl;
    cout.flush();
    cin >> res;
  }
}