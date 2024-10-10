#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, l, r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        double tmp = sqrt(2*(r-l)+1.0/4)+1.0/2;
        int res = int(tmp);
        cout << res << endl;
    }
}