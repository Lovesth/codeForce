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
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '_')
            {
                s[i] = st.empty() ? '(' : ')';
            }
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                res += i-st.top();
                st.pop();
            }
        }
        cout << res << endl;
    }
}