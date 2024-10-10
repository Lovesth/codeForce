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
        if(n%2 == 0){
            cout << n/2+*max_element(nums.begin(), nums.end()) << endl;
        }else{
            int resOdd = 0, resEven = 0;
            int maxValOdd = 0, maxValEven = 0;
            for(int i=1; i<=n; i++){
                if(i&1){
                    maxValOdd = max(maxValOdd,nums[i]);
                }else{
                    maxValEven = max(maxValEven, nums[i]);
                }
            }
            cout << max(maxValOdd+n/2+1, maxValEven+n/2) << endl;
        }
    }
}