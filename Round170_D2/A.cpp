#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    string s, t;
    cin >> q;
    while (q--)
    {
        cin >> s >> t;
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size() && s[i] == t[j]; i++, j++);
        cout << i+(s.size()-i)+(t.size()-i)+(i!=0) << endl;
    }
}