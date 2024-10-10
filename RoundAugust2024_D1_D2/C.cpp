#include <bits/stdc++.h>
#include <climits>
#include <ostream>
#include <vector>
using namespace std;
using ll = long long;

ll calDis(ll x1, ll y1, ll x2, ll y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
  int t;
  int n;
  ll xs, ys, xt, yt;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<ll>> points(n, vector<ll>(2));
    for (auto &point : points)
      cin >> point[0] >> point[1];
    cin >> xs >> ys >> xt >> yt;
    auto dis = calDis(xs, ys, xt, yt);
    ll minDis = LLONG_MAX;
    for (auto &point : points) {
      minDis = min(minDis, calDis(xt, yt, point[0], point[1]));
    }
    // cout << dis << " " << minDis << endl;
    if (minDis > dis)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}