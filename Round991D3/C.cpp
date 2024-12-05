#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int sum_ = 0;
        vector<int> rec(10);
        for (auto c : s)
        {
            sum_ += c - '0';
            rec[c - '0']++;
        }

        sum_ = sum_ % 9;
        if (sum_ == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            // 2->4, 3->9
            int target = 9 - sum_;
            int tmp;
            bool flag = false;
            for (int i = 0; i <= rec[2]; i++)
            {
                for (int j = 0; j <= rec[3]; j++)
                {
                    tmp = (2 * i + 6 * j) % 9;
                    if (tmp == target)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (tmp == target)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}