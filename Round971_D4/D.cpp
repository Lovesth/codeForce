#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, x, y;
    cin >> t;
    while(t--){
        cin >> n;
        vector<unordered_set<int>> points(2);
        for(int i=0; i<n; i++){
            cin >> x >> y;
            points[y].insert(x);
        }
        ll res = 0;
        int len0 = points[0].size();
        int len1 = points[1].size();
        for(auto& num : points[0]){
            if(points[1].count(num)){
                res += len0+len1-2;
            }
            if(points[1].count(num-1) && points[1].count(num+1)){
                res += 1;
            }
        }
        for(auto& num : points[1]){
            if(points[0].count(num-1) && points[0].count(num+1)){
                res += 1;
            }
        }
        cout << res << endl;
    }
}