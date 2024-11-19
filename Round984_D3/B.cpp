#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, b, c;
    cin >> t;
    while (t--)
    {
        map<int, int> rec{};
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> b >> c;
            rec[b] += c;
        }
        priority_queue<int, vector<int>, less<int>> pq{};
        for (auto it = rec.begin(); it != rec.end(); it++)
        {
            pq.push(it->second);
        }
        int i = 0, ret = 0;
        for (; i < n && !pq.empty(); i++)
        {
            ret += pq.top();
            pq.pop();
        }
        cout << ret << endl;
    }
}