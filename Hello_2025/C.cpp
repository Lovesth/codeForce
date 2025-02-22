#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int k = 31 - __builtin_clz(l ^ r);
        int a = l | ((1 << k) - 1);
        int b = a + 1;
        int c = (a == l ? r : l);
        cout << a << " " << b << " " << c << endl;
    }
}