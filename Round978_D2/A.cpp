#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        int a, cnt = 0, s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            s += a;
            if (a & 1)
            {
                cnt++;
            }
        }
        int res = s-cnt;
        r -= res/2;
        if(r>=cnt){
            res += cnt;
        }else{
            res += 2*r-cnt;
        }
        cout << res << endl;
    }
}