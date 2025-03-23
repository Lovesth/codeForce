#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y, a;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> a;
        if (a % (x + y) + 0.5 < x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}