#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int s{0}, t{0}, w{0};
// vector<int> vis(3e5+10);
vector<pair<ll,ll>> dp(2e5+10, {LLONG_MAX, -1});
pair<ll,ll> res{LLONG_MAX, -1};

void dfs(map<int, vector<vector<int>>>& edges, vector<ll>& b, int curNode){
    for(auto& nextPoints : edges[curNode]){
        ll tmp = dp[curNode].second + b[curNode];
        if(tmp < nextPoints[1])
            continue;
        dp[nextPoints[0]].second = max(dp[nextPoints[0]].second, tmp);
        dp[nextPoints[0]].first = min(max(nextPoints[1] * 1LL, dp[curNode].first), dp[nextPoints[0]].first);
        dfs(edges, b, nextPoints[0]);
    }
    if(curNode == n){
        if(dp[n].first < res.first)
            res = dp[n];
    }
    dp[curNode] = {LLONG_MAX, -1};
}

void solve(){
    for(int i=0; i<=n; i++)
        dp[i] = {LLONG_MAX, -1};
    res = {LLONG_MAX, -1};
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

    dp[1] = {0LL, 0LL};
    dfs(edges, b, 1);

    if(res.second == -1){
        cout << -1 << endl;
        return;
    }
    cout << res.first << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}