#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;


int main(){
    int t;
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        int num;
        vector<ll> dp(4);
        for(int i=0; i<n; ++i){
            cin >> num;
            if(num == 1){
                dp[1]++;
            }else if(num == 2){
                dp[2] = (2*dp[2] + dp[1]) % MOD;
                // dp[2] = (dp[2] + dp[1]) % MOD;
            }else{
                dp[3] = (dp[3] + dp[2]) % MOD;
            }
        }
        cout << dp[3] << endl;
    }
}