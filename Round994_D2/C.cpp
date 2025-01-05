#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        vector<int> res(n);
        --x, --y;
        for (int i = 0; i < n; i++)
        {
            res[(x + i) % n] = i % 2;
        }
        if(n&1 || (y-x)%2 == 0)
            res[x] = 2;
        for(auto& r : res)
            cout << r << " ";
        cout << endl;
    }
}