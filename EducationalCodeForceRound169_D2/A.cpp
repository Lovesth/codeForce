#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums)
            cin >> num;
        if(n>2){
            cout << "NO" << endl;
            continue;
        }
        if(abs(nums[0]-nums[1])>1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}