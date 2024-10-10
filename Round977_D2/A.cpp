#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }
        multiset<ll> rec(nums.begin(), nums.end());
        ll res = 0;
        while(rec.size() > 1){
            ll t1 = *rec.begin();
            ll t2 = *(++rec.begin());
            for(int _=1; _<=2; _++){
                rec.erase(rec.begin());
            }
            rec.insert((t1+t2)/2);
        }
        cout << *rec.begin() << endl;
    }
}