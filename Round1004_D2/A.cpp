#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;

        if (y - x == 1)
        {
            cout << "YES" << endl;
        }
        else if (x > y && (x - y + 1) % 9 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}