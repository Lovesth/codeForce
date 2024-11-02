#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        int tmp, maxVal = 0;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            pq.push(tmp);
            maxVal = max(maxVal, tmp);
        }
        int res = 0;
        while(1){
            int tmp1 = pq.top();
            pq.pop();
            if(tmp1+pq.top()<=maxVal){
                res++;
                pq.push(maxVal);
            }else{
                break;
            }
        }
        cout << res << endl;
    }
}