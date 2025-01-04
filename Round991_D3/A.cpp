#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<string> sv(n);
        int curLen = 0, cnt = 0;
        for (auto &s : sv)
        {
            cin >> s;
            curLen += s.size();
            if (curLen <= m)
                cnt++;
        }
        cout << cnt << endl;
    }
}