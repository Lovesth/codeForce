#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n, d, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> d >> k;
        vector<ll> lData(n + 1);
        vector<ll> rData(n + 1);
        ll l, r;
        for (int i = 1; i <= k; i++)
        {
            cin >> l >> r;
            lData[l]++;
            rData[r]++;
        }
        partial_sum(lData.begin(), lData.end(), lData.begin());
        partial_sum(rData.begin(), rData.end(), rData.begin());
        ll maxVal = 0;
        ll minVal = LLONG_MAX;
        ll b = 0, m = 0;
        for(int pos=1; pos<=n-d+1; pos++){
            ll tmp = lData[pos+d-1]-rData[pos-1];
            if(tmp>maxVal){
                maxVal = tmp;
                b = pos;
            }
            if(tmp<minVal){
                minVal = tmp;
                m = pos;
            }
        }
        cout << b << " " << m << endl;
    }
}