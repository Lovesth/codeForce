#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> rec(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> rec[i][j];
            }
        }
        map<int,int> rec1{};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int color = rec[i][j];
                if((i+1) < n && color == rec[i+1][j])
                    rec1[color] = 2;
                if((j+1) < m && color == rec[i][j+1])
                    rec1[color] = 2;
                rec1[color] = max(rec1[color], 1); 
            }
        }
        int maxCnt = 0;
        int totalCnt = 0;
        for(auto[_,v] : rec1){
            totalCnt += v;
            maxCnt = max(maxCnt, v);
        }
        cout << totalCnt-maxCnt << endl;
    }
}