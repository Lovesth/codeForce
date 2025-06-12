#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int s{0}, t{0}, w{0};
// vector<int> vis(3e5+10);
vector<int> dp(2e5+10, 0);

void solve(){
    cin >> n >> m;
    vector<ll> b(n+1);
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    map<int, vector<vector<int>>> edges{};
    
    for(int i=0; i<m; i++){
        cin >> s >> t >> w;
        // edges[s].push_back({t, w, i});
        edges[s].push_back({t, w});
    }

    auto check = [&](int curVal){
        for(int i=0; i<=n; i++)
            dp[i] = 0;
        for(int i=1; i<n; i++){
            if(i > 1 && dp[i] == 0)
                continue;
            dp[i] += b[i];
            dp[i] = min(dp[i], curVal);
            for(auto& nextPoint : edges[i]){
                if(dp[i] < nextPoint[1]){
                    continue;
                }
                dp[nextPoint[0]] = max(dp[nextPoint[0]], dp[i]);
            }
        }
        return dp[n] > 0;
    };

    int l{1}, r = 1e9+1;
    while(l < r){
        int mid = (l+r) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if(l > 1e9){
        cout << -1 << endl;
        return;
    }
    cout << l << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}