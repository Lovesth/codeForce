#include <bits/stdc++.h>
#include <string>
using namespace std;

bool check(string &s1, string &s2) {
  int left = 0, right = 0;
  while (left < s1.size() && right < s2.size()) {
    if (s1[left] == s2[right] || s1[left] == '?') {
      if (s1[left] == '?')
        s1[left] = s2[right];
      right++;
    }

    left++;
  }
  if (right == s2.size())
    for (; left < s1.size(); left++)
      if (s1[left] == '?')
        s1[left] = 'a';
  return right == s2.size();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    if (check(s, t))
      cout << "YES" << endl << s << endl;
    else
      cout << "NO" << endl;
  }
}