#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_valid_k(const vector<ll> &a, ll k)
{
    int n = a.size();
    int odd_clusters = 0;
    int i = 0;
    while (i < n)
    {
        int cluster_size = 1;
        int j = i;
        while (j + 1 < n && a[j + 1] - a[j] <= k)
        {
            j++;
            cluster_size++;
        }
        if (cluster_size % 2 == 1)
        {
            odd_clusters++;
        }
        if (odd_clusters > 1)
        {
            return false;
        }
        i = j + 1;
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll low = 1;
        ll high = 1e18;
        ll answer = -1;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (is_valid_k(a, mid))
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << answer << endl;
    }
}