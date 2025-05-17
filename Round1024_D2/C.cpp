#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int t;
  int n;

  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<int>> data(n, vector<int>(n));

    int curPos;
    curPos = (n-1) / 2;
    int i{}, j{};
    i = j = n/2;
    if(n%2 == 0)
        j--;
    int curNum{0};
    int curLen = (n & 1 ? 1 : 2);

    while ((i >= 0) && (j >= 0)) {
      data[i][j] = curNum++;

    //   int tmp = curLen;
    //   // curLen--;
      for (int t = i - 1; t >= curPos; t--) {
        data[t][j] = curNum++;
      }

      for (int t = curPos + 1; t < curPos + curLen; t++) {
        data[curPos][t] = curNum++;
      }
      for (int t = curPos + 1; t < curPos + curLen; t++) {
        data[t][curPos + curLen - 1] = curNum++;
      }
      for (int t = curPos + curLen - 2; t >= curPos + ((n%2 == 0) && (curLen<=2)); t--) {
        data[curPos + curLen - 1][t] = curNum++;
      }

    //   for (int t = curPos + curLen - 2; t >= i + 1; t--) {
    //     data[t][j] = curNum++;
    //   }
      i = curPos + curLen - 1;
      --j;

      curLen += 2;
      --curPos;
    }
    for (auto &row : data) {
      for (auto num : row) {
        cout << num << " ";
      }
      cout << endl;
    }
  }
}