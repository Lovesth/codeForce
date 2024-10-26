#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, w, h;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int maxW = 0, maxH = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> w >> h;
            maxW = max(maxW, w);
            maxH = max(maxH, h);
        }
        cout << 2*(maxW+maxH) << endl;
        // vector<int> rec(101);
        // for(int i=1; i<=n; i++){
        //     cin >> w >> h;
        //     for(int j=1; j<=w; j++){
        //         rec[j] = max(rec[j],h);
        //     }
        // }
    }
}