#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int n1 = n, n2 = n, n3 = n;
    int res = 0;
    res += n2 / 2;
    n1 -= n2 / 2;
    n2 -= n2 / 2 * 2;
    //
    if (n2)
    {
        int t = min(n1 / 2, n2);
        res += t;
        n1 -= 2 * t;
        n2 -= t;
    }
    if (n1)
    {
        res += n1 / 3;
        n1 = n1 % 3;
    }
    if (n3)
    {
        res += n3 / 2;
        n3 %= 2;
    }
    //
    int t = n1 * 18 + n2 * 21 + n3 * 25;
    res += (t + 60 - 1) / 60;
    cout << res << endl;
}