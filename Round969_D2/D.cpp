#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n, u, v;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> edges(n + 1);
        vector<int> degree(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        cin >> s;
        s = " " + s;
        int zeroCnt = 0, onesCnt = 0, res = 0, leafCnt = 0, allLeafCnt = 0;
        for (int i = 2; i <= n; i++)
        {
            if (degree[i] == 1)
            {
                if (s[i] == '0')
                    zeroCnt++;
                if (s[i] == '1')
                    onesCnt++;
                if (s[i] == '?')
                    leafCnt++;
            }
            if (s[i] == '?')
                allLeafCnt++;
        }
        int isIris = 1;
        if (s[1] == '?')
        {
            if (zeroCnt > onesCnt)
            {
                s[1] = '1';
                isIris = 0;
            }
            else if (onesCnt > zeroCnt)
            {
                s[1] = '0';
                isIris = 0;
            }
            else
            {
                if ((allLeafCnt - leafCnt) % 2)
                {
                    s[1] = '0';
                }
                else
                {
                    s[1] = '0';
                    isIris = 0;
                }
            }
        }
        if (s[1] == '1')
            res += zeroCnt;
        else
            res += onesCnt;
        res += (isIris ? (leafCnt + 1) / 2 : leafCnt / 2);
        cout << res << endl;
    }
}
