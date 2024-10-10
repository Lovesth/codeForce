#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> nums(n);
        ll s = 0, maxVal = 0;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            s += nums[i];
            maxVal = max(maxVal, nums[i]);
        }
        for(ll res=n; res>0; res--){
            if(res*maxVal > s){
                if(res*maxVal <= s+k){
                    cout << res << endl;
                    break;
                }
            }else{
                if(s%res == 0){
                    cout << res << endl;
                    break;
                }
                if(s/res != (s+k)/res){
                    cout << res << endl;
                    break;
                }
            }
        }
    }
}