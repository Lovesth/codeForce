#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n;
    ll x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        unordered_map<ll, ll> rec;
        ll num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            rec[num]++;
        }

        for (ll i = 0;; i++)
        {
            if (rec.count(i))
            {
                if (rec[i] > 1)
                {
                    ll v = rec[i];
                    rec[i % x] += v - 1;
                    rec[i] -= v - 1;
                }
            }
            else
            {
                if (rec.count(i % x) && rec[i % x] > 1)
                {
                    rec[i]++;
                    rec[i % x]--;
                }
                else
                {
                    num = i;
                    break;
                }
            }
        }
        cout << num << endl;
    }
}