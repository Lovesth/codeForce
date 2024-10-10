#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> data(n);
        ll S = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
            S += data[i];
        }
        if (n <= 2)
        {
            cout << -1 << endl;
            continue;
        }
        sort(data.begin(), data.end());
        ll x = 0;
        x = max(x, 1+data[n/2] * n * 2 - S);
        cout << x << endl;
    }
}