#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int maxVal = 0;
        long long s = 0;
        int tmp;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            maxVal = max(maxVal,tmp);
            s += tmp;
        }
        cout << max(1LL*maxVal, (long long)ceil(1.0*s/x)) << endl;
    }
    
}