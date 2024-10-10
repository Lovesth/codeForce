#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int check(int x1, int x2, int y1, int y2) {
  int s1 = 0, s2 = 0;
  if (x1 > y1)
    s1++;
  if (y1 > x1)
    s2++;
  if (x2 > y2)
    s1++;
  if (y2 > x2)
    s2++;
  return s1 > s2;
}

int main() {
  int t;
  cin >> t;
  int a1, a2, b1, b2;
  while (t--) {
    cin >> a1 >> a2 >> b1 >> b2;
    int cnt = 0;
    cnt += check(a1, a2, b1, b2);
    cnt += check(a1, a2, b2, b1);
    cnt *= 2;
    cout << cnt << endl;
  }
}