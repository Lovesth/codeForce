#include <bits/stdc++.h>
using namespace std;

bool isNext(const pair<int, int> &t1, const pair<int, int> &t2)
{
    if (t1.second == 0)
    {
        return t2.first == 0 && t2.second == t1.first + 1;
    }
    return t2.first == t1.first + 1 && t2.second == t1.second - 1;
}

auto getNext(const pair<int, int> &t1)
{
    if (t1.second == 0)
    {
        return make_pair(0, t1.first + 1);
    }
    return make_pair(t1.first + 1, t1.second - 1);
}

struct Comp
{
    bool operator()(const pair<int, int> &t1, const pair<int, int> &t2) const
    {
        auto &[x1, y1] = t1;
        auto &[x2, y2] = t2;
        if (x1 + y1 < x2 + y2)
        {
            return true;
        }
        else if (x1 + y1 > x2 + y2)
        {
            return false;
        }
        if (x1 < x2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        pair<int, int> curTable4Zero{0, 0};
        set<pair<int, int>, Comp> rec{};
        for (int i = 0; i < n; i++)
        {
            int x = curTable4Zero.first;
            int y = curTable4Zero.second;
            rec.emplace(3 * x, 3 * y + 1);
            rec.emplace(3 * x, 3 * y + 2);
            rec.emplace(3 * x + 2, 3 * y);
            rec.emplace(3 * x + 2, 3 * y + 3);
            curTable4Zero = getNext(curTable4Zero);
        }
        int c;
        curTable4Zero = {0, 0};
        vector<pair<int, int>> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == 0)
            {
                res[i].first = 3 * curTable4Zero.first + 1;
                res[i].second = 3 * curTable4Zero.second + 1;
                curTable4Zero = getNext(curTable4Zero);
                rec.erase(res[i]);
            }
            else
            {
                auto [x, y] = *rec.begin();
                res[i].first = x;
                res[i].second = y;
                rec.erase(rec.begin());
            }
        }
        for (auto &[x, y] : res)
            cout << x << " " << y << " " << endl;
    }
}