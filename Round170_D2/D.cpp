#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, INT_MIN);
    dp[0] = 0;
    vector<int> rec(m + 2);
    int pos = 0;
    int a, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a > 0)
        {
            rec[a]++;
            rec[m + 1]--;
        }
        else if (a < 0)
        {
            if (cnt + a >= 0)
            {
                rec[0]++;
                rec[cnt + a + 1]--;
            }
        }
        else
        {
            int tmp = 0;
            for (int i = 0; i <= m; i++)
            {
                tmp += rec[i];
                dp[i] += tmp;
                rec[i] = 0;
            }
            for (int i = m; i > 0; i--)
            {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            cnt++;
        }
    }
    int tmp = 0;
    for (int i = 0; i <= m; i++)
    {
        tmp += rec[i];
        dp[i] += tmp;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}