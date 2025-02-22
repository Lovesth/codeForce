#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int num;
        map<int, int> rec{};

        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            rec[num]++;
        }
        while (rec.size() > 1)
        {
            auto [k, v] = *rec.begin();
            if (v <= 1)
            {
                break;
            }
            rec.erase(rec.begin());
            if (v > 2)
                rec[k + 1] += v - 2;
        }
        auto [k, v] = *rec.begin();
        if (v & 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}