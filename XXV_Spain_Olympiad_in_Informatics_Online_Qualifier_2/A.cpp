#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        vector<ll> nums(n+1);
        for(int i=1; i<=n; i++){
            cin >> nums[i];
        }
        sort(begin(nums)+1, end(nums));
        int left = n/2, right = n/2+1;
        ll f = nums[left]+nums[right];
        bool flag = true;
        while(left && flag){
            flag = (flag && (nums[left]+nums[right]==f));
            left--, right++;
        }
        cout << (flag ? "SI" : "NO") << endl; 
    }
}