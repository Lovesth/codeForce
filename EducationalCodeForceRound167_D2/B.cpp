#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> data(3, vector<int>(n+1));
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin >> data[i][j];
            }
        }
        vector<int> rec{};
        int res1{}, res2{};
        for(int i=1; i<=n; i++){
            if(data[1][i]>data[2][i]){
                res1 += data[1][i];
            }
            if(data[2][i]>data[1][i]){
                res2 += data[2][i];
            }
            if(data[1][i]==data[2][i])
                rec.push_back(i);
        }
        for(auto idx : rec){
            if(data[1][idx]==0)
                continue;
            if(data[1][idx]==-1){
                if(res1<res2){
                    res2--;
                }else{
                    res1--;
                }
            }
            if(data[1][idx]==1){
                if(res1<res2){
                    res1++;
                }else{
                    res2++;
                }
            }
        }
        cout << min(res1,res2) << endl;
    }
}