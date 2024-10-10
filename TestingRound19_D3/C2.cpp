#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t1;
    cin >> t1;
    string_view t{t1};
    int n = t.size();
    int ul = (n + 1) / 2;
    auto solve = [&]()
    {
        int left = n / 2, right = n / 2;
        if (n % 2)
        {
            left = right = n / 2;
        }
        else
        {
            left = n / 2 - 1;
            right = n / 2;
        }
        vector<int> recordLeft(26);
        vector<int> recordMiddle(26);
        vector<int> recordRight(26);
        vector<int> record1(26);
        vector<int> record2(26);
        for (int i = left; i <= right; i++)
        {
            recordMiddle[t[i] - 'a']++;
        }
        for (int i = 0; i <= right - left; i++)
        {
            recordLeft[t[i] - 'a']++;
        }
        for (int i = n - (right - left + 1); i <= n - 1; i++)
        {
            recordRight[t[i] - 'a']++;
        }
        for (int i = right - left + 1; i < left; i++)
        {
            record1[t[i] - 'a']++;
        }
        for (int i = right + 1; i < n - (right - left + 1); i++)
        {
            record2[t[i] - 'a']++;
        }
        for (; left > 0; left--, right++)
        {
            if (recordLeft == recordMiddle && recordLeft == recordRight && record1 == record2)
            {
                if (t.substr(0, right + 1) == t.substr(left, right + 1))
                {
                    cout << "YES" << endl
                         << t.substr(0, right + 1) << endl;
                    break;
                }
            }
            recordLeft[t[right - left + 1] - 'a']++;
            recordLeft[t[right - left + 2] - 'a']++;
            recordRight[t[n - (right - left + 1) - 1] - 'a']++;
            recordRight[t[n - (right - left + 1) - 2] - 'a']++;
            recordMiddle[t[left - 1] - 'a']++;
            recordMiddle[t[right + 1] - 'a']++;
            if (record1[t[left - 1] - 'a'])
                record1[t[left - 1] - 'a']--;
            if (record1[t[right - left + 1] - 'a'])
                record1[t[right - left + 1] - 'a']--;
            if (record1[t[right - left + 2] - 'a'])
                record1[t[right - left + 2] - 'a']--;
            if (record2[t[right + 1] - 'a'])
                record2[t[right + 1] - 'a']--;
            if (record2[t[n - (right - left + 1) - 1] - 'a'])
                record2[t[n - (right - left + 1) - 1] - 'a']--;
            if (record2[t[n - (right - left + 1) - 2] - 'a'])
                record2[t[n - (right - left + 1) - 2] - 'a']--;
        }
        if (left <= 0)
            cout << "NO" << endl;
    };
    solve();
}