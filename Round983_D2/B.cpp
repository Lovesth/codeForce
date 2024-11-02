#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n == 1)
        {
            if (k == 1)
                cout << 1 << endl
                     << 1 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        if ((k - 1) & 1)
        {
            cout << 3 << endl;
            cout << 1 << " " << k << " " << k + 1 << endl;
        }
        else
        {
            int l1, l2, l3, l4, l5;
            l1 = 1;
            l2 = k - 1;
            l3 = k;
            l4 = k + 1;
            l5 = k + 2;
            if (l1 < l2 && l2 < l3 && l3 < l4 && l4 < l5 && l5 <= n)
            {
                cout << 5 << endl;
                cout << l1 << " " << l2 << " " << l3 << " " << l4 << " " << l5 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}