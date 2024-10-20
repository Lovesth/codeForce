#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            cin >> perm[i];
        for (int i = 0; i < n; i++)
            perm[i]--;
        vector<int> invperm(n);
        for (int i = 0; i < n; i++)
            invperm[perm[i]] = i;
        vector<int> diffArr(n);
        for (int i = 0; i < n; i++)
        {
            diffArr[min(i, invperm[i])]++;
            diffArr[max(i, invperm[i])]--;
        }
        for (int i = 1; i < n; i++)
            diffArr[i] += diffArr[i - 1];
        string s;
        cin >> s;
        set<int> problems;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'L' && s[i + 1] == 'R' && diffArr[i] != 0)
            {
                problems.insert(i);
            }
        }
        while (q--)
        {
            int x;
            cin >> x;
            x--;
            if (s[x] == 'L')
            {
                s[x] = 'R';
            }
            else
            {
                s[x] = 'L';
            }
            if (s[x - 1] == 'L' && s[x] == 'R' && diffArr[x - 1] != 0)
            {
                problems.insert(x - 1);
            }
            else
            {
                problems.erase(x - 1);
            }
            if (s[x] == 'L' && s[x + 1] == 'R' && diffArr[x] != 0)
            {
                problems.insert(x);
            }
            else
            {
                problems.erase(x);
            }
            if (problems.size())
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
