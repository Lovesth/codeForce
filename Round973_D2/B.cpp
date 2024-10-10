#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll res = 0;
        ll tmp;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            if(i==n-1)
                res -= tmp;
            else
                res += tmp;
        }
        cout << res << endl;
    }
}