#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int res = 0;
        if((l&1) == 0){
            l++;
        }
        res = (r-l+2)/4;
        cout << res << endl;
    }
    
}