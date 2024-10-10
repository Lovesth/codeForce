#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if(n&1 && ((k+1)/2)%2==0){
            cout << "YES" << endl;
        }else if((n&1)==0 && (k/2)%2==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}