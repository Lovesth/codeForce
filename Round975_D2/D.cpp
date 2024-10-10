#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a;
    cin >> n;
    vector<int> l(n + 1, n);
    vector<int> r(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        l[a] = min(l[a], i);
        r[a] = max(r[a], i);
    }
    int L = n, R = 1;
    vector<int> f(n + 2);
    for (int T = 1; T <= n; T++)
    {
        if (l[T] <= r[T])
        {
            L = min(L, l[T]);
            R = max(R, r[T]);
        }
        if (R - L + 1 > T)
        {
            cout << 0 << endl;
            return;
        }
        f[max(R - T + 1, 1)]++;
        f[min(L + T, n + 1)]--;
    }
    partial_sum(f.begin(), f.end(), f.begin());
    cout << count(f.begin(), f.end(), n) << endl;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        solve();
    }
}