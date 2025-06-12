#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int s{0}, t{0}, w{0};
// vector<int> vis(3e5+10);
vector<ll> dp(2e5+10, 1e9+10);

void dfs(int curNode, vector<ll>& b, map<int, vector<vector<int>>>& edges){
    auto& nextPoints = edges[curNode];
    auto curCnt = max(dp[curNode], 0LL);

    for(auto nex : nextPoints){
        if(curCnt < nex[1])
            continue;
        dp[nex[0]] = min(dp[nex[0]], curCnt-b[nex[0]]);
        dfs(nex[0], b, edges);
    }
}


void solve(){
    // for(int i=0; i<m; i++)
    //     vis[i] = 0;

    cin >> n >> m;
    vector<ll> b(n+1);
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    map<int, vector<vector<int>>> edges{};
    
    for(int i=0; i<m; i++){
        cin >> s >> t >> w;
        // edges[s].push_back({t, w, i});
        edges[t].push_back({s, w, i});
    }
    // if(edges.count(n) == 0){
    //     cout << -1 << endl;
    //     return;
    // }

    int l=0, r=6;
    while(l < r){
        for(int i=0; i<=n; i++)
            dp[i] = 1e9+10;
        int mid = (l + r) / 2;
        dp[n] = mid;
        dfs(n, b, edges);
        if(dp[1] <= 0){
            r = mid;
        }else if(dp[1] == 1e9+10){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    if(l > 1e9){
        cout << -1 << endl;
        return;
    }
    cout << r << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}