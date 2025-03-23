#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> grids(n);
        for(auto& s : grids){
            cin >> s;
        }
        
        bool yes{true};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grids[i][j] == '1'){
                    bool flag{true};
                    for(int k=i-1; k>=0; --k){
                        if(grids[k][j] == '0'){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        continue;;
                    flag = true;
                    for(int k=j-1; k>=0; --k){
                        if(grids[i][k] == '0'){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        yes = false;
                        break;
                    }
                }
            }
            if(!yes)
                break;
        }
        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}