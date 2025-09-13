#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> nums(n);

        for (auto &num : nums)
        {
            cin >> num;
        }

        ll minOdd = LLONG_MAX / 2;
        ll minEven = LLONG_MAX / 2;
        ll res{0};
        ll add = (n&1 ? n-1 : n-2);
        for(int i=0; i<n; i++) {
            if(i&1) {
                res -= nums[i];
                add = max(add, i+2LL*nums[i]-minEven);
                minOdd = min(minOdd, i-2LL*nums[i]);
            }else{
                res += nums[i];
                add = max(add, i-2LL*nums[i]-minOdd);
                minEven = min(minEven, i+2LL*nums[i]);
            }
        }

        res += add;
        cout << res << endl;
    }
}