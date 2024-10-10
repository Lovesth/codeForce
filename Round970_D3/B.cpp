#include <bits/stdc++.h>
using namespace std;

bool check(string &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '1')
            return false;
    }
    for (int row = 2; row <= n - 1; row++)
    {
        if (s[(row - 1) * n] != '1' || s[row * n - 1] != '1')
            return false;
        for (int col = 1; col < n - 1; col++)
        {
            if (s[(row - 1) * n + col] != '0')
                return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[(n-1)*n+i] != '1')
            return false;
    }
    return true;
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int ord = sqrt(n);
        if (ord * ord != n)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << (check(s, ord) ? "YES" : "NO") << endl; 
    }
}