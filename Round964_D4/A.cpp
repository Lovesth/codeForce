#include <bits/stdc++.h>
#include <string>
using namespace std;

int calculateSum(int n) {
  int res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = stoi(s);
    cout << calculateSum(n) << endl;
  }
}