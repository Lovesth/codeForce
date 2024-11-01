#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastPow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n & 1)
        {
            cout << n << endl;
            cout << 2 << " " << 1 << " " << 3 << " " << 4 << " " << 5 << " ";
            for (int i = 6; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            int tmp;
            for (int i = 1; i < 20; i++)
            {
                if (fastPow(2, i) >= n)
                {
                    tmp = i;
                    break;
                }
            }
            if (fastPow(2, tmp) == n)
            {
                cout << 2 * n - 1 << endl;
                for (int i = 1; i < fastPow(2, tmp - 1) - 1; i++)
                {
                    cout << i << " ";
                }
                for (int i = fastPow(2, tmp - 1); i < fastPow(2, tmp) - 1; i++)
                {
                    cout << i << " ";
                }
                cout << fastPow(2, tmp - 1) - 1 << " ";
                cout << fastPow(2, tmp) - 1 << " ";
                cout << n << endl;
            }
            else
            {
                cout << fastPow(2, tmp) - 1 << endl;
                for (int i = 1; i < fastPow(2, tmp - 1) - 1; i++)
                {
                    cout << i << " ";
                }
                for (int i = fastPow(2, tmp - 1); i <= n; i++)
                {
                    cout << i << " ";
                }
                cout << fastPow(2, tmp - 1) - 1 << endl;
            }
        }
    }
}