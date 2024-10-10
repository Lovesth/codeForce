#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    ll a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> b >> c >> d;
        bool flag = true;
        a = 0;
        for (int i = 0; i < 63; i++)
        {
            int b_ = (b >> i) & 1;
            int c_ = (c >> i) & 1;
            int d_ = (d >> i) & 1;
            if ((!b_ && c_ && d_) || (b_ && !c_ && !d_))
            {
                flag = false;
                break;
            }
            if (d_ == 0)
            {
                a |= (c_ != 0) * (1LL << i);
            }
            else
            {
                a |= (c_ != 1) * (1LL << i);
            }
        }
        if(!flag)
            cout << -1 << endl;
        else
            cout << a << endl;
    }
}