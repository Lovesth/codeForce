#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll res = 0;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = n; i >= 1; i -= 2)
        {
            int tmp1, tmp2;
            tmp1 = nums[i];
            if (i == 1)
            {
                res += tmp1;
                break;
            }
            tmp2 = nums[i - 1];
            int diff = tmp1 - tmp2;
            if (k >= diff)
            {
                k -= diff;
                continue;
            }
            res += diff - k;
            k = 0;
        }
        // if(t<=10)
        cout << res << endl;
        // if(t<=4704-435 && t>=100){
        //     cout << "---------------------" << endl;
        //     cout << n << " " << k << endl;
        //     for(int i=1; i<=n; i++){
        //         cout << nums[i] << " ";
        //     }
        //     cout << endl;
        //     cout << res << endl;
        //     cout << "---------------------" << endl;
        // }
    }
}