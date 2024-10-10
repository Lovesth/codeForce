#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n, m, q;
    cin >> t;
    while(t--){
        cin >> n >> m >> q;
        vector<int> ms(m);
        unordered_map<int,int> ns(n);
        int tmp;
        for(int i=1; i<=n; i++){
            cin >> ns[i-1];
        }
        for(int j=1; j<=m; j++){
            cin >> ms[j-1];
        }
        ms.erase(unique(ms.begin(), ms.end()), ms.end());
        m = ms.size();
        unordered_map<int,int> recm;
        for(int j=1; j<=m; j++){
            recm[ms[j]] = j;
        }
        bool flag = true;
        for(int k=0; k<m; k++){
            int cPeople = ms[k];
            if(ns[0]!=cPeople){
                flag = false;
                break;
            }else{
                if(recm.count(cPeople)>1){
                    
                }
            }
            recm[cPeople]--;
        }
    }
}