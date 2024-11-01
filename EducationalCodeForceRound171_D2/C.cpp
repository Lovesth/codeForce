#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        s = " " + s;
        int i = n, j = n, k = n, l = n;
        priority_queue<int, vector<int>, less<int>> onesPos{};
        ll res = 0;
        while (i >= 1)
        {
            for (j = i; j >= 1 && s[j] == '1'; j--)
            {
                onesPos.push(j);
            }
            k = j;
            for (l = k; l >= 1 && s[l] == '0'; l--)
            {
                res += l;
            }
            for (int _ = 0; _ < k - l && !onesPos.empty(); _++)
            {
                onesPos.pop();
            }
            i = l;
        }
        if (onesPos.size() > 0)
        {
            int len = onesPos.size();
            for (int i = 0; i < len / 2; i++)
            {
                onesPos.pop();
            }
            while (!onesPos.empty())
            {
                res += onesPos.top();
                onesPos.pop();
            }
            
        }
        cout << res << endl;
    }
}
