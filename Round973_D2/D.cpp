#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using df = double;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        stack<pair<ll,ll>> st;
        ll s, cnt;
        for(int i=1; i<=n; i++){
            cin >> s;
            cnt = 1;
            while(!st.empty() && st.top().first>=s/cnt){
                s += st.top().first * st.top().second;
                cnt += st.top().second;
                st.pop();
            }
            st.push({s/cnt, cnt-s%cnt});
            if(s%cnt){
                st.push({s/cnt+1, s%cnt});
            }
        }
        ll mx = st.top().first;
        while(st.size()>1){
            st.pop();
        }
        ll mi = st.top().first;
        cout << mx-mi << endl;
    }
}