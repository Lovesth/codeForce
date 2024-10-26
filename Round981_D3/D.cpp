#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        set<ll> us{0};
        int tmp;
        ll s = 0;
        int res = 0;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            s += tmp;
            if(us.count(s)){
                res++;
                us.clear();
                us.insert(0);
                s = 0;
            }
            us.insert(s);
        }
        cout << res << endl;
    }
}