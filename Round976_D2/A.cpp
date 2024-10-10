#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k==1){
            cout << n << endl;
            continue;
        }
        ll res = 0;
        while(n){
            res += n%k;
            n /= k;
        }
        cout << res << endl;
    }
}