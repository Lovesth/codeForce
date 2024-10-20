#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s(n-1, '0');
        s += string(1, '1');
        cout << s << endl;
    }
     
}