#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int tmp;
        map<int, int> rec{};
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            rec[tmp]++;
        }
        if(rec.size() <= 1){
            cout << 1 << endl;
            continue;
        }
        vector<int> freq{};
        for (auto &[k, v] : rec)
        {
            freq.push_back(v);
        }
        sort(freq.begin(), freq.end());
        int idx = 0;
        for (; idx < freq.size() && k;)
        {
            if (k >= freq[idx])
            {
                k -= freq[idx];
                freq.back() += freq[idx];
                idx++;
            }
            else
            {
                break;
            }
        }
        cout << freq.size() - idx << endl;
    }
}