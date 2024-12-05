#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l, r, k;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> k;
        int ub = r;
        int lb = l;
        int res = 0;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (1 + (ub - mid) / mid < k)
            {
                r = mid-1;
            }
            else
            {
                l = mid;
            }
        }
        if(1 + (ub - l) / l >= k)
            cout << l - lb + 1 << endl;
        else
            cout << 0 << endl;
    }
}