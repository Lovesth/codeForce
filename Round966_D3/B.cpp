#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int tmp;
    cin >> tmp;
    int left = tmp - 1;
    int right = tmp + 1;
    n--;
    bool flag = true;
    while (n--) {
      cin >> tmp;
      if (tmp == left) {
        left--;
      } else if (tmp == right) {
        right++;
      } else {
        flag = false;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}