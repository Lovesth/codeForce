#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x, y;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> x >> y;
        int cntPerSecond = min(x,y);
        cout << int(ceil(1.0*n/cntPerSecond)) << endl;
    }
}