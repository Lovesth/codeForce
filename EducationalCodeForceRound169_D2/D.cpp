#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &cities, vector<int> &q, unordered_map<string, set<int>> &record)
{
    string s1 = cities[q[0]];
    string s2 = cities[q[1]];
    if (s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1])
    {
        cout << abs(q[1] - q[0]) << endl;
        return;
    }
    unordered_set<string> potential;
    potential.insert(s1.substr(0, 1) + s2.substr(0, 1));
    potential.insert(s1.substr(0, 1) + s2.substr(1, 1));
    potential.insert(s1.substr(1, 1) + s2.substr(0, 1));
    potential.insert(s1.substr(1, 1) + s2.substr(1, 1));

    potential.insert(s2.substr(0, 1) + s1.substr(0, 1));
    potential.insert(s2.substr(0, 1) + s1.substr(1, 1));
    potential.insert(s2.substr(1, 1) + s1.substr(0, 1));
    potential.insert(s2.substr(1, 1) + s1.substr(1, 1));
    int res = 0x3f3f3f3f;
    for (auto &s : potential)
    {
        auto &r = record[s];
        if(r.empty())
            continue;
        auto it = r.lower_bound(q[0]);
        if(it!=r.end()){
            res = min(res,abs(*it-q[0])+abs(q[1]-*it));
        }
        if(it!=r.begin()){
            it--;
            res = min(res,abs(*it-q[0])+abs(q[1]-*it));
        }
    }
    cout << (res==0x3f3f3f3f ? -1 : res) << endl;
}

int main()
{
    int t, q, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<string> cities(n + 1);
        vector<vector<int>> queries(q + 1, vector<int>(2));
        unordered_map<string, set<int>> record;
        for (int i = 1; i <= n; i++)
        {
            cin >> cities[i];
            record[cities[i]].insert(i);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> queries[i][0] >> queries[i][1];
        }
        for (int i=1; i<=q; i++)
                solve(cities, queries[i], record);
    }
}