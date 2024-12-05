#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s, r;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s >> r;
        // char curChar = s[0];
        int cntOneS = 0;
        int cntZeroS = 0;
        for (auto c : s)
        {
            if (c == '0')
                cntZeroS++;
            else
                cntOneS++;
        }
        int pos = 0;
        int rec = 0;
        while (rec < n - 1 && cntOneS > 0 && cntZeroS > 0)
        {
            int tmp = min(cntOneS, cntZeroS);
            rec += tmp;
            int cntOneR = 0;
            int cntZeroR = 0;
            for (int i = pos; i < pos + tmp; i++)
            {
                if (r[i] == '0')
                    cntZeroR++;
                else
                    cntOneR++;
            }
            cntOneS = cntOneS - tmp + cntOneR;
            cntZeroS = cntZeroS - tmp + cntZeroR;
            pos += tmp;
        }
        if (rec >= n - 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}