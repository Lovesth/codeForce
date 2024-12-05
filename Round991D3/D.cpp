#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char currentChar = s[i];
            int pos = i;
            for (int j = i; j < min(i + 10, n); j++)
            {
                if ((s[j] - s[i]) > (j - i) && (s[j] - (j - i)) > currentChar)
                {
                    currentChar = s[j] - (j - i);
                    pos = j;
                }
            }
            for (int k = pos - 1; k >= i; k--)
            {
                swap(s[k], s[k + 1]);
            }
            s[i] -= pos - i;
        }
        cout << s << endl;
    }
}