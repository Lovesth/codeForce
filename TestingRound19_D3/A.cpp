#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int s = 0;
        int tmp;
        int sign_ = 1;
        while (n--)
        {
            cin >> tmp;
            if (sign_)
                s += tmp;
            else
                s -= tmp;
            sign_ ^= 1;
        }
        cout << s << endl;
    }
}