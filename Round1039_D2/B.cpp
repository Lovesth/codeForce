#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums) {
            cin >> num;
        }

        for(int i=0; i<n/2; i++) {
            int num1 = nums[i];
            int num2 = nums[n-1-i];
            if(i&1) {
                cout << (num1 > num2 ? "RL" : "LR");
            }else{
                cout << (num1 > num2 ? "LR" : "RL");
            }
        }

        if(n&1) {
            cout << "L";
        }
        cout << endl;
    }
}