#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a & 1)
        {
            cout << "NO" << endl;
        }
        else if(a==0){
            cout << (b%2==0 ? "YES" : "NO") << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}