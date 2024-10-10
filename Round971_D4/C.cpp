#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y, k;
    cin >> t;
    float INF = 1e-6;
    long long res = 0;
    while (t--)
    {
        cin >> x >> y >> k;
        if (k == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int sx = ceil((1.0 * x - INF) / k);
            int sy = ceil((1.0 * y - INF) / k);
            if (sx > sy)
            {
                res = 2 * sx - 1;
            }
            else
            {
                res = 2 * sy;
            }
            cout << res << endl;
        }
    }
}