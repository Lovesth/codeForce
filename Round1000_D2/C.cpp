#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, vector<int>> edges{};
        int e1, e2;
        for(int i=0; i<n-1; ++i){
            cin >> e1 >> e2;
            edges[e1].push_back(e2);
            edges[e2].push_back(e1);
        }

        
    }
    
}