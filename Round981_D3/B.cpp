#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> rec(2*n);
        int tmp;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> tmp;
                rec[i-j+n] = min(rec[i-j+n], tmp);
            }
        }
        int res = 0;
        for(auto num : rec){
            res += abs(num);
        }
        cout << res << endl;
    }
}