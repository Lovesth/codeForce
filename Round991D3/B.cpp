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
        vector<int> nums(n + 1);
        ll sOdd = 0;
        ll sEven = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            if (i & 1)
            {
                sOdd += nums[i];
            }
            else
            {
                sEven += nums[i];
            }
        }
        ll s = sOdd + sEven;
        if (s % n != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        ll tmp = s / n;
        ll cntOdd = (n + 1) / 2;
        ll cntEven = n - (n + 1) / 2;
        if (cntOdd * tmp != sOdd || cntEven * tmp != sEven)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}