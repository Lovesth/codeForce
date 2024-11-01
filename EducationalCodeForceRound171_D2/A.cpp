#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, X, Y, K;
    cin >> t;
    while (t--)
    {
        cin >> X >> Y >> K;
        int minLen = min(X, Y);
        cout << 0 << " " << 0 << " " << minLen << " " << minLen << endl;
        cout << 0 << " " << minLen << " " << minLen << " " << 0 << endl;
    }
}