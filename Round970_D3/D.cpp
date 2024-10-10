#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &memo, vector<int> &nums, string &s, int num)
{
    if (memo[num] != -1)
    {
        cout << memo[num] << " ";
        return;
    }
    int res = 0;
    unordered_set<int> path;
    int cur = num;
    while (path.count(cur) == 0)
    {
        if(s[cur-1]=='0')
            res++;
        path.insert(cur);
        cur = nums[cur];
    }
    for(auto& p : path){
        memo[p] = res;
    }
    cout << res << " ";
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        cin >> s;
        vector<int> memo(n + 1, -1);
        for (int cur = 1; cur <= n; cur++)
        {
            solve(memo, nums, s, cur);
        }
        cout << endl;
    }
}