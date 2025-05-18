#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

struct FenwickTree {
  vector<int> t{};
  FenwickTree(int n) { t.resize(n + 1); }
  void reset() {
    for (int i = 0; i < t.size(); i++) {
      t[i] = 0;
    }
  }

  auto query(int k) {
    ll res{0};
    while (k > 0) {
      res += t[k];
      k -= k & -k;
    }
    return res;
  }

  void update(int k, int val) {
    while (k < t.size()) {
      t[k] += val;
      k += k & -k;
    }
  }
};

ll f(vector<int> &nums, int n) {
  FenwickTree FT(n);
  ll res{0};

  for (int i = nums.size() - 1; i >= 0; i--) {
    res += FT.query(nums[i]);
    FT.update(nums[i], 1);
  }
  return res;
}

int main() {
  int t{};
  int n{};
  cin >> t;
  while (t--) {
    cin >> n;
    int num{};
    vector<int> oddNum{};
    vector<int> evenNum{};
    for (int i = 1; i <= n; i++) {
      cin >> num;
      if (i & 1) {
        oddNum.push_back(num);
      } else {
        evenNum.push_back(num);
      }
    }

    int flag = (f(oddNum, n) % 2) != (f(evenNum, n) % 2);

    sort(oddNum.begin(), oddNum.end());
    sort(evenNum.begin(), evenNum.end());
    vector<int> res{};
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        res.push_back(oddNum[i / 2]);
      } else {
        res.push_back(evenNum[i / 2 - 1]);
      }
    }

    if (flag) {
      swap(res[res.size() - 1], res[res.size() - 3]);
    }

    for (auto num : res) {
      cout << num << " ";
    }
    cout << endl;
  }
}