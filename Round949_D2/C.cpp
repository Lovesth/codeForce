#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;

vector<int> findPath(int s, int e){
    vector<int> L, R;
    while (__lg(s)>__lg(e)) {
        L.push_back(s);
        s >>= 1;
    }
    while (__lg(e)>__lg(s)) {
        R.push_back(e);
        e >>= 1;
    }
    while (s!=e) {
        L.push_back(s);
        R.push_back(e);
        s >>= 1;
        e >>= 1;
    }
    L.push_back(s);
    for(auto it=R.rbegin(); it!=R.rend(); it++){
        L.push_back(*it);
    }
    return L;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> vec;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]!=-1)
                vec.push_back(i);
        }
        if(vec.size()==0){
            for(int i=0; i<n; i++){
                cout << (i&1)+1 << " ";
            }
            cout << endl;
            continue;
        }
        int l=vec[0], r=vec[vec.size()-1];
        for(int i=l-1; i>=0; i--){
            a[i] = a[i+1]>=2?a[i+1]/2:a[i+1]*2;
        }
        for(int i=r+1; i<a.size(); i++){
            a[i] = a[i-1]>=2?a[i-1]/2:a[i-1]*2;
        }
        bool flag = true;
        for(int i=0; i<vec.size()-1; i++){
            int l = vec[i];
            int r = vec[i+1];
            auto path = findPath(a[l], a[r]);
            int len1 = path.size();
            int len2 = r-l+1;
            if(len1>len2 || (len1%2 ^ len2%2)){
                flag = false;
                break;
            }
            for(int j=0; j<path.size(); j++){
                a[l+j] = path[j];
            }
            for(int j=l+len1, cnt=1; j<=r; j++, cnt++){
                a[j] = cnt&1 ? a[j-1]*2 : a[j-1]/2;
            }
        }
        if(flag){
            for(auto&e : a)
                cout << e << " ";
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
}