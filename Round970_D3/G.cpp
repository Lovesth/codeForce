#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll tmp;
        multiset<ll> data;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            data.insert(tmp);
        }
        if(data.count(1)){
            cout << data.size()+k-1 << endl;
        }else{
            
        }
    }
}