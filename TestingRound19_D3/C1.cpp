#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t;
    cin >> t;
    int n = t.size();
    int ul = (n + 1) / 2;
    auto solve = [&]()
    {
        char c = t[0];
        for (int l = 1; l < ul; l++)
        {
            if(t[l]==c){
                string t1 = t.substr(l, n-l);
                string t2 = t.substr(0, n-l);
                if(t1 == t2){
                    cout << "YES" << endl << t1 << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    };
    solve();
}