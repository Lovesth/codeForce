#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> nums(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i][0] >> nums[i][1];
        }
        sort(nums.begin(), nums.end(), [](auto &num1, auto &num2) -> bool
             {
            int min1 = min(num1[0],num1[1]);
            int max1 = max(num1[0],num1[1]);
            int min2 = min(num2[0],num2[1]);
            int max2 = max(num2[0],num2[1]);
            return vector<int>{{min1,max1}} < vector<int>{{min2,max2}}; });
        for (auto &num : nums)
        {
            cout << num[0] << " " << num[1] << " ";
        }
        cout << endl;
    }
}