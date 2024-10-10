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
        vector<ll> nums(n + 1);
        int d = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            d = gcd(d, nums[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            nums[i] /= d;
        }
        ll S = 0;
        ll curD = 0;
        for (int i = 1; i <= n; i++)
        {
            ll curMinD = 1e9;
            for (int j = 1; j <= n; j++)
            {
                curMinD = min(curMinD, gcd(curD, nums[j]));
            }
            curD = curMinD;
            if (curD == 1)
            {
                S += n - i + 1;
                break;
            }
            S += curD;
        }
        cout << S*d << endl;
    }
}