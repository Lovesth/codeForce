#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 2; i <= n / 2; i++)
        {
            if (nums[i] == nums[n - i + 1])
                continue;
            if (nums[i] == nums[i - 1] || nums[n - i + 1] == nums[n - i + 2])
            {
                swap(nums[i], nums[n - i + 1]);
            }
        }
        int res = 0;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i+1])
                res++;
        }
        cout << res << endl;
    }
}