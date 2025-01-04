#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        vector<vector<int>> rec(3);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'p')
            {
                rec[0].push_back(i);
            }
            else if (s[i] == 's')
            {
                rec[1].push_back(i);
            }
            else
            {
                rec[2].push_back(i);
            }
        }

        if (rec[0].size() == 0 || rec[1].size() == 0)
        {
            cout << "YES" << endl;
        }
        else if (rec[0].front() < rec[1].back())
        {
            cout << "NO" << endl;
        }
        else
        {
            if (rec[0].front() <= n - 2 && rec[1].back() >= 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
}