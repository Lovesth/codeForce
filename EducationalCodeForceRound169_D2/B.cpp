#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int l, r, L, R;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> L >> R;
        int res = min(r,R)-max(l,L);
        if(res<0){
            cout << 1 << endl;
        }else{
            res += (l!=L);
            res += (r!=R);
            cout << res << endl;
        }
    }
    
}