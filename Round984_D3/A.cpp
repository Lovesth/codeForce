#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> nums(n);
        for (auto &num : nums)
        {
            cin >> num;
        }
        for (int i = 1; i < n; i++)
        {
            int tmp = abs(nums[i] - nums[i - 1]);
            if (tmp != 5 && tmp != 7)
            {
                cout << "NO" << endl;
                break;
            }
            if (i == n - 1)
                cout << "YES" << endl;
        }
    }
}