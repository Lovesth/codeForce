#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int curGold = 0;
        int tmp;
        int res = 0;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            if(tmp>=k){
                curGold += tmp;
            }else if(tmp==0 && curGold>=1){
                curGold--;
                res++;
            }
        }
        cout << res << endl;
    }
}