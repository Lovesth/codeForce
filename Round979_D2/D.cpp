#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<int> nums(n + 1);
        vector<int> rec(n + 1);
        int queries;
        string s;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            rec[min(i, nums[i])]++;
            rec[max(i, nums[i])]--;
        }
        partial_sum(rec.begin() + 1, rec.end(), rec.begin() + 1);
        unordered_set<int> us;
        cin >> s;
        s.insert(s.begin(), ' ');
        for (int i = 1; i < n; i++)
        {
            if (rec[i] && s[i] == 'L' && s[i + 1] == 'R')
                us.insert(i);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> queries;
            if (s[queries] == 'R')
            {
                s[queries] = 'L';
            }
            else
            {
                s[queries] = 'R';
            }
            if (queries > 1 && rec[queries - 1])
            {
                if (s[queries - 1] == 'L' && s[queries] == 'R')
                    us.insert(queries - 1);
                else
                    us.erase(queries - 1);
            }
            if (queries < n && rec[queries])
            {
                if (s[queries] == 'L' && s[queries + 1] == 'R')
                    us.insert(queries);
                else
                    us.erase(queries);
            }
            if (us.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
