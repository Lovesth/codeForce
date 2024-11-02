
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (auto &num : a)
        {
            cin >> num;
        }
        ranges::sort(a);
        int l = 0, r = 1;
        int ans = INT_MAX;
        for(r=1; r<n; r++){
            while(r-l>1 && a[l]+a[l+1]<=a[r])
                l++;
            ans = min(ans, n-(r-l+1));
        }
        cout << ans << endl;
    }
}