#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int tmp, s = 0, maxVal = 0, minVal = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            s += tmp;
            maxVal = max(maxVal, tmp);
            minVal = min(minVal,tmp);
        }
        cout << (maxVal-minVal)*(n-1) << endl;
    }
}