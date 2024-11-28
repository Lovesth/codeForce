#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, q, i, v;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s >> q;
        set<int> recEnd{};
        int sLen = s.size();
        for (int j = 0; j < sLen - 3; j++)
        {
            if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0')
                recEnd.insert(j + 3);
        }
        while (q--)
        {
            cin >> i >> v;
            i--;
            s[i] = '0' + v;
            auto it = recEnd.lower_bound(i);
            if (it != recEnd.end() && ((*it) - i) <= 3)
            {
                int pos = *it;
                if (!(s[pos] == '0' && s[pos - 1] == '0' && s[pos - 2] == '1' && s[pos - 3] == '1'))
                    recEnd.erase(it);
            }

            for (int k = max(0, i - 3); k <= min(sLen - 4, i); k++)
            {
                if (s[k] == '1' && s[k + 1] == '1' && s[k + 2] == '0' && s[k + 3] == '0')
                    recEnd.insert(k+3);
            }

            if (!recEnd.empty())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}