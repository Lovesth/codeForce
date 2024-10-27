#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    int t;
    int n, m, r, c;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> r >> c;
        ll res = 0;
        res += m - c;
        res += 1LL * (n - r) * (m + m - 1);
        cout << res << endl;
    }
}