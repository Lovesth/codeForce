#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cal(ll i, ll k, ll n)
{
    return abs(i * (2 * k + i - 1) / 2 - (n - i) * (2 * k + n + i - 1) / 2);
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        double s = double(1) * ((ll)n * n + 2LL * n * k - n) / double(2) + pow((double(2) * k - 1), 2) / double(4);
        ll res = sqrt(s) - (double(2) * k - 1) / double(2);
        if (res >= 2 && res < n)
        {
            cout << min({cal(res, k, n), cal(res - 1, k, n), cal(res + 1, k, n)}) << endl;
        }
        if (res <= 1)
        {
            cout << min({cal(res, k, n), cal(res + 1, k, n)}) << endl;
        }
        if(res==n){
            cout << min({cal(res,k,n),cal(res-1,k,n)}) << endl;
        }
    }
}