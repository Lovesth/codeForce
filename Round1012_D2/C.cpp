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

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<pair<int, int>, vector<int>> rec{};
        vector<pair<int, int>> res(n);
        pair<int, int> curTable4Zero{0, 0};
        int c;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == 0 || rec.empty())
            {
                int x = curTable4Zero.first;
                int y = curTable4Zero.second;
                rec[curTable4Zero].push_back(0);
                res[i].first = 3 * x + 1;
                res[i].second = 3 * y + 1;
                curTable4Zero = getNext(curTable4Zero);
            }
            else
            {
                auto &[k, v] = *rec.begin();
                int tmp = v.size();
                int x = k.first;
                int y = k.second;
                if (tmp == 0)
                {
                    res[i].first = 3 * x + 1;
                    res[i].second = 3 * y + 1;
                    v.push_back(0);
                }
                else if (tmp == 1)
                {
                    res[i].first = 3 * x + 1;
                    res[i].second = 3 * y + 2;
                    v.push_back(1);
                }
                else if (tmp == 2)
                {
                    res[i].first = 3 * x + 2;
                    res[i].second = 3 * y + 1;
                    v.push_back(2);
                }
                else
                {
                    // TODO ?
                    if ((y == 0) && rec.count(getNext(k)) && rec[getNext(k)].size() <= 1)
                    {
                        int cnt = rec[getNext(k)].size();
                        auto [x1, y1] = getNext(k);
                        res[i].first = 3 * x1 + 1;
                        res[i].second = 3 * y1 + 2;
                        rec[getNext(k)].push_back(cnt);
                    }
                    else if (k.second == 0 && isNext(k, curTable4Zero))
                    {
                        int x = curTable4Zero.first;
                        int y = curTable4Zero.second;
                        rec[curTable4Zero].push_back(0);
                        res[i].first = 3 * x + 1;
                        res[i].second = 3 * y + 1;
                        curTable4Zero = getNext(curTable4Zero);
                    }
                    else
                    {
                        res[i].first = 3 * x + 2;
                        res[i].second = 3 * y + 2;
                        v.push_back(3);
                        // if (v.size() == 4)
                        rec.erase(rec.begin());
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
}