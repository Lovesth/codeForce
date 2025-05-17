#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, p, q, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> p >> q;
        // 
        int d = n / p;
        int r = n % p;
        if(!r && (m != d*q))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}