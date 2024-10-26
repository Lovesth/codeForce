#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n+1);
        for(int i=1; i<=n; i++){
            cin >> nums[i];
        }
        int res = INT_MAX;
        for(int i=n; i>=1; i--){
            int cnt = 0;
            for(int j=n; j>i; j--){
                if(nums[j]>nums[i])
                    cnt++;
            }
            res = min(res,cnt+i-1);
        }
        cout << res << endl;
    }
}