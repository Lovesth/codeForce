#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{}, n{};
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> a(n+1);
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }

        map<int, vector<int>> poss{};
        vector<int> dp(n+1);
        int res{0};

        for(int i=1; i<=n; i++) {
            int num = a[i];
            
            if(poss[num].size() < num-1) {
                poss[num].push_back(i);
                dp[i] = dp[i-1];
                continue;
            }

            if(num == 1){
                dp[i] = dp[i-1] + 1;
                poss[num].push_back(i);
                res = max(res, dp[i]);
                continue;
            }

            int len = poss[num].size();
            int lastPos = poss[num][len-(num-1)];
            dp[i] = max(dp[i-1], dp[lastPos-1] + num);
            poss[num].push_back(i);
            res = max(res, dp[i]);
        }

        cout << res << endl;
    }
}           // 2
                    
// 1                        
                           // 3