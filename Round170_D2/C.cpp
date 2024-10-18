#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        map<int, int> rec;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            rec[a]++;
        }
        int res = 0;
        for (auto it = rec.begin(); it != rec.end();)
        {
            auto preIt = it;
            auto nextIt = next(preIt);
            vector<int> tmp{preIt->second};
            for (; nextIt != rec.end();)
            {
                if (nextIt->first == preIt->first + 1)
                {
                    tmp.push_back(nextIt->second);
                    preIt = nextIt++;
                }
                else
                {
                    break;
                }
            }
            it = nextIt;
            int l = 0, r = 0, ret = 0;
            for (; r < tmp.size(); r++)
            {
                ret += tmp[r];
                while(r-l+1>k){
                    ret -= tmp[l++];
                }
                res = max(res,ret);
            }
        }
        cout << res << endl;
    }
}