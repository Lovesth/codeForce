#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mySqrt(ll x){
    ll res = sqrt(x);
    if((res+1)*(res+1) <= x)
        return res+1;
    if(res*res<=x)
        return res;
    return res-1;
}

bool check(ll n, ll k){
    return n-mySqrt(n) >= k;
}

int main(){
    int t;
    ll k;
    cin >> t;
    while(t--){
        cin >> k;
        ll l = k, r = 4*(1e18);
        while(l<r){
            ll mid = (l+r)/2;
            if(check(mid,k)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout << r << endl;
    }
}