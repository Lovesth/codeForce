#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<vector<int>> rectangles(n, vector<int>(2));
        for (auto &rect : rectangles)
        {
            cin >> rect[0] >> rect[1];
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> curRectAngle = rectangles[i - 1];
            int w = curRectAngle[0];
            int h = curRectAngle[1];
            int curMaxPoints = w + h;
            int cost = 0;
            for(int j=0; j<=curMaxPoints; j++){
                for(int j0=0; j0+j<=k; j0++){
                    dp[i][j+j0] = min({dp[i][j+j0], dp[i-1][j+j0], dp[i-1][j0]+cost});
                }
                cost += min(w,h);
                if(w<h){
                    h--;
                }else{
                    w--;
                }
            }
        }
        cout << (dp[n][k] == 0x3f3f3f3f ? -1 : dp[n][k]) << endl;
    }
}