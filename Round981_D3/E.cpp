#include <bits/stdc++.h>
using namespace std;

consteval auto mySqrt(int x){
    return sqrt(x);
}

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
        vector<int> vis(n + 1);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                for (int j = i;; j = nums[j])
                {
                    cnt++;
                    vis[j] = 1;
                    if (nums[j] == i)
                        break;
                }
                res += (cnt - 1) / 2;
            }
        }
        cout << res << endl;
    }
}