#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> res(n);
        while(n--){
            cin >> s;
            res[n] = s.find('#')+1;
        }
        for(auto& r : res){
            cout << r << " ";
        }
        cout << endl;
    }
}