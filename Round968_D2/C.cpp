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
        sort(s.begin(), s.end());
        string s1(n, ' ');
        int j=0;
        for (int i = 0; i < n; i += 2, j++)
        {
            s1[i] = s[j];
        }
        for(int i=n-1; i>=0; i--){
            if(s1[i] != ' ')
                continue;
            s1[i] = s[j];
            j++;
        }
        cout << s1 << endl;
    }
}