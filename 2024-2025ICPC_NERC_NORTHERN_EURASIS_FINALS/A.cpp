#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> order(n + 1);
    vector<int> originOrder(n + 1);
    set<pair<int, int>> rec{};
    vector<pair<int, int>> res{};
    vector<int> rec1(n + 1);
    iota(originOrder.begin(), originOrder.end(), 0);
    iota(rec1.begin(), rec1.end(), 0);
    for (int i = 1; i <= n; i++)
        cin >> order[i];

    for (int i = 1; i <= n; i++)
    {
        int curNum = order[i];
        int curPos = rec1[i];
        if (curPos == i)
        {
            
        }
    }
}