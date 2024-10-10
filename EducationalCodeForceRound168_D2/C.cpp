#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        int res = 0;
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || s[i]=='(')
            {
                st.push({s[i], i});
                continue;
            }
            auto it = st.top();
            if(s[i]==')'){
                res += i-it.second;
                st.pop();
                continue;
            }
            if(it.first==')'){
                st.push({s[i],i});
                continue;
            }else{
                res += i-it.second;
                st.pop();
            }
        }
        cout << res << endl;
    }
}