#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    string sn = to_string(n);
    int snLen = sn.size();
    vector<vector<int>> ans;
    for (int a = 1; a <= 10000; a++) {
      for (int b = min({10000, a * n, a * snLen}); b >= max(a * snLen - 6, 1);
           b--) {
        string correct = to_string(a * n - b);
        if (correct == "0")
          correct = "";
        int calLen = max(snLen * a - b, 0);
        if (calLen > correct.size())
          break;
        if (calLen != correct.size())
          continue;
        for (int i = 0; i < calLen; i++) {
          if (correct[i] != sn[i % snLen])
            break;
          if (i == calLen - 1)
            ans.push_back(vector<int>{a, b});
        }
      }
    }
    cout << ans.size() << endl;
    for (auto &e : ans)
      cout << e[0] << " " << e[1] << endl;
  }
}